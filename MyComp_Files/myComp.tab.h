
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton interface for Bison's Yacc-like parsers in C
   
      Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.
   
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


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     ID = 258,
     NUM = 259,
     DNUM = 260,
     CNUM = 261,
     BNUM = 262,
     HEADER_NAME = 263,
     STRING = 264,
     IF = 265,
     ELSE = 266,
     FI = 267,
     WHILE = 268,
     ELIHW = 269,
     INT = 270,
     PRINT = 271,
     PRINT_CON = 272,
     LE = 273,
     GE = 274,
     EQ = 275,
     DOUBLE = 276,
     CHAR = 277,
     INCLUDE = 278,
     IND = 279,
     MAIN = 280,
     NIAM = 281,
     BOOL = 282,
     SWITCH = 283,
     HCTIWS = 284,
     IS = 285,
     SI = 286,
     MUST = 287,
     TSUM = 288,
     INPUT = 289,
     ARRAY = 290
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 1676 of yacc.c  */
#line 35 "myComp.y"

	IfType ifType;
	double value;
	char type;
	Exp_type expType;
	Is_type isType;	
	CString stringData;
	ArrayDouble arrayDouble;



/* Line 1676 of yacc.c  */
#line 99 "myComp.tab.h"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;


