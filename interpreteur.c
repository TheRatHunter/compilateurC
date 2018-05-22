#include <stdio.h> 
#include <stdlib.h>
#include <string.h>

#include "table_instructions.h"

#define SIZE_TINSTR 1000

int indiceInstruction = 0;
int nbInstructions;
int reg[16];
int memoireDonnees[1024];
int ip = 0;
struct instruction * tabInstr;

void initInstrs() {
	tabInstr = malloc(sizeof(struct instruction)*SIZE_TINSTR);
}

void printRegistres() {
	printf("	+---------------------+\n");
	printf("	|      Registres      |\n");
	printf("	+---------------------+\n");
	for (int i=0; i < 16 ; i++) {
		printf("	| %3d |           %3d |\n",i, reg[i]);
	}
	printf("	+---------------------+\n");
}

void interpreter() {
	printf("Interprétation du code ASM...\n");
	while (ip < nbInstructions){

		if (!strcmp(tabInstr[ip].instr,"jmp") ) {
			printf("-> jmp   détecté, ip =%3d , arg1 =%3d , arg2 =%3d\n", ip, tabInstr[ip].arg1, tabInstr[ip].arg2);
			printRegistres();
			ip = tabInstr[ip].arg1 ;
		} else if (!strcmp(tabInstr[ip].instr,"add")) {
			printf("-> add   détecté, ip =%3d , arg1 =%3d , arg2 =%3d\n", ip, tabInstr[ip].arg1, tabInstr[ip].arg2);
			reg[tabInstr[ip].arg1] += reg[tabInstr[ip].arg2];
			printRegistres();
			ip++;
		} else if (!strcmp(tabInstr[ip].instr,"sub")) {
			printf("-> sub   détecté, ip =%3d , arg1 =%3d , arg2 =%3d\n", ip, tabInstr[ip].arg1, tabInstr[ip].arg2);
			printRegistres();
			ip++;
		} else if (!strcmp(tabInstr[ip].instr,"mul")) {
			printf("-> mul   détecté, ip =%3d , arg1 =%3d , arg2 =%3d\n", ip, tabInstr[ip].arg1, tabInstr[ip].arg2);
			printRegistres();
			ip++;
		} else if (!strcmp(tabInstr[ip].instr,"div")) {
			printf("-> div   détecté, ip =%3d , arg1 =%3d , arg2 =%3d\n", ip, tabInstr[ip].arg1, tabInstr[ip].arg2);
			printRegistres();
			ip++;
		} else if (!strcmp(tabInstr[ip].instr,"equ")) {
			printf("-> equ   détecté, ip =%3d , arg1 =%3d , arg2 =%3d\n", ip, tabInstr[ip].arg1, tabInstr[ip].arg2);
			printRegistres();
			ip++;
		} else if (!strcmp(tabInstr[ip].instr,"nequ")) {
			printf("-> nequ  détecté, ip =%3d , arg1 =%3d , arg2 =%3d\n", ip, tabInstr[ip].arg1, tabInstr[ip].arg2);
			printRegistres();
			ip++;
		} else if (!strcmp(tabInstr[ip].instr,"inf")) {
			printf("-> inf   détecté, ip =%3d , arg1 =%3d , arg2 =%3d\n", ip, tabInstr[ip].arg1, tabInstr[ip].arg2);
			printRegistres();
			ip++;
		} else if (!strcmp(tabInstr[ip].instr,"infe")) {
			printf("-> infe  détecté, ip =%3d , arg1 =%3d , arg2 =%3d\n", ip, tabInstr[ip].arg1, tabInstr[ip].arg2);
			printRegistres();
			ip++;
		} else if (!strcmp(tabInstr[ip].instr,"sup")) {
			printf("-> sup   détecté, ip =%3d , arg1 =%3d , arg2 =%3d\n", ip, tabInstr[ip].arg1, tabInstr[ip].arg2);
			printRegistres();
			ip++;
		} else if (!strcmp(tabInstr[ip].instr,"supe")) {
			printf("-> supe  détecté, ip =%3d , arg1 =%3d , arg2 =%3d\n", ip, tabInstr[ip].arg1, tabInstr[ip].arg2);
			printRegistres();
			ip++;
		} else if (!strcmp(tabInstr[ip].instr,"afc")) {
			printf("-> afc   détecté, ip =%3d , arg1 =%3d , arg2 =%3d\n", ip, tabInstr[ip].arg1, tabInstr[ip].arg2);
			reg[tabInstr[ip].arg1] = tabInstr[ip].arg2;
			printRegistres();
			ip++;
		} else if (!strcmp(tabInstr[ip].instr,"store")) {
			printf("-> store détecté, ip =%3d , arg1 =%3d , arg2 =%3d\n", ip, tabInstr[ip].arg1, tabInstr[ip].arg2);
			memoireDonnees[tabInstr[ip].arg1] = reg[tabInstr[ip].arg2];
			printf("On a stocké dans la mémoire de données à l'adresse %d la valeur %d venant du registre %d.\n", 
				tabInstr[ip].arg1, memoireDonnees[tabInstr[ip].arg1], tabInstr[ip].arg2);
			ip++;
		} else if ((!strcmp(tabInstr[ip].instr,"load"))) {
			printf("-> load  détecté, ip =%3d , arg1 =%3d , arg2 =%3d\n", ip, tabInstr[ip].arg1, tabInstr[ip].arg2);
			reg[tabInstr[ip].arg2] = memoireDonnees[tabInstr[ip].arg1];
			printf("On a stocké dans le registre %d la valeur %d contenue dans la mémoire de données à l'adresse %d.\n", 
				tabInstr[ip].arg2, memoireDonnees[tabInstr[ip].arg1], tabInstr[ip].arg1);
			ip++;
		} else if ((!strcmp(tabInstr[ip].instr,"print"))) {
			printf("-> print détecté, ip =%3d , arg1 =%3d , arg2 =%3d\n", ip, tabInstr[ip].arg1, tabInstr[ip].arg2);
			printRegistres();
			printf("%d\n", tabInstr[ip].arg1);
			ip++;
		} else {
			printf("ERREUR INSTRUCTION INCONNUE, ip=%d, arg1=%d, arg2=%d\n", ip, tabInstr[ip].arg1, tabInstr[ip].arg2);
			printRegistres();
			ip++;
		}

	} 

}


