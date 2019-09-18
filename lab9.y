 %{
/*
Programmer: Fidel Garcia
Date: March 26. 2019
Details: This YACC program will interpet the tokens that are given from our LEX
		program and will create and interpet the tokens into our regular Expression
		language. This program will also create nodes that are predefined in 
		our C program and header file. Additionally, this program will also have
		semantic action after every declaration, weather it be with variables
		variable types, and or compositional statements such as functions, if 
		statements, read, writes and call methods, with the additional a symbol table and type checking. 
Input: This file will take tokens from LEX.
Output: This file will handle the tokens from LEX and if the tokens are in the
		correct sequence then the file will create nodes and have function calls 
		to print, what tokens are seen. If the sequence is not correct then this
		file will display a generic syntax error.   
*/	
	
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include "ast.h"
#include "symtable.h"
#include "emit.h"

extern int lineNum;
extern int mydebug;

int level = 0;
int offset = 2;
int tempOffest = 0;
int maxOffset = 0;
int yylex(); 

struct ASTnodetype *myprogram = NULL;				

/* Called by yyparse on error */
void yyerror (s)  
	char *s;{
  fprintf (stderr,"%s on line %d\n", s, lineNum);
				}
%}

/*defines the start symbol*/ 
%start program

%union {
  int number;
  char *string;
  struct ASTnodetype *ASTnode;
	enum Operator myOperator;
	enum SystemType myType;
}

%token <number> NUM 
%token <string> ID INT VOID WHILE DO IF THEN ELSE READ WRITE FOR RETURN LE GE EQ NE L G STRING
%token THEBEGIN END OF BOOLEAN TRUE FALSE AND OR NOT 
%type <ASTnode> varDecl varList funcDecl param params paramList compState declList factor args addExpr exprState selcState iterState
%type <ASTnode> locDecl decl stateList state var readState expr simpExpr program wrtState call argsList term assState retState ';'
%type <myType> type 
%type <myOperator> multop relop addop
%left '+' '-' '/' '*' '%'

%% /* end specs, begin rules */

program   :declList	{myprogram = $1;}
          ;

declList  :decl	{$$ = $1;}
          |decl declList	{$$ = $1;
                           $1 ->next = $2;}
          ;

decl      :varDecl {$$ = $1;}
          |funcDecl {$$ = $1;}
          ;

varDecl   :type varList';' {$$ = $2;
							ASTnode *p;
							p = $$;
								while (p != NULL){
									p ->mytype = $1;
									p ->symbol ->Type = $1;
									p = p ->s1;
								}
                            }
          ;

varList   :ID {struct SymbTab *p;
					if (Search($1, level, 0) == NULL){
						$$ = ASTCreateNode(VarDec);
                        $$ ->name = $1;
						$$ ->symbol = Insert($1, 0, 0, level, 1, offset, NULL);
							offset++;
							Display();
							} else{
								yyerror($1);
								yyerror("Error: Value(s) already been prev. declared.");
								exit(1);
							}
              }
				  
          |ID '[' NUM ']' {struct SymbTab *p;
									if (Search($1, level, 0) == NULL){
				 					   $$ = ASTCreateNode(VarDec);
                     $$ ->name = $1;
									   $$ ->value = $3;
                     $$ ->symbol = Insert($1, 0, 2, level, $3, offset, 0);
										offset = offset + $3;
										Display();
                          	} else{
									  yyerror($1);
									  yyerror("Error: Value(s) already been prev. declared.");
									  exit(1);
                          		}
							  		}
								  
          |ID ',' varList {struct SymbTab *p;
				 					if (Search($1, level, 0) == NULL){
				 					   $$ = ASTCreateNode(VarDec);
                     $$ ->name = $1;
                     $$ ->s1 = $3;
									   $$ ->symbol = Insert($1, 0, 0, level, 1, offset, 0);
										offset++;
										Display();
                          } else{
									  yyerror($1);
									  yyerror("Error: Value(s) already been prev. declared.");
									  exit(1);
                          		}
							  }
								  
          |ID '[' NUM ']' ',' varList {struct SymbTab *p;
                                        if (Search($1, level, 0) == NULL){
                                           $$ = ASTCreateNode(VarDec);
                                           $$ ->name = $1;
                                           $$ ->symbol = Insert($1, 0, 2, level, $3, offset, 0);
                                            offset = offset + $3;
                                           $$ ->value = $3;
                                           $$ ->s1 = $6;
                                       } else {
                                            yyerror($1);
                                            yyerror("Error: Value(s) already been prev. declared");
                                            exit(1);
                                       }
                                    }
          ;

