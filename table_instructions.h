struct instruction
{
	char instr[16];
	int arg1;
	int arg2;
};

void initInstrs();

void addInstr(char instr[16], int arg1, int arg2);

int getIndiceInstr();

void patchInstr(int indOrig, int indDest);

void displayInstructions();

void genererAsm(char* filename);

void genererCodeHexa(char* filename);