int parse( char* filename )
{
	printf("Lecture du fichier %s...\n", filename);
	initInstrs();

	//static const char filename[] = "output.asm";
	FILE *file = fopen ( filename, "r" );
	if ( file != NULL )
	{
		char line [ 128 ]; 
 
		while ( fgets ( line, sizeof line, file ) != NULL )
		{

			char *str = line;
			char *token;
		 
			//Découper la chaîne selon les espaces
			token = strtok (str," ");

		 	struct instruction newLine = { .instr = "", .arg1 = -1, .arg2 = -1 };	
			for (int i=0; i<3; i++)
			{				
				if (i==0) {				
					strcpy(newLine.instr , token);
				} else if (i == 1) {
					newLine.arg1 = atoi(token);
				} else if (i == 2) {
					newLine.arg2 = atoi(token);
				}	 
				token = strtok (NULL, " ,");
			}
			
			tabInstr[indiceInstruction++] = newLine ;

		}
		nbInstructions = indiceInstruction;
		fclose ( file );
	}
	else
	{
		perror ( filename ); // why didn't the file open? 
	}
	return 0;
}

void displayInstructions() {

	printf("	+----------------------------------+\n");
	printf("	|   Code ASM lu dans le fichier    |\n");
	printf("	+----------------------------------+\n");
	for (int i=0; i < indiceInstruction ; i++) {
		printf("	| %2d | %9s | %6d | %6d |\n",i, tabInstr[i].instr, tabInstr[i].arg1, tabInstr[i].arg2);
		printf("	+----------------------------------+\n");
	}

}

int main(int argc, char *argv[]) {
	printf("Lancement de l'interpréteur...\n");
	if (argc!=2) {
		printf("Un argument SVP (vous en avez rentré %d).\n", (argc-1));
		exit(-1);
	}
	printf("Parsing du fichier output.asm...\n");
	parse(argv[1]);
	printf("Instructions lues dans le fichier output.asm :\n");
	displayInstructions();
	printf("Interprétation :\n");
	interpreter();
	return 0;
}



