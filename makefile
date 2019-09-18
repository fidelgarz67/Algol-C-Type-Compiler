#Programmer: Fidel Garcia
#Date: March 26.2019
#Description: This make file will compile and run Lab6's lex 
#             and Yacc files with an included test file included.
all:
	yacc -d lab9.y
	lex lab9.l
	gcc y.tab.c ast.c ast.h symtable.c symtable.h emit.c emit.h lex.yy.c -o lab9
	./lab9 -o Lab9 <test.dat
