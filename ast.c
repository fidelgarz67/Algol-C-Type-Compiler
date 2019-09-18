/*
Programmer:Fidel Garcia
Date: March 26. 2019
Details: This is the C file that will be used to ensure that each AST node that is 
         created has a specific output, identifying what type of statement was read 
         or seen. This C program will also predetermine what each newly created node's
         pointers are set to, for example in our case it is either null or 0 as a default.
         This program will recursivly print all of the nodes with the proper indention
         to determine if a variable is within a funtion or not. 
*/
#include <stdio.h>
#include <stdlib.h>
#include "ast.h" 
extern int mydebug;

//Create a node
ASTnode *ASTCreateNode(enum ASTType type){
    ASTnode *p;
    if (mydebug) fprintf(stderr,"Creating AST Node \n");
    p = (ASTnode*)malloc(sizeof(ASTnode));
    p ->type = type; //either vardec or funcdec
    p ->mytype = VOIDType;
    p ->name = NULL; //variable ID
    p ->value = 0; //default size unless its an array
    p ->s1 = NULL;
    p ->s2 = NULL;
    p ->next = NULL;
	 p -> symbol = NULL;
    return(p);
}//end of creating a node

//Helper function to print tabbing
void printTabbing(int howmany){
    for (int i=1; i < howmany; i++){
       printf(" ");
    }
}//end of print tabbing

//Print a node
void ASTPrint (int level, ASTnode *p){
   int i;
   if(p == NULL) return; //no nodes to print
      else{
         //start indenting 
         printTabbing(level);
         switch (p ->myOperator){
            case VarDec:
                printMyType(p);
                 printf("Variable ");
                    printf("%s \n", p ->name);
                    if(p ->value > 0) {printf("with a size: [ %d ] \n", p ->value);}   
                 ASTPrint(level, p ->s1);
                 break;
                 
            case FuncDec:
               printMyType(p);
				   printf("FUNCTION %s \n", p ->name);
               ASTPrint(level+2,p ->s1);
               ASTPrint(level+2,p ->s2);
                 break;
			   case Param:
                printMyType(p);
				   printf("PARAMETER(s): ( %s )\n", p ->name);
                 break;
            case Block:
               printf("BLOCK STATEMENT\n");
               ASTPrint(level+1, p ->s1);
               ASTPrint(level+1, p ->s2);
                 break;
            case Read:
               printf("READ STATEMENT\n");
               ASTPrint(level+1, p ->s1); 
                 break; 
            case Write:
               printf("WRITE STATEMENT\n");
               ASTPrint(level+1, p ->s1); 
                 break;
            case Var:
               printf("Identifier %s \n", p ->name);
               ASTPrint(level+1, p ->s1);
                 break;
            case Expression:  
               printf("EXPRESSION ");
                  switch(p ->myOperator) {
                        case MyPlus : printf(" + ");break;
                        case MyMinus : printf(" - ");break;
                        case GreatThen: printf(" > ");break;
                        case LessThen: printf(" < ");break;
                        case MyDiv: printf(" / ");break;
                        case MyTimes: printf(" * ");break;
                        case GreatThenEQ: printf(" >= ");break; 
                        case LessThenEQ: printf(" <= ");break; 
                        case EqualTo: printf(" == ");break; 
                        case NotEqualTo: printf(" != ");break; 
                        case MyOR: printf(" OR ");break;
                        case MyAND: printf(" AND ");break;
                  }
                  printf("\n");
                     ASTPrint(level+1, p ->s1);
                  if (p ->mytype != MyNot) {ASTPrint(level+1, p ->s2);}
                  break;
            case Number:
               if(p -> value == 0){
                  printf("False value was found. \n");
               }else if(p -> value == 1){
                  printf("True value was found. \n");
                  }else{
                     printf("NUMBER FOUND ");
                     printf("%d\n", p -> value);
                     }
                     ASTPrint(level+1, p ->s1);
                  break;
            case Iterative:
               printf("WHILE STATEMENT\n");
                  ASTPrint(level+1, p ->s1);
                  ASTPrint(level+1, p ->s2);
                  break;
            case Assign:
               printf("ASSIGN STATEMENT\n");
                  ASTPrint(level+1, p ->s1);
                  ASTPrint(level+1, p ->s2);
                  break;
            case Call:
               printf("CALL STATEMENT\n");
                  printf("%s\n",p ->name);
                  ASTPrint(level+1, p ->s1);
                  ASTPrint(level+1, p ->s2);
                  ASTPrint(level+1, p ->next);
                  break;
            case Select:
               printf("SELECT STATEMENT\n");
               ASTPrint(level+1, p ->s1);
               ASTPrint(level+1, p ->s2);
               break;      
            case ReturnState:
               printf("RETURN STATEMENT\n");
               ASTPrint(level+1, p ->s1);
               break;
            case ifState:
               printf("IF STATEMENT\n");
               ASTPrint(level+1, p ->s1);
               ASTPrint(level+1, p ->s2);
               break;
            case ifElse:
               printf("IF ELSE STATEMENT\n");
               ASTPrint(level+1, p ->s1);
               ASTPrint(level+1, p ->s2);
               break;
            default: printf("unknown type in ASTprint\n");
         }//end of switch
         ASTPrint(level, p ->next);
      }
}//end of printing a node
void printMyType(ASTnode *p){
    if(p ->mytype == INTType) {printf("INT ");}
    if(p ->mytype == VOIDType){printf("VOID ");}
    if(p ->mytype == BOOLType){printf("BOOLEAN ");}
}
