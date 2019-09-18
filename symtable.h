/*  Symbol Table --linked list  headers
    Used for Compilers class

    Modified Spring 2015 to allow for name to pointed to by symtable, instead of copied, since the name is copied
    into the heap

    Modified to have levels.  A level 0 means global variable, other levels means in range of the function.  We
    start out our offsets at 0 (from stack pointer) for level 1,,,when we enter a functional declaration.
    We increment offset each time we insert a new variable.  A variable is considered to be valid if it is found in
    the symbol table at our level or lesser level.  If at 0, then it is global.  

    We return a pointer to the symbol table when a variable matches our creteria.

    We add a routine to remove variables at our level and above.
*/

#include "ast.h"

#ifndef _SYMTAB 
#define _SYMTAB

void Display();
int Delete(int level);
int FetchAddr (char *lab);

struct SymbTab{
     char *name;
     int offset; /* from activation record boundary */
     int mysize;  /* number of words this item is 1 or more */
     int level;  /* the level where we found the variable */
     enum Operator myOperator;  /* the type of the symbol */
     enum SystemType Type;
     int IsAFunc;  /* the element is a function */
     ASTnode *fparms; /* pointer to parameters of the function in the AST */
     struct SymbTab *next; /* pointer for next as well as first */
};

/*Prototypes*/
struct SymbTab *Insert(char *name, enum SystemType myType, int isafunc, int level, int mysize, int offset, ASTnode *fparms );
void PrintSym(struct SymbTab *s);
void Display();
struct SymbTab *Search(char name[], int level, int recur);
int Delete(int level);
char *createTemp();
int compareFormula(ASTnode *fparms, ASTnode *args);
#endif
