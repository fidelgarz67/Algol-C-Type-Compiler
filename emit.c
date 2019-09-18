/* 
Programmer: Fidel Garcia
Date: May 2. 2019
Details: an Emit c file that will priduce asm code.
*/

#include <stdio.h>
//#include<malloc/malloc.h>
#include <malloc.h>
#include <string.h>
#include "ast.h"
#include "emit.h"
#include <math.h>
#include <stdlib.h>

#define wordSize 8
int LTEMP = 0;

//creating a label function
//post - generate a label for any label needed
char *label(){
   char cap[100];
   char *s;
   sprintf(cap, "_L%d", LTEMP++);
   s = strdup(cap);
   return (s);
}//end of label

//pre - ast node of a VarDec
//post - print out variable that are global
void emitGlobal(ASTnode *p){
   //error checking 
   if(p == NULL)
      return;
   //Is it a variable w/ level 0?
   if((p ->type == VarDec) && (p ->symbol ->level == 0)){
          if(p ->value != 0){
            fprintf(fp, "\tcommon %s %d \t\t ;defined global variable\n", p ->name, (p ->value * wordSize));
        } else{
            fprintf(fp, "\tcommon %s %d \t\t ;defined global variable\n", p ->name, wordSize);
        }//end of else
   }//end of main if
   //recursively go to the next variables
   emitGlobal(p ->s1);
   emitGlobal(p ->s2);
   emitGlobal(p ->next);
}//end of emitGlobal

//pre - AST NODE write statement
//post - added strings to the data section of the asm file
void emitString(ASTnode *p){
    //error checking
    if(p == NULL) return;
    
    if(p ->type == Write){
        if(p ->mytype == STRINGType){
            fprintf(fp, "%s: \t db %s, 0 \t\t ;global string\n", p ->label, p ->name);
        }
    }
    emitString(p ->s1);
    emitString(p ->s2);
    emitString(p ->next);
}//end of emitString

//pre - ast node of a FuncDec
//post - print out the SP and BP for the AR
//default asm code to create an AR for the start of the funtion
void emitStart(ASTnode *p){
   fprintf(fp, "%s: \n", p ->name);   //create a 'label' for the function
   if(strcmp(p ->name, "main") == 0){   //if the name is main create a SP and BP
      fprintf(fp, "\t mov rbp, rsp \t\t ;Create SP and BP for Main method\n");
   }
   //asm code for generating an AR 
   fprintf(fp, "\t mov r8, rsp \t\t ;Function header SP to be at most BP\n");
   fprintf(fp, "\t add r8, -%d, \t\t ;Get a chunk of mem. for the AR \n", p ->symbol ->offset * wordSize);
   fprintf(fp, "\t mov [r8], rbp \t\t ;Function header stores the old BP\n");
   fprintf(fp, "\t mov [r8+8], rsp \t\t ;Function header stores the old SP\n");
   fprintf(fp, "\t mov rsp, r8 \t\t ;Function header's new SP\n\n");
}//end of emitStart

//pre - function has already been printed in the asm file
//post - finish the AR with the approprite SP and BP values
//default asm code for ending an AR at the of a function
void emitEnd(){
   fprintf(fp, "\t mov rbp, [rsp] \t\t ;Function restores the offset\n");
   fprintf(fp, "\t mov rsp, [rsp+8] \t\t ;Function restores the SP\n");
   fprintf(fp, "\t mov rsp, rbp \t\t ;Sets the SP and offset to be the same\n");
   fprintf(fp, "\t xor rax, rax\n");
   fprintf(fp, "\t ret\n\n");
}//end of emitEnd

