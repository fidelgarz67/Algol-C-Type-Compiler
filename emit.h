/* 
Programmer: Fidel Garcia
Date: May 2. 2019
Details: an Emit h file that will priduce asm code.
*/
#include<stdio.h>
//#include<malloc/malloc.h>
#include<malloc.h>
#include<string.h>
#include"ast.h"
#include <stdlib.h>

#ifndef emit_h
#define emit_h

//decalred needed variables
FILE *fp;
char *label();

//Prototypes
void emitGlobal(ASTnode *p);
void emitString(ASTnode *p);
void emit_ident(ASTnode *p);
void emitStart(ASTnode *p);
void emitEnd();
void emitAST(ASTnode *p);
void emit_expr (ASTnode *p);
void emit_ass(ASTnode *p);
void emit_if (ASTnode *p);
void emit_while (ASTnode *p);

#endif
