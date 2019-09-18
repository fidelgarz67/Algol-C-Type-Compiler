/*
Programmer: Fidel Garcia
Date: March 26. 2019
Details: This LEX program will look at a test file character by character
		and will create a token that is either one of our reserve words for our
		language and or symbols such as comparision operators. This file will 
		also be able to identify if a character sequence will either be an ID, 
		a number, whitespace (tabs), as well as newlines. 
*/
%{
int mydebug = 0;
int lineNum = 1;
#include "ast.h"
#include "y.tab.h"

%}

%%
"and"               {if (mydebug)fprintf(stderr, "and Found\n");return(AND);} 
"or"                {if (mydebug)fprintf(stderr, "or Found\n");return(OR);}
"not"               {if (mydebug)fprintf(stderr, "not Found\n");return(NOT);}
"void"              {if (mydebug)fprintf(stderr, "void Found\n");return(VOID);}
"while"             {if (mydebug)fprintf(stderr, "while Found\n");return(WHILE);}
"do"                {if (mydebug)fprintf(stderr, "do Found\n");return(DO);} 
"if"                {if (mydebug)fprintf(stderr, "if Found\n");return(IF);} 
"then"              {if (mydebug)fprintf(stderr, "then Found\n");return(THEN);} 
"else"              {if (mydebug)fprintf(stderr, "else Found\n");return(ELSE);} 
"read"              {if (mydebug)fprintf(stderr, "read Found\n");return(READ);}
"write"             {if (mydebug)fprintf(stderr, "write Found\n");return(WRITE);}
"for"               {if (mydebug)fprintf(stderr, "for Found\n");return(FOR);} 
"return"            {if (mydebug)fprintf(stderr, "return Found\n");return(RETURN);} 
'<'                 {if (mydebug)fprintf(stderr, "< Found\n");return(L);} 
'>'                 {if (mydebug)fprintf(stderr, "> Found\n");return(G);} 
"<="                {if (mydebug)fprintf(stderr, "<= Found\n");return(LE);}
">="                {if (mydebug)fprintf(stderr, ">= Found\n");return(GE);}
"=="                {if (mydebug)fprintf(stderr, "== Found\n");return(EQ);} 
"!="                {if (mydebug)fprintf(stderr, "!= Found\n");return(NE);} 
"begin"             {if (mydebug)fprintf(stderr, "begin Found\n");return(THEBEGIN);} 
"end"               {if (mydebug)fprintf(stderr, "end Found\n");return(END);}
"of"                {if (mydebug)fprintf(stderr, "of Found\n");return(OF);}
"boolean"           {if (mydebug)fprintf(stderr, "boolean Found\n");return(BOOLEAN);} 
"true"              {if (mydebug)fprintf(stderr, "true Found\n");return(TRUE);}
"false"             {if (mydebug)fprintf(stderr, "false Found\n");return(FALSE);}
"int"               {if (mydebug)fprintf(stderr, "int Found\n");return(INT);}     

\".*\"              {if (mydebug) fprintf(stderr, "STRING found\n");
                       yylval.string = strdup(yytext); return(STRING);}

[a-zA-Z][a-zA-Z0-9]*	{if (mydebug) fprintf(stderr,"ID found\n"); 
							yylval.string = strdup(yytext); return(ID);}
                       
[0-9][0-9]*				{if (mydebug) fprintf(stderr,"NUM found\n"); 
                          	yylval.number =atoi((const char *)yytext); return(NUM);}
                       
[ \t]						{if (mydebug) fprintf(stderr,"Whitespace found\n");}

[=\-+*/%&|(),\[\];]	{if (mydebug) fprintf(stderr,"return a token %c\n",*yytext); 
								return (*yytext);}
                       
\n							{if (mydebug) fprintf(stderr,"cariage return %c",*yytext); 
								lineNum++;}
%%
int yywrap(void){
	return 1;
}