//pre - AST node of type variable
//post - [rax] will have the value of the Identifier
void emit_ident(ASTnode *p){
  if (p ->s1 != NULL){ 
    switch(p ->s1 -> type){

      //move the array value into a reg
      case Number:
         fprintf(fp, "\t mov rcx, %d \t\t ;Array Number\n", p ->s1 ->value);
         break;

      //mem. location of rax into a reg
      case Var:
         emit_ident(p ->s1);
         fprintf(fp, "\t mov rcx, [rax] \t\t ;Array Identifier\n");
         break;

      case Expression:
          emit_expr(p ->s1);
          fprintf(fp, "\t mov rcx, [rsp + %d] \t\t ;Writing and Expression\n", (p ->s1 ->symbol ->offset) * wordSize);
         break;

      case Call:
         break;

      default:printf("Error\n"); 
      exit(1);      
    }//end of switch

  //shift the offset  
  int logW = (int) (log10(wordSize)/log10(2));
     fprintf(fp, "\t shl rcx, %d \t\t ;Shift the offset << %d\n", logW, logW);
  }//end of if

  
  if (((p ->type) == Var) && ((p ->symbol ->level) == 0)) {
        fprintf(fp,"\t mov rax, %s \t\t ;Move variable name into rax\n", p ->name);
    }else {
       fprintf(fp,"\t mov rax, %d \t\t ;Move variable value into rax\n", ((p ->symbol ->offset) * wordSize));
       fprintf(fp,"\t add rax, rsp \t\t ;Add SP to rax\n");
    }

    if (p ->s1 != NULL) {
       fprintf(fp, "\t add rax, rcx \t\t ;Add array internal offset\n\n");
    } 
}//end of emit_ident

