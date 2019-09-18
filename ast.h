/* 
Programmer: Fidel Garcia
Date: March 26. 2019
Details: This is the Header file for the C program that will apply semantic action 
         for our lexical and YACC file. This header file will have the enumerators for
         the Abtract Syntax Tree(AST), as well as System Types. This file will also define
         the properties of the AST node types such as any pointer, and or properties 
         that need to be saved (type, value and even name).
*/

#include<stdio.h>
//#include<malloc/malloc.h>
#include<malloc.h>
#ifndef ast
#define ast

enum ASTType {
   VarDec,
	FuncDec,
   Param,
   Block,
   LocalDec,
   Var,
   Number,
   Expression,
   Call,
   Read,
   Write,
   ReturnState,
   Assign,
   Iterative,
   ifState,
   ifElse,
   Select
};

enum Operator{
   MyNot,
   MyAND,
   MyOR,
   MyTimes,
   MyDiv,
   MyPlus,
   MyMinus,
   LessThenEQ,
   LessThen,
   GreatThen,
   GreatThenEQ,
   EqualTo,
   NotEqualTo
};

enum SystemType{
   INTType,
   VOIDType,
   BOOLType,
   NULLType,
   STRINGType
};

typedef struct ASTnodetype {
	enum Operator myOperator;
	enum SystemType mytype;
	enum ASTType type;
    char *label;
    char *name;
	int value;
	int size;
	struct SymbTab *symbol;
	struct ASTnodetype *next, *s1, *s2;
}ASTnode;

#include "symtable.h"

//Prototypes
ASTnode *ASTCreateNode(enum ASTType type);
void ASTPrint (int level,ASTnode *p);
void printTabbing(int howmany);
void printMyType(ASTnode *p);

#endif
