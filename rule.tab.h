/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

#ifndef YY_YY_RULE_TAB_H_INCLUDED
# define YY_YY_RULE_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    tVIRGULE = 258,
    tFIN_INSTRUCTION = 259,
    tPRINTF = 260,
    tACCOLADE_OUVRANTE = 261,
    tACCOLADE_FERMANTE = 262,
    tPLUS = 263,
    tMOINS = 264,
    tFOIS = 265,
    tDIVISE = 266,
    tEGAL = 267,
    tPARENTHESE_OUVRANTE = 268,
    tPARENTHESE_FERMANTE = 269,
    tCONST = 270,
    tNOM = 271,
    tNOMBRE = 272,
    tTYPE = 273,
    tINT = 274,
    tCHAR = 275,
    tVOID = 276,
    tCARACTERE = 277,
    tNULL = 278,
    tWHILE = 279,
    tGUILLEMET = 280,
    tIF = 281,
    tELSE = 282,
    tDOUBLE_EGAL = 283,
    tDIFFERENT = 284,
    tINFERIEUR = 285,
    tINFERIEUR_EGAL = 286,
    tSUPERIEUR = 287,
    tSUPERIEUR_EGAL = 288,
    tPOINT_EXCLAM = 289,
    tTRUC = 290
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 12 "rule.y" /* yacc.c:1909  */

	int nb;
	char* str;

#line 95 "rule.tab.h" /* yacc.c:1909  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_RULE_TAB_H_INCLUDED  */