//pre - ASTnode of an expression statement
//post - [rax] will have the value of the expression
//start of emit_expr
void emit_expr (ASTnode *p){
    if (p == NULL) return;
    
    //left hand side of the expression
    switch(p ->s1 -> type){

      //move the array value into a reg
        case Number:
         fprintf(fp, "\t mov rax, %d \t\t ;Array Number\n", p ->s1 ->value);
         break;

      //mem. location of rax into a reg
      case Var:
         emit_ident(p ->s1);
         fprintf(fp, "\t mov rax, [rax] \t\t ;Array Identifier\n");
         break;

      case Expression:
          emit_expr(p ->s1);
          fprintf(fp, "\t mov rax, [rsp + %d] \t\t ;Writing and Expression\n", (p ->s1 ->symbol ->offset) * wordSize);
         break;

      case Call:
         break;

      default:printf("Error\n"); 
      exit(1);      
    }//end of switch
    
    //store
    fprintf(fp, "\t mov [rsp + %d], rax \t\t ;Move rax into SP + offset\n", (p ->symbol ->offset) * wordSize);
    
    //right hand side
    if(p ->s2 != NULL){
        switch(p ->s2 ->type){

      //move the array value into a reg
      case Number:
         fprintf(fp, "\t mov rbx, %d \t\t ;Array Number\n", p ->s2 ->value);
         break;

      //mem. location of rax into a reg
      case Var:
         emit_ident(p ->s2);
         fprintf(fp, "\t mov rbx, [rax] \t\t ;Array Identifier\n");
         break;

      case Expression:
          emit_expr(p ->s2);
          fprintf(fp, "\t mov rbx, [rsp + %d] \t\t ;Writing and Expression\n", (p ->s2 ->symbol ->offset) * wordSize);
         break;

      case Call:
         break;

      default:printf("Error\n"); 
      exit(1);      
    }//end of switch
    }
    //store
    fprintf(fp, "\t mov rax, [rsp + %d] \t\t ;Move the SP + offset into rax\n", (p ->symbol ->offset) * wordSize);
    
    //find out what the operator is
    switch(p ->myOperator){
        case MyNot:
            fprintf(fp, "\t cmp rax, 0 \t\t ;Compare rax with 0\n");
            fprintf(fp, "\t sete al \t\t ;Set al to be equal\n");
            fprintf(fp, "\t mov rdx, 1 \t\t ;Move 1 into rdx\n");
            fprintf(fp, "\t and rax, rdx \t\t ;Add both rax and rdx\n");
           break;
           
        case MyAND:
            //eval. the LHS
            fprintf(fp, "\t cmp rax, 0 \t\t ;Compare rax with 0\n");
            fprintf(fp, "\t setne al \t\t ;Set al to not be equal\n");
            fprintf(fp, "\t mov rdx, 1 \t\t ;Move one into rdx\n");
            fprintf(fp, "\t and rax, rdx \t\t ;Add both rax and rdx\n");
            
            //eval. the RHS
            fprintf(fp, "\t cmp rbx, 0 \t\t ;Compare rbx with 0\n");
            fprintf(fp, "\t setne bl \t\t ;Set bl to not be equal\n");
            fprintf(fp, "\t mov rdx, 1 \t\t ;Move one into rdx\n");
            fprintf(fp, "\t and rbx, rdx \t\t ;Add both rbx and rdx\n");
            
            //add both values
            fprintf(fp, "\t and rax, rbx \t\t ;Add both rax and rbx\n");
           break;
           
        case MyOR:
            fprintf(fp, "\t or rax, rdx \t\t ;Or both rax and rbx\n");
            fprintf(fp, "\t mov rbx, 1 \t\t ;Move 1 into rbx \n");
            fprintf(fp, "\t and rax, rbx \t\t ;Add both rax and rbx\n");
           break;   
           
        case MyTimes:
            fprintf(fp, "\t imul rbx \t\t ; Multiplies rbx\n");   
           break;
           
        case MyDiv:
            fprintf(fp, "\t xor rdx, rdx \t\t ; Clears rdx\n"); //clears out rbx to be used
            fprintf(fp, "\t idiv rbx \t\t ; Multiplies rbx\n");   
           break;
           
        case MyPlus:
           fprintf(fp, "\t add rax, rbx \t\t ;Adding rbx and rax\n");
           break;
           
        case MyMinus:
           fprintf(fp, "\t sub rax, rbx \t\t ;Subtracting rbx and rax\n");
           break;
           
        case LessThenEQ:
            //compare both the LHS and RHS
            fprintf(fp, "\t cmp rax, rbx \t\t ;Compare rax and rbx\n");
            fprintf(fp, "\t setle al \t\t ;Set al less than or equal\n");
            fprintf(fp, "\t mov rbx, 1 \t\t ;Move 1 into rbx\n");
            fprintf(fp, "\t and rax, rbx \t\t ;Add both rax and rbx\n");
           break;
           
        case LessThen:
            //compare both the LHS and RHS
            fprintf(fp, "\t cmp rax, rbx \t\t ;Compare rax and rbx\n");
            fprintf(fp, "\t setl al \t\t ;Set al less than\n");
            fprintf(fp, "\t mov rbx, 1 \t\t ;Move 1 into rbx\n");
            fprintf(fp, "\t and rax, rbx \t\t ;Add both rax and rbx\n");
           break;
           
        case GreatThen:
            //compare both the LHS and RHS
            fprintf(fp, "\t cmp rax, rbx \t\t ;Compare rax and rbx\n");
            fprintf(fp, "\t setg al \t\t ;Set al greater than\n");
            fprintf(fp, "\t mov rbx, 1 \t\t ;Move 1 into rbx\n");
            fprintf(fp, "\t and rax, rbx \t\t ;Add both rax and rbx\n");
           break;
           
        case GreatThenEQ:
            //compare both the LHS and RHS
            fprintf(fp, "\t cmp rax, rbx \t\t ;Compare rax and rbx\n");
            fprintf(fp, "\t setge al \t\t ;Set al greater than or equal\n");
            fprintf(fp, "\t mov rbx, 1 \t\t ;Move 1 into rbx\n");
            fprintf(fp, "\t and rax, rbx \t\t ;Add both rax and rbx\n");
           break;
           
        case EqualTo:
            //compare both the LHS and RHS
            fprintf(fp, "\t cmp rax, rbx \t\t ;Compare rax and rbx\n");
            fprintf(fp, "\t sete al \t\t ;Set al equal\n");
            fprintf(fp, "\t mov rbx, 1 \t\t ;Move 1 into rbx\n");
            fprintf(fp, "\t and rax, rbx \t\t ;Add both rax and rbx\n");
            break;
            
        case NotEqualTo:
            //compare both the LHS and RHS
            fprintf(fp, "\t cmp rax, rbx \t\t ;Compare rax and rbx\n");
            fprintf(fp, "\t setne al \t\t ;Set al not equal\n");
            fprintf(fp, "\t mov rbx, 1 \t\t ;Move 1 into rbx\n");
            fprintf(fp, "\t and rax, rbx \t\t ;Add both rax and rbx\n");
          break;
    }
    fprintf(fp, "\t mov [rsp + %d], rax \t\t ;Move rax into SP +offset\n", (p ->symbol ->offset) * wordSize);
}//end of emit_expr

