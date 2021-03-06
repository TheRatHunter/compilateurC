all: compiler interpreter
lex.yy.c:compiler.l
	flex compiler.l
rule.tab.c: rule.y
	bison -d -v rule.y
compiler: lex.yy.c rule.tab.c table_symboles.c table_instructions.c
	#gcc -g -o compiler lex.yy.c rule.tab.c table_symboles.c table_instructions.c libfl.a ./bison-3.0.4/lib/liby.a
	#Version INSA :
	gcc -std=c99 -g -o compiler lex.yy.c rule.tab.c table_symboles.c table_instructions.c libfl.a ~/Programmes/bison-3.0.4/lib/liby.a
test: compiler
	./compiler<test.c
test2: compiler
	./compiler<test2.c
interpreter: interpreteur.c
	gcc -std=c99 -Wall -o interpreteur interpreteur.c
testI: interpreter
	./interpreteur output.asm
tests: compiler interpreter
	#Doit afficher dans l'ordre : 3 4 8 35 35 3 4 5
	./compiler<test.c
	./interpreteur output.asm
tests2: compiler interpreter
	#Doit afficher 3 puis 35
	./compiler<test2.c
	./interpreteur output.asm
tests3: compiler interpreter
	#Doit afficher dans l'ordre : 5 3 8 7 20 40 20 16 22 44 66 3 4 5 6 99
	cat testPerso.c
	./compiler<testPerso.c
	./interpreteur output.asm
etape1: compiler
	./compiler<testPerso.c
etape2: interpreter
	#Doit afficher dans l'ordre : 5 3 8 7 20 40 20 16 22 44 66 3 4 5 6 99
	./interpreteur output.asm