type      :INT {$$ = INTType;}                              
          |VOID {$$ = VOIDType;} 
          |BOOLEAN {$$ = BOOLType;} 
          ;
          
funcDecl  :type ID {if(Search($2, level, 0)== NULL){
                    tempOffest = offset;
                    offset = 2;
                    maxOffset = offset;
                    Insert($2, $1, 1, level, 1, offset, 0);
                        }else{
                        	yyerror($2);
									yyerror("Error: Function has already been prev defined");
									exit(1);
                        }
                    }
                    
            '('params')' {Search($2, 0, 0) -> fparms = $5;}/*Search will return p!!!*/
            
            compState {struct SymbTab *p;
                        $$ = ASTCreateNode(FuncDec);
                        $$ ->name = $2;
                        $$ ->mytype = $1;
                        $$ ->size = maxOffset; /* size of the node */
                        $$ ->symbol = Search($2, level, 0);
                        $$ ->symbol ->offset = maxOffset; /* size of the Symb struct */
                        $$ ->s1 = $5;
                        $$ ->s2 = $8;
                        offset = tempOffest;
                        }
          ;

params    :VOID {$$ = NULL;}                              
          |paramList {$$ = $1;}                         
          ;

paramList :param {$$ = $1;}                             
          |param ',' paramList {$1 -> next = $3;}               
          ;

param     :type ID {if (Search($2, level+1, 0) == NULL){
  							$$ = ASTCreateNode(Param);
  						 	$$ ->name =$2;
  						 	$$ ->mytype = $1;
							$$ ->symbol = Insert($2, $1, 0, level+1, 1, offset, 0);
								offset++;
								}else{
									yyerror($2);
									yyerror("Error: Parameter has already been prev. defined");
									exit(1);
								}
						  
                   }                           
          |type ID '['']' {if (Search($2, level+1, 0) == NULL){
									$$ = ASTCreateNode(Param);
             				  	$$ ->name = $2;
									$$ ->value = -1;
            					$$ ->mytype = $1;
									$$ ->symbol = Insert($2, $1, 2, level+1, 1, offset, 0);
										offset++;
          						}else{
										yyerror($2);
										yyerror("Error: Parameter [] has already been prev. defined");
										exit(1);
          							}
                          }                       
          ;

compState: THEBEGIN {level++;}
				locDecl stateList END {$$ = ASTCreateNode(Block);
                                           $$ -> s1 = $3;
                                           $$ -> s2 = $4;
														 Display();
														 if (maxOffset < offset)
														 	maxOffset = offset;
														 	offset = offset - Delete(level);
															level--;
                                           }   
          ;

locDecl   :/*empty*/ {$$ = NULL;}
          |varDecl locDecl {$$ = $1;
                            $1 -> next = $2;}    
          ;

stateList :/*empty*/ {$$ = NULL;}
          |state stateList {$$ = $1;
                            $1 -> next = $2;}                   
          ;

state     :exprState {$$ = $1;}
          |compState {$$ = $1;}                      
          |selcState {$$ = $1;}                         
          |iterState {$$ = $1;}                         
          |assState {$$ = $1;}                         
          |retState {$$ = $1;}                         
          |readState {$$ = $1;}                        
          |wrtState {$$ = $1;}                         
          ;

exprState :expr';' {$$ = ASTCreateNode(Expression);
                    $$ -> s1 = $1;}  
						                           
          |';' {$$ = ASTCreateNode(Expression);}                               
          ; 

selcState :IF expr THEN state {$$ = ASTCreateNode(ifState);
                               $$ -> s1 = $2;
                               $$ ->s2 = ASTCreateNode(ifElse);
                               $$ -> s2 ->s1 = $4;
                               }       
										          
          |IF expr THEN state ELSE state{$$ = ASTCreateNode(ifState);
                                         $$ ->s1 = $2;
                                         $$ ->s2 = ASTCreateNode(ifElse);
                                         $$ ->s2 ->s1 = $4;
                                         $$ ->s2 ->s2 = $6;
                                         }     
          ;