//pre - AST node of assignment statement
//post - [rax] will have the value of the assignment statement
//start of emit_ass
void emit_ass(ASTnode *p){
    //RHS of the assignment statement
    switch(p ->s2 ->type){

      //move the array value into a reg
      case Number:
         fprintf(fp, "\t mov rbx, %d \t\t ;Array Number\n", p ->s2 ->value);
         break;

      //mem. location of rax into a reg
      case Var:
         emit_ident(p ->s2);
         fprintf(fp, "\t mov rbx, [rax] \t\t ;Array Identifier\n");
         break;

      case Expression:
          emit_expr(p ->s2);
          fprintf(fp, "\t mov rbx, [rsp + %d] \t\t ;Writing and Expression\n", (p ->s2 ->symbol ->offset) * wordSize);
         break;

      case Call:
         break;

      default:printf("Error\n"); 
      exit(1);      
    }//end of switch
    //LHS of the ass
    emit_ident(p ->s1);
    
    fprintf(fp, "\t mov [rax], rbx \t\t ;Move rbx into mem. of rax (assign value)\n");
}//end of emit_ass

//pre - ASTnode of an if statement
//post - output the labels and overall design of an if statment in asm
//start of emit_if
void emit_if (ASTnode *p){
    char *label1 = label();
    char *label2 = label();
    
    switch(p ->s1 ->type){

      //move the array value into a reg
      case Number:
         fprintf(fp, "\t mov rax, %d \t\t ;Array Number\n", p ->s1 ->value);
         break;

      //mem. location of rax into a reg
      case Var:
         emit_ident(p ->s1);
         fprintf(fp, "\t mov rax, [rax] \t\t ;Array Identifier\n");
         break;

      case Expression:
          emit_expr(p ->s1);
          fprintf(fp, "\t mov rax, [rsp + %d] \t\t ;Writing and Expression\n", (p ->s1 ->symbol ->offset) * wordSize);
         break;

      case Call:
         break;

      default:printf("Error\n"); 
      exit(1);      
    }//end of switch
    
    //after getting the expression
    fprintf(fp, "\t cmp rax, 0 \t\t ;Compare the expression with 0\n");
    fprintf(fp, "\t je %s \t\t ;Jump to the first label\n", label1);
    emitAST(p ->s2 ->s1);
    
    if(p -> s2 ->s2 != NULL){
        fprintf(fp, "\t jmp %s \t\t ;Jump to the second label\n", label2);
    }
    fprintf(fp, "%s: \n", label1);
    if(p ->s2 ->s2 != NULL){
        emitAST(p ->s2 ->s2);
        fprintf(fp, "%s: \n", label2);
    }
    
}//end of emit_if

//pre - ASTnode of an iterative statement
//post - output the labels and overall design of an iterative statment in asm
void emit_while(ASTnode *p){
    char *label1 = label();
    char *label2 = label();
    
    if (p == NULL) return;
    
    fprintf(fp, "%s:\n", label1);
    
    switch(p ->s1 ->type){

      //move the array value into a reg
      case Number:
         fprintf(fp, "\t mov rax, %d \t\t ;Array Number\n", p ->s1 ->value);
         break;

      //mem. location of rax into a reg
      case Var:
         emit_ident(p ->s1);
         fprintf(fp, "\t mov rax, [rax] \t\t ;Array Identifier\n");
         break;

      case Expression:
          emit_expr(p ->s1);
          fprintf(fp, "\t mov rax, [rsp + %d] \t\t ;Writing and Expression\n", (p ->s1 ->symbol ->offset) * wordSize);
         break;

      case Call:
         break;

      default:printf("Error\n"); 
      exit(1);      
    }//end of switch
    
    fprintf(fp, "\t cmp rax, 0 \t\t ;Compare rax to 0\n");
    fprintf(fp, "\t je %s\n", label2);
    emitAST(p ->s2);
    fprintf(fp, "\t jmp %s\n", label1);
    fprintf(fp, "%s:\n", label2);
}//end of emit_while

