%{
	#include "rule.tab.h"
%}

%option yylineno

CARACTERE "\'"[a-zA-Z_]"\'"
NOM [a-zA-Z_]+
NOMBRE (-)?[0-9]+("e"(-)?[0-9]+)?
ACCOLADE_OUVRANTE "{"
ACCOLADE_FERMANTE "}"
PLUS "+"
MOINS "-"
FOIS "*"
DIVISE "/"
EGAL "="
DOUBLE_EGAL "=="
DIFFERENT "!="
INFERIEUR "<"
INFERIEUR_EGAL "<="
SUPERIEUR ">"
SUPERIEUR_EGAL ">="
POINT_EXCLAM "!"
PARENTHESE_OUVRANTE "("
PARENTHESE_FERMANTE ")"
GUILLEMET "\""

%%
[\t \n] { }
"," {return tVIRGULE ;}
";" { return tFIN_INSTRUCTION; }
"printf" { return tPRINTF ; }
{ACCOLADE_OUVRANTE} { return tACCOLADE_OUVRANTE ; }
{ACCOLADE_FERMANTE} { return tACCOLADE_FERMANTE ; }
{GUILLEMET} { return tGUILLEMET ; }
{PLUS} { return tPLUS ; }
{MOINS} { return tMOINS ; }
{FOIS} { return tFOIS ; }
{DIVISE} { return tDIVISE ; }
{EGAL} { return tEGAL ; }
{PARENTHESE_OUVRANTE} { return tPARENTHESE_OUVRANTE ; }
{PARENTHESE_FERMANTE} { return tPARENTHESE_FERMANTE ; }
{DOUBLE_EGAL} { return tDOUBLE_EGAL ;}
{DIFFERENT} { return tDIFFERENT ;}
{INFERIEUR} { return tINFERIEUR ;}
{INFERIEUR_EGAL} { return tINFERIEUR_EGAL ;}
{SUPERIEUR} { return tSUPERIEUR ;}
{SUPERIEUR_EGAL} { return tSUPERIEUR_EGAL ;}
{POINT_EXCLAM} { return tPOINT_EXCLAM ;}

"if" {return tIF ; }
"else" {return tELSE ;}
"const" { return tCONST ; }
"int" { yylval.str = strdup(yytext);
		return tINT ; }
"char" { yylval.str = strdup(yytext);
		return tCHAR ; }
"void" { yylval.str = strdup(yytext);
		return tVOID ; }
"while" { yylval.str = strdup(yytext);
		return tWHILE ; }
"NULL" { return tNULL ; }

{NOM} { yylval.str = strdup(yytext);
		return tNOM ; }
{NOMBRE} { yylval.nb = atoi(yytext) ;
			return tNOMBRE ; }
{CARACTERE} { yylval.str = strdup(yytext);
				return tCARACTERE ; }