iterState :WHILE expr DO state{$$ = ASTCreateNode(Iterative);
                               $$ ->s1 = $2;
                               $$ ->s2 = $4;
                               }               
          ;

retState  :RETURN ';' {$$ = ASTCreateNode(ReturnState);}                        
          |RETURN expr ';' {$$ = ASTCreateNode(ReturnState);
                            $$ ->s1 = $2;
                           }                   
          ;

readState :READ var ';' {$$ = ASTCreateNode(Read);
                         $$ ->s1 = $2; 
                        }                      
          ;

wrtState  :WRITE expr ';' {$$ = ASTCreateNode(Write);
                           $$ ->s1 = $2;
                          } 

          |WRITE STRING ';' {$$ = ASTCreateNode(Write);
                             $$ ->name = $2;
                             $$ ->mytype = STRINGType;
                             $$ ->label = label();
                            }                
          ;

assState  :var '=' simpExpr ';'{$$ = ASTCreateNode(Assign);
                                $$ ->s1 = $1;
                                $$ ->s2 = $3;
                                }              
          ;

expr      :simpExpr {$$ = $1;}                     
          ;

simpExpr  :addExpr {$$ = $1;}                            
          |addExpr relop addExpr {if ($1 ->mytype == $3 ->mytype){
				 							$$ = ASTCreateNode(Expression);
                            	  	$$ ->s1 = $1;
                     				$$ ->s2 = $3;
      									$$ ->mytype = $3 ->mytype;
											$$ ->myOperator = $2;
											$$ ->name = createTemp();
											$$ ->symbol = Insert($$ ->name, INTType, 0, level, 1, offset, 0);
                                                offset++;
											}else{
												yyerror("Error: Add expression mismatch");
												exit(1);
											}
										         
										}   
          ;

var       :ID {struct SymbTab *p;
					if((p = Search($1, level, 1)) != NULL){
						$$ = ASTCreateNode(Var);
	               $$ ->name = $1;
						$$ ->symbol = p;
						$$ ->mytype = p ->Type;
						if(p ->IsAFunc == 2){
							yyerror($1);
							yyerror("Error: Variable is not a function");
							exit(1);
						}
						}else{
							yyerror($1);
							yyerror("Error: Variable has already been prev. defined");
							exit(1);
						}
              }       
				                           
          |ID '['expr']'{struct SymbTab *p;
				 				if((p = Search($1, level, 1)) != NULL){
					 				$$ = ASTCreateNode(Var);
	          				  	$$ ->name = $1;
	           				 	$$ ->s1 = $3;
									$$ ->mytype = p ->Type;
									if(p ->IsAFunc == 2){
										$$ ->symbol = p;
										}else{
											yyerror($1);
											yyerror("Variable [], is not a function");
										}
				 				} else{
				 					yyerror($1);
									yyerror("Error: Variable [], has already prev. been defined");
				 					exit(1);
									}	
                        }                     
          ;          

relop     :LE {$$ = LessThenEQ;}                                  
          |'<' {$$ = LessThen;}                                 
          |'>' {$$ = GreatThen;}                                 
          |GE {$$ = GreatThenEQ;}                                
          |EQ {$$ = EqualTo;}                                
          |NE {$$ = NotEqualTo;}                                
          ;

addExpr   :term {$$ = $1;}                            
          |addExpr addop term {if($1 ->mytype == $3 ->mytype){
				 							$$ = ASTCreateNode(Expression);
				                		$$ ->s1 = $1;
				                  	$$ ->s2 = $3;
				                     $$ ->mytype = $3 ->mytype;
											$$ ->myOperator = $2;
											$$ ->name = createTemp();
											$$ ->symbol = Insert($$ ->name, INTType, 0, level, 1, offset, 0);
												offset++;
          							}else{
          								yyerror("Error: Add expression type mismatch");
											exit(1);
          								}
                              }               
          ;

addop     :'+' {$$ = MyPlus;}                               
          |'-' {$$ = MyMinus;}                                
          ;