//pre - ASt tree 
//post - will produce a NASM file that can be compliled and executed
//start of emitAST
void emitAST (ASTnode *p){
   int i;
   if(p == NULL) return; //no nodes to print
        //look at the diffrent node types
         switch (p ->type){
             
            //exit since the global variables function will handle this 
            case VarDec:
                 break;   
                 
            case FuncDec:
               emitStart(p);   //generate code for an AR
               //traverse to the other nodes in the program
               emitAST(p ->s1);
               emitAST(p ->s2);
               emitAST(p ->next);
               emitEnd();   //generate code for closing an AR
                 break;
                 
			   case Param:
                printMyType(p);
                printf("PARAMETER(s) \n", p ->name);
                 break;
                 
            case Block:
               printf("BLOCK STATEMENT\n");
               emitAST(p ->s1);
               emitAST(p ->s2);
                 break;
                 
            case Read:
               printf("READ STATEMENT\n");
               emit_ident(p ->s1); 
               fprintf(fp, "\t GET_DEC 8, [rax] \t\t ;Will read in a value\n");
               emitAST(p ->s1);   //go to the next node (s1) afterwards
                 break; 
                 
            case Write:
               printf("WRITE STATEMENT\n");

               //we got a string in write
               if(p ->mytype == STRINGType){
                fprintf(fp, "\t PRINT_STRING %s\t\t ;Writing in a String\n", p ->label);
                fprintf(fp, "\t NEWLINE\n\n");
               } else {
                //if not a String check
                switch(p ->s1 ->type){   //check the node type of s1
                   case Var:
                      emit_ident(p ->s1);
                      fprintf(fp, "\t mov rsi, [rax]\t\t ;Writing a variable\n");
                      break;

                   case Number:
                      if(p ->s1 ->mytype == BOOLType){
                        fprintf(fp, "\t mov rsi, %d\t\t ;Writing a Boolean\n",p ->s1 ->value);
                      } else {
                        fprintf(fp, "\t mov rsi, %d\t\t ;Writing a Number\n",p ->s1 ->value);
                      }
                      break;

                   case Expression:
                       emit_expr(p ->s1);
                       fprintf(fp, "\t mov rsi, [rsp + %d] \t\t ;Writing and Expression\n", (p ->s1 ->symbol ->offset) * wordSize);
                      break;

                   case Call:
                      break;
                   default:printf("unknown type \n");         
                }//end of 2nd switch
                //once the value is in rsi
                fprintf(fp, "\t PRINT_DEC 8, rsi\t\t ;Writing in a value\n");
                fprintf(fp, "\t NEWLINE\n\n");
               }
                 break;
                 
            case Var:
               printf("Identifier %s \n", p ->name);
               emit_ident(p);
               emitAST(p ->s1);   //go to the next node AFTERWARDS
                 break;
                 
            case Expression:  
               printf("EXPRESSION \n");
               emitAST(p ->s1);
               if(p ->myOperator != MyNot){
                   emitAST(p ->s2);
            }
                  break;
                  
            case Number:
                     emitAST(p ->s1);
                  break;
                  
            case Iterative:
               printf("WHILE STATEMENT\n");
               emit_while(p);
                  break;
                  
            case Assign:
               printf("ASSIGN STATEMENT\n");
               emit_ass(p);
                  break;
                  
            case Call:
               printf("CALL STATEMENT\n");
               printf("%s\n",p ->name);
               emitAST(p ->s1);
                  break;
                  
            case Select:
               printf("SELECT STATEMENT\n");
               emitAST(p ->s1);
               emitAST(p ->s2);
                  break;   
               
            case ReturnState:
               printf("RETURN STATEMENT\n");
               emitAST(p ->s1);
                  break;
               
            case ifState:
               printf("IF STATEMENT\n");
               emit_if(p);
                  break;
               
            case ifElse:
               printf("IF ELSE STATEMENT\n");
                  break;
               
            default: printf("unknown type in ASTprint\n");
         }//end of switch
         emitAST(p ->next);
}//end of printing a node 
