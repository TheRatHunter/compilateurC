#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "table_instructions.h"

#define SIZE_TINSTR 1000
int indiceInstruction = 0;

struct instruction * tabInstr;

void initInstrs() {
	tabInstr = malloc(sizeof(struct instruction)*SIZE_TINSTR);
}

int getIndiceInstr() {
	return indiceInstruction;
}

void displayInstructions() {

	printf("	+----------------------------------+\n");
	printf("	|          Code assembleur         |\n");
	printf("	+----------------------------------+\n");
	for (int i=0; i < indiceInstruction ; i++) {
		printf("	| %2d | %9s | %6d | %6d |\n",i, tabInstr[i].instr, tabInstr[i].arg1, tabInstr[i].arg2);
		printf("	+----------------------------------+\n");
	}

}

void addInstr(char instr[16], int arg1, int arg2) {

	if (indiceInstruction < 0 || indiceInstruction >= SIZE_TINSTR) {
		printf("Erreur d'indice\n");
		exit(1);
	} else {
		struct instruction newLine = { .instr = "", .arg1 = arg1, .arg2 = arg2 };	
		strcpy(newLine.instr , instr);
		tabInstr[indiceInstruction] = newLine ;
		indiceInstruction++;
	}
}

void patchInstr(int indOrig, int indDest){
	tabInstr[indOrig].arg1 = indDest;
}

void genererAsm(char* filename)
{
    FILE * f;

    f = fopen(filename, "w");
    if (f != NULL)
    {
		for (int i=0; i < indiceInstruction ; i++) {
			fprintf(f, "%s %d %d\n", tabInstr[i].instr, tabInstr[i].arg1, tabInstr[i].arg2);
		}
        fclose(f);
    }
    else
        perror("hello.txt");
}