term      :factor {$$ = $1;}                          
          |term multop factor {if($1 ->mytype == $3 ->mytype){
				 							$$ = ASTCreateNode(Expression);
				                		$$ ->s1 = $1;
				                  	$$ ->s2 = $3;
				                     $$ ->mytype = $3 ->mytype;
											$$ ->myOperator = $2;
											$$ ->name = createTemp();
											$$ ->symbol = Insert($$ ->name, INTType, 0, level, 1, offset, 0);
												offset++;
          							}else{
          								yyerror("Error: Add expression type mismatch");
											exit(1);
          								}
                              }              
          ;

multop    :'*' {$$ = MyTimes;}                               
          |'/' {$$ = MyDiv;}                              
          |AND {$$ = MyAND;}                              
          |OR {$$ = MyOR;}                               
          ;

factor    :'('expr')'{$$ = $2;}                       
          |NUM {$$ = ASTCreateNode(Number);
                $$ ->value = $1;
					 $$ ->mytype = INTType;
                }                                
          |var {$$ = $1;}                               
          |call {$$ = $1;}                              
          |TRUE {$$ = ASTCreateNode(Number);
                 $$ ->value = 1;
					  $$ ->mytype = BOOLType;
                 }                               
          |FALSE {$$ = ASTCreateNode(Number);
                  $$ ->value = 0;
						$$ ->mytype = BOOLType;
                 }                              
          |NOT factor{$$ = ASTCreateNode(Expression);
                      $$ ->myOperator = MyNot;
                      $$ ->s1 = $2;
                      $$ ->mytype = $2 ->mytype;
                      $$ ->name = createTemp();
                      $$ ->symbol = Insert($$ ->name, BOOLType, 0, level, 1, offset, 0);
                      offset++;
                     }                        
          ;

call      : ID'('args')' {struct SymbTab *p;
								if((p = Search($1, level, 1)) != NULL){
									if(p ->IsAFunc != 1){
										yyerror($1);
										yyerror("Error: Call is not a function");
										exit(1);
									}
									if(compareFormula(p ->fparms, $3) != 1){
										yyerror($1);
										yyerror("Error: Param lenght/type mismatch");
										exit(1);
									}
									$$ = ASTCreateNode(Call);
                                    $$ ->name = $1;
                                    $$ ->s1 = $3;
									$$ ->symbol = p;
									$$ ->mytype = p ->Type;
									}else{
										yyerror($1);
										yyerror("Error: Reference has not yet been defined");
										exit(1);
									}
									
									
									
									
                         }                     
          ;

args      :/*empty*/ {$$ = NULL;}
          |argsList {$$ = $1;}                          
          ;
argsList  :expr {$$ = ASTCreateNode(Expression);
						$$ = $1;
                 	$$ ->mytype = $1 ->mytype;
						
					}                              
          |expr ',' argsList {$$ = ASTCreateNode(Expression);
                         		$$ ->s1 = $1;
                        		$$ ->next = $3;
                    			 	$$ ->mytype = $1 ->mytype; 
									}
          ;          
%%  /* end of rules, start of program */

//arguments are being parsed and passed by the compiler
int main(int argc, char*argv[]){
   //set the initial file pointer to null
	fp = NULL;
	char myfile[100];
	yyparse();
	
	//loop to find the argument
	for(int i = 0; i < argc; i++){
      if(strcmp(argv[i], "-d") == 0){
        mydebug = 1;
        printf("Debugging is now turned ON");
      }
	   printf("arg at %d is %s \n", i, argv[i]);
	   if(strcmp(argv[i], "-o") == 0){
	      printf("Got it, file name is %s \n", argv[i+1]);

	      //create a file with the name given
	      strcpy(myfile, argv[i+1]);

	      //attach the asm extention to the created file
	      strcat(myfile, ".asm");
	      printf("The name of the file is %s:\n", myfile);

	      //open the file in order to write to it
	      fp = fopen(myfile, "w");

	      //error check the new file
	      if(fp == NULL){
	         printf("The file is NOT writeable.");
	      }else {
            //writing into the file
	         fprintf(fp, "%%include \"io64.inc\" \n");
	         emitGlobal(myprogram);
	         fprintf(fp, "section .data\n\n");
	         emitString(myprogram);
            fprintf(fp, "section .text\n\n");
            fprintf(fp, "\t global main\n"); 
             emitAST(myprogram);
         //close the file when done writing to it   
         fclose(fp);
	         }//end of else
	}//end of if
   }//end of for loop
}//end of main method
