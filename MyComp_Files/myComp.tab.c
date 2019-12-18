
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C
   
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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.4.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Copy the first part of user declarations.  */

/* Line 189 of yacc.c  */
#line 1 "myComp.y"

	#include <iostream>
	#include <stdlib.h>
	#include <fstream>
	#include <cstring>
	#include <sstream>
	#include "struct.h"

	using namespace std; 

	#define SYM_SIZE 20
	#define MAX_SWITCH_IS_NUM 10

	int yylex();
	int yyerror (char const *s);
	void print_str(CString str, ostream& out);
	void print_exp(Exp_type exp, ostream& out);
	Exp_type biOp(char operation, Exp_type first, Exp_type second);
	Exp_type relOp(char* operation, Exp_type first, Exp_type second);
	void init(char* file);

	ofstream fout;

    double sym[SYM_SIZE];
    char type[SYM_SIZE];
    bool declared[SYM_SIZE];

    Array arrays[SYM_SIZE];
    int nextArrayIndex = 0;

    bool shouldExec = true; 



/* Line 189 of yacc.c  */
#line 108 "myComp.tab.c"

/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif


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

/* Line 214 of yacc.c  */
#line 35 "myComp.y"

	IfType ifType;
	double value;
	char type;
	Exp_type expType;
	Is_type isType;	
	CString stringData;
	ArrayDouble arrayDouble;



/* Line 214 of yacc.c  */
#line 191 "myComp.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 203 "myComp.tab.c"

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
}
#endif

#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
	 || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  6
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   210

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  51
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  28
/* YYNRULES -- Number of rules.  */
#define YYNRULES  67
/* YYNRULES -- Number of states.  */
#define YYNSTATES  153

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   290

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      43,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,    44,     2,     2,     2,     2,
      47,    48,    41,    39,     2,    40,    49,    42,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    50,     2,
      37,    36,    38,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    45,     2,    46,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint8 yyprhs[] =
{
       0,     0,     3,     6,     8,    12,    13,    19,    23,    27,
      30,    32,    34,    36,    38,    40,    42,    44,    45,    49,
      57,    58,    59,    72,    80,    85,    93,    97,   100,   108,
     115,   119,   126,   130,   134,   135,   140,   141,   146,   148,
     150,   151,   156,   157,   162,   164,   166,   170,   177,   179,
     181,   183,   185,   187,   192,   196,   200,   204,   208,   212,
     216,   220,   224,   228,   232,   234,   236,   238
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      52,     0,    -1,    53,    55,    -1,    54,    -1,    54,    43,
      53,    -1,    -1,    44,    44,    23,    24,     8,    -1,    25,
      56,    26,    -1,    57,    43,    56,    -1,    57,    43,    -1,
      58,    -1,    59,    -1,    62,    -1,    68,    -1,    64,    -1,
      69,    -1,    76,    -1,    -1,    78,    24,     3,    -1,    35,
      78,    24,     3,    45,     4,    46,    -1,    -1,    -1,    10,
      47,    77,    60,    48,    43,    56,    61,    11,    43,    56,
      12,    -1,    13,    47,    63,    48,    43,    56,    14,    -1,
       4,    49,    49,     4,    -1,    28,    47,    77,    48,    43,
      65,    29,    -1,    66,    43,    65,    -1,    67,    43,    -1,
      30,    77,    50,    43,     4,    43,    31,    -1,    32,    50,
      43,     4,    43,    33,    -1,     3,    36,    77,    -1,     3,
      45,     4,    46,    36,    77,    -1,    16,    24,    70,    -1,
      17,    24,    73,    -1,    -1,    77,    71,    24,    70,    -1,
      -1,     9,    72,    24,    70,    -1,    77,    -1,     9,    -1,
      -1,    77,    74,    24,    73,    -1,    -1,     9,    75,    24,
      73,    -1,    77,    -1,     9,    -1,    34,    24,     3,    -1,
      34,    24,     3,    45,     4,    46,    -1,     4,    -1,     5,
      -1,     6,    -1,     7,    -1,     3,    -1,     3,    45,     4,
      46,    -1,    77,    39,    77,    -1,    77,    40,    77,    -1,
      77,    41,    77,    -1,    77,    42,    77,    -1,    77,    38,
      77,    -1,    77,    37,    77,    -1,    77,    19,    77,    -1,
      77,    18,    77,    -1,    77,    20,    77,    -1,    47,    77,
      48,    -1,    15,    -1,    21,    -1,    22,    -1,    27,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    65,    65,    67,    68,    70,    71,    73,    75,    76,
      79,    80,    81,    82,    83,    84,    85,    86,    89,   104,
     126,   126,   126,   150,   159,   161,   187,   208,   210,   215,
     227,   244,   267,   268,   270,   270,   272,   272,   274,   276,
     278,   278,   280,   280,   282,   284,   286,   340,   400,   401,
     402,   403,   404,   416,   433,   434,   435,   436,   438,   439,
     440,   441,   442,   444,   448,   449,   450,   451
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "ID", "NUM", "DNUM", "CNUM", "BNUM",
  "HEADER_NAME", "STRING", "IF", "ELSE", "FI", "WHILE", "ELIHW", "INT",
  "PRINT", "PRINT_CON", "LE", "GE", "EQ", "DOUBLE", "CHAR", "INCLUDE",
  "IND", "MAIN", "NIAM", "BOOL", "SWITCH", "HCTIWS", "IS", "SI", "MUST",
  "TSUM", "INPUT", "ARRAY", "'='", "'<'", "'>'", "'+'", "'-'", "'*'",
  "'/'", "'\\n'", "'#'", "'['", "']'", "'('", "')'", "'.'", "':'",
  "$accept", "s", "header_root", "header", "main", "body", "stmt", "dec",
  "cond", "$@1", "$@2", "loop", "loopCond", "switch", "isMustBlock", "is",
  "must", "assgn", "print", "print_exp", "$@3", "$@4", "print_exp_con",
  "$@5", "$@6", "input", "exp", "type", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,    61,    60,    62,    43,
      45,    42,    47,    10,    35,    91,    93,    40,    41,    46,
      58
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    51,    52,    53,    53,    54,    54,    55,    56,    56,
      57,    57,    57,    57,    57,    57,    57,    57,    58,    58,
      60,    61,    59,    62,    63,    64,    65,    65,    66,    67,
      68,    68,    69,    69,    71,    70,    72,    70,    70,    70,
      74,    73,    75,    73,    73,    73,    76,    76,    77,    77,
      77,    77,    77,    77,    77,    77,    77,    77,    77,    77,
      77,    77,    77,    77,    78,    78,    78,    78
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     2,     1,     3,     0,     5,     3,     3,     2,
       1,     1,     1,     1,     1,     1,     1,     0,     3,     7,
       0,     0,    12,     7,     4,     7,     3,     2,     7,     6,
       3,     6,     3,     3,     0,     4,     0,     4,     1,     1,
       0,     4,     0,     4,     1,     1,     3,     6,     1,     1,
       1,     1,     1,     4,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     1,     1,     1,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       5,     0,     0,     0,     3,     0,     1,    17,     2,     5,
       0,     0,     0,     0,    64,     0,     0,    65,    66,    67,
       0,     0,     0,     0,     0,    10,    11,    12,    14,    13,
      15,    16,     0,     4,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     7,     9,     0,     6,    52,    48,
      49,    50,    51,     0,    30,     0,    20,     0,     0,    36,
      32,    34,    42,    33,    40,     0,    46,     0,     8,    18,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    63,    61,    60,    62,    59,    58,    54,
      55,    56,    57,     0,     0,     0,    17,     0,     0,     0,
       0,     0,     0,     0,    53,    31,    17,    24,     0,    37,
      35,    43,    41,     0,     0,     0,     0,     0,    47,     0,
      21,    23,     0,     0,    25,     0,    27,    19,     0,     0,
       0,    26,     0,     0,     0,    17,     0,     0,     0,     0,
      29,    22,    28
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,     4,     8,    23,    24,    25,    26,    82,
     138,    27,    58,    28,   125,   126,   127,    29,    30,    60,
      86,    85,    63,    88,    87,    31,    61,    32
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -59
static const yytype_int16 yypact[] =
{
     -42,   -39,    33,    12,     8,    39,   -59,    93,   -59,   -42,
      41,   -32,    21,    23,   -59,    49,    54,   -59,   -59,   -59,
      35,    59,   177,    37,    44,   -59,   -59,   -59,   -59,   -59,
     -59,   -59,    60,   -59,    80,    25,    86,    25,    89,     5,
      17,    25,    91,    71,   -59,    64,    94,   -59,    56,   -59,
     -59,   -59,   -59,    25,   149,    58,   149,    53,    57,    68,
     -59,   123,    69,   -59,   136,    98,    74,   110,   -59,   -59,
     118,   111,    25,    25,    25,    25,    25,    25,    25,    25,
      25,    87,    76,    77,    82,   108,   109,   120,   121,   104,
     130,   112,   124,   -59,   -24,   -24,   -24,   -24,   -24,     6,
       6,   -59,   -59,    25,   115,   167,    93,     5,     5,    17,
      17,    -5,   126,   176,   -59,   149,    93,   -59,   168,   -59,
     -59,   -59,   -59,    25,   131,   154,   141,   142,   -59,   147,
     -59,   -59,    16,   151,   -59,    -5,   -59,   -59,   184,   153,
     193,   -59,   157,   197,   159,    93,   160,   172,   194,   178,
     -59,   -59,   -59
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -59,   -59,   198,   -59,   -59,   -45,   -59,   -59,   -59,   -59,
     -59,   -59,   -59,   -59,    73,   -59,   -59,   -59,   -59,   -58,
     -59,   -59,   -50,   -59,   -59,   -59,   -34,   188
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -46
static const yytype_int16 yytable[] =
{
      68,    54,     1,    56,    35,     5,    64,    65,    48,    49,
      50,    51,    52,    36,    59,    77,    78,    79,    80,    71,
      48,    49,    50,    51,    52,   123,    62,   124,    48,    49,
      50,    51,    52,     6,    72,    73,    74,     7,    94,    95,
      96,    97,    98,    99,   100,   101,   102,    79,    80,   119,
     120,     9,    53,    75,    76,    77,    78,    79,    80,   121,
     122,   118,    10,    44,    53,    34,   139,    11,    37,   115,
      38,   130,    53,    39,    12,    64,    64,    13,    40,    14,
      15,    16,    41,    42,    46,    17,    18,    45,    47,   132,
      55,    19,    20,    57,    66,    67,    11,    69,    21,    22,
     148,    70,    83,    12,    81,    84,    13,   -17,    14,    15,
      16,   -39,   -45,    91,    17,    18,    72,    73,    74,    90,
      19,    20,    92,   103,   104,   106,   105,    21,    22,    72,
      73,    74,   107,   108,   112,    75,    76,    77,    78,    79,
      80,    72,    73,    74,   109,   110,    89,   111,    75,    76,
      77,    78,    79,    80,    72,    73,    74,   113,   116,    93,
      75,    76,    77,    78,    79,    80,   -38,    72,    73,    74,
     114,   117,   128,    75,    76,    77,    78,    79,    80,   -44,
     129,   133,   131,   134,   135,   136,    75,    76,    77,    78,
      79,    80,    14,   137,   140,   142,   143,   144,    17,    18,
     145,   146,   147,   149,    19,   150,   151,    33,   141,   152,
      43
};

static const yytype_uint8 yycheck[] =
{
      45,    35,    44,    37,    36,    44,    40,    41,     3,     4,
       5,     6,     7,    45,     9,    39,    40,    41,    42,    53,
       3,     4,     5,     6,     7,    30,     9,    32,     3,     4,
       5,     6,     7,     0,    18,    19,    20,    25,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    41,    42,   107,
     108,    43,    47,    37,    38,    39,    40,    41,    42,   109,
     110,   106,    23,    26,    47,    24,    50,     3,    47,   103,
      47,   116,    47,    24,    10,   109,   110,    13,    24,    15,
      16,    17,    47,    24,    24,    21,    22,    43,     8,   123,
       4,    27,    28,     4,     3,    24,     3,     3,    34,    35,
     145,    45,    49,    10,    46,    48,    13,    43,    15,    16,
      17,    43,    43,     3,    21,    22,    18,    19,    20,    45,
      27,    28,     4,    36,    48,    43,    49,    34,    35,    18,
      19,    20,    24,    24,     4,    37,    38,    39,    40,    41,
      42,    18,    19,    20,    24,    24,    48,    43,    37,    38,
      39,    40,    41,    42,    18,    19,    20,    45,    43,    48,
      37,    38,    39,    40,    41,    42,    43,    18,    19,    20,
      46,     4,    46,    37,    38,    39,    40,    41,    42,    43,
       4,    50,    14,    29,    43,    43,    37,    38,    39,    40,
      41,    42,    15,    46,    43,    11,    43,     4,    21,    22,
      43,     4,    43,    43,    27,    33,    12,     9,   135,    31,
      22
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    44,    52,    53,    54,    44,     0,    25,    55,    43,
      23,     3,    10,    13,    15,    16,    17,    21,    22,    27,
      28,    34,    35,    56,    57,    58,    59,    62,    64,    68,
      69,    76,    78,    53,    24,    36,    45,    47,    47,    24,
      24,    47,    24,    78,    26,    43,    24,     8,     3,     4,
       5,     6,     7,    47,    77,     4,    77,     4,    63,     9,
      70,    77,     9,    73,    77,    77,     3,    24,    56,     3,
      45,    77,    18,    19,    20,    37,    38,    39,    40,    41,
      42,    46,    60,    49,    48,    72,    71,    75,    74,    48,
      45,     3,     4,    48,    77,    77,    77,    77,    77,    77,
      77,    77,    77,    36,    48,    49,    43,    24,    24,    24,
      24,    43,     4,    45,    46,    77,    43,     4,    56,    70,
      70,    73,    73,    30,    32,    65,    66,    67,    46,     4,
      56,    14,    77,    50,    29,    43,    43,    46,    61,    50,
      43,    65,    11,    43,     4,    43,     4,    43,    56,    43,
      33,    12,    31
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef	YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif



#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
	switch (*++yyp)
	  {
	  case '\'':
	  case ',':
	    goto do_not_strip_quotes;

	  case '\\':
	    if (*++yyp != '\\')
	      goto do_not_strip_quotes;
	    /* Fall through.  */
	  default:
	    if (yyres)
	      yyres[yyn] = *yyp;
	    yyn++;
	    break;

	  case '"':
	    if (yyres)
	      yyres[yyn] = '\0';
	    return yyn;
	  }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
}
#endif /* YYERROR_VERBOSE */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}

/* Prevent warnings from -Wmissing-prototypes.  */
#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */


/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*-------------------------.
| yyparse or yypush_parse.  |
`-------------------------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{


    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.

       Refer to the stacks thru separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yytoken = 0;
  yyss = yyssa;
  yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */
  yyssp = yyss;
  yyvsp = yyvs;

  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack.  Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	yytype_int16 *yyss1 = yyss;

	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),
		    &yystacksize);

	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
	goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
	yystacksize = YYMAXDEPTH;

      {
	yytype_int16 *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyexhaustedlab;
	YYSTACK_RELOCATE (yyss_alloc, yyss);
	YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yyn == 0 || yyn == YYTABLE_NINF)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  *++yyvsp = yylval;

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 4:

/* Line 1455 of yacc.c  */
#line 68 "myComp.y"
    { fout<<endl; ;}
    break;

  case 6:

/* Line 1455 of yacc.c  */
#line 71 "myComp.y"
    { cout<<"Header "<<(yyvsp[(5) - (5)].stringData).start<<" included"<<endl; ;}
    break;

  case 18:

/* Line 1455 of yacc.c  */
#line 89 "myComp.y"
    {
						if(shouldExec)
							{
								if(declared[(int)(yyvsp[(3) - (3)].value)])
							{
								yyerror("Error : Cannot redeclare variable!\n");
							}
							else
							{
								sym[(int)(yyvsp[(3) - (3)].value)]=0;
								type[(int)(yyvsp[(3) - (3)].value)]=(yyvsp[(1) - (3)].type);
								declared[(int)(yyvsp[(3) - (3)].value)]=true; 
							}
						}
					;}
    break;

  case 19:

/* Line 1455 of yacc.c  */
#line 104 "myComp.y"
    {
											if(shouldExec)
											{
												if(declared[(int)(yyvsp[(4) - (7)].value)])
												{
													yyerror("Error : Cannot redeclare variable!\n");
												}
												else
												{
													sym[(int)(yyvsp[(4) - (7)].value)]=nextArrayIndex;

													type[(int)(yyvsp[(4) - (7)].value)]=(yyvsp[(2) - (7)].type);
													declared[(int)(yyvsp[(4) - (7)].value)]=true;

													arrays[nextArrayIndex].start = new double[(int)(yyvsp[(6) - (7)].value)];
													arrays[nextArrayIndex].size = (int)(yyvsp[(6) - (7)].value);

													nextArrayIndex++;
												}
											}
										;}
    break;

  case 20:

/* Line 1455 of yacc.c  */
#line 126 "myComp.y"
    { if( shouldExec) { if( !(yyvsp[(3) - (3)].expType).value ) { (yyvsp[(1) - (3)].ifType).shouldChanged = true; shouldExec = false; } else { (yyvsp[(1) - (3)].ifType).ifExec = true; } } ;}
    break;

  case 21:

/* Line 1455 of yacc.c  */
#line 126 "myComp.y"
    { if( (yyvsp[(1) - (7)].ifType).shouldChanged && !shouldExec && !(yyvsp[(1) - (7)].ifType).ifExec) { shouldExec = true; (yyvsp[(1) - (7)].ifType).shouldChanged = false; } else if(shouldExec) { shouldExec = false; (yyvsp[(1) - (7)].ifType).shouldChanged = true; } ;}
    break;

  case 22:

/* Line 1455 of yacc.c  */
#line 126 "myComp.y"
    {
					
					if((yyvsp[(1) - (12)].ifType).shouldChanged) shouldExec = true;
					if(shouldExec)
					{
						//if-else implement
						if((yyvsp[(3) - (12)].expType).type != 'b')
						{
							yyerror("Error : Condition must be of type bool");
						}

						// fout<<"if-else invoked"<<endl;
						// if($3.value)
						// {
						// 	fout<<"if block executed"<<endl;
						// }
						// else
						// {
						// 	fout<<"else block executed"<<endl;
						// }
					}
				;}
    break;

  case 23:

/* Line 1455 of yacc.c  */
#line 150 "myComp.y"
    {
							if(shouldExec)
							{
								//loop implement
								cout<<"While loop executed "<<(yyvsp[(3) - (7)].value)<<" times"<<endl;
							}
						;}
    break;

  case 24:

/* Line 1455 of yacc.c  */
#line 159 "myComp.y"
    { (yyval.value) = (yyvsp[(4) - (4)].value) - (yyvsp[(1) - (4)].value); ;}
    break;

  case 25:

/* Line 1455 of yacc.c  */
#line 161 "myComp.y"
    {

										if(shouldExec)
										{
											bool isExecuted = false;

											for(int  i = (yyvsp[(6) - (7)].arrayDouble).size - 1; i > 0; i--)
											{
												if((yyvsp[(6) - (7)].arrayDouble).startCase[i] == (yyvsp[(3) - (7)].expType).value)
												{
													cout<<"The value selected is : "<<(yyvsp[(6) - (7)].arrayDouble).startValue[i]<<endl;
													isExecuted = true;
													break;
												}
											}

											if(!isExecuted)
											{
												cout<<"The value selected is : "<<(yyvsp[(6) - (7)].arrayDouble).startValue[0]<<endl;
											}

											delete((yyvsp[(6) - (7)].arrayDouble).startCase);
											delete((yyvsp[(6) - (7)].arrayDouble).startValue);
										}
									;}
    break;

  case 26:

/* Line 1455 of yacc.c  */
#line 187 "myComp.y"
    {
										if((yyvsp[(1) - (3)].isType).caseExp.type == (yyvsp[(3) - (3)].arrayDouble).type || (yyvsp[(3) - (3)].arrayDouble).type == 'u')
										{
											if((yyvsp[(3) - (3)].arrayDouble).size >= MAX_SWITCH_IS_NUM)
											{
												yyerror("Error : Switch cannot be that long!");
											}

											(yyval.arrayDouble).startCase = (yyvsp[(3) - (3)].arrayDouble).startCase;
											(yyval.arrayDouble).startValue = (yyvsp[(3) - (3)].arrayDouble).startValue;
											(yyval.arrayDouble).size = (yyvsp[(3) - (3)].arrayDouble).size;
											(yyval.arrayDouble).type = (yyvsp[(1) - (3)].isType).caseExp.type;
											(yyval.arrayDouble).startCase[(yyval.arrayDouble).size] = (yyvsp[(1) - (3)].isType).caseExp.value;
											(yyval.arrayDouble).startValue[(yyval.arrayDouble).size] = (yyvsp[(1) - (3)].isType).value;
											(yyval.arrayDouble).size++;
										}
										else
										{
											yyerror("Error : Type mismatch in switch!");
										}
									;}
    break;

  case 27:

/* Line 1455 of yacc.c  */
#line 208 "myComp.y"
    { (yyval.arrayDouble) = (yyvsp[(1) - (2)].arrayDouble); ;}
    break;

  case 28:

/* Line 1455 of yacc.c  */
#line 210 "myComp.y"
    {
									(yyval.isType).caseExp = (yyvsp[(2) - (7)].expType);
									(yyval.isType).value = (yyvsp[(5) - (7)].value);
								;}
    break;

  case 29:

/* Line 1455 of yacc.c  */
#line 215 "myComp.y"
    {
									double * arrayCase = new double[MAX_SWITCH_IS_NUM];
									double * arrayValue = new double[MAX_SWITCH_IS_NUM];
									arrayCase[0] = 0;
									arrayValue[0] = (yyvsp[(4) - (6)].value);

									(yyval.arrayDouble).type = 'u';
									(yyval.arrayDouble).startCase = arrayCase; 
									(yyval.arrayDouble).startValue = arrayValue; 
									(yyval.arrayDouble).size = 1;
								;}
    break;

  case 30:

/* Line 1455 of yacc.c  */
#line 227 "myComp.y"
    {
						if(shouldExec)
						{
							if(!declared[(int)(yyvsp[(1) - (3)].value)])
							{
								yyerror("Error : varible undeclared use!\n");
							} 
							else if(type[(int)(yyvsp[(1) - (3)].value)] != (yyvsp[(3) - (3)].expType).type)
							{
								yyerror("Error : type mismatch!\n");
							}
							else
							{
								sym[(int)(yyvsp[(1) - (3)].value)]=(yyvsp[(3) - (3)].expType).value;
							}
						}
					;}
    break;

  case 31:

/* Line 1455 of yacc.c  */
#line 244 "myComp.y"
    {
									if(shouldExec)
									{
										if(!declared[(int)(yyvsp[(1) - (6)].value)])
										{
											yyerror("Error : varible undeclared use!\n");
										} 
										else if(type[(int)(yyvsp[(1) - (6)].value)] != (yyvsp[(6) - (6)].expType).type)
										{
											yyerror("Error : type mismatch!\n");
										}
										else
										{
											int arrIndex = sym[(int)(yyvsp[(1) - (6)].value)];

											if((int)(yyvsp[(3) - (6)].value) >= arrays[arrIndex].size) yyerror("Array index out of bound!!");

											arrays[arrIndex].start[(int)(yyvsp[(3) - (6)].value)] = (yyvsp[(6) - (6)].expType).value; 
										}
									}
								;}
    break;

  case 34:

/* Line 1455 of yacc.c  */
#line 270 "myComp.y"
    { if(shouldExec) print_exp((yyvsp[(1) - (1)].expType),fout); ;}
    break;

  case 36:

/* Line 1455 of yacc.c  */
#line 272 "myComp.y"
    { if(shouldExec) print_str((yyvsp[(1) - (1)].stringData),fout); ;}
    break;

  case 38:

/* Line 1455 of yacc.c  */
#line 274 "myComp.y"
    { if(shouldExec) print_exp((yyvsp[(1) - (1)].expType),fout); ;}
    break;

  case 39:

/* Line 1455 of yacc.c  */
#line 276 "myComp.y"
    { if(shouldExec) print_str((yyvsp[(1) - (1)].stringData),fout); ;}
    break;

  case 40:

/* Line 1455 of yacc.c  */
#line 278 "myComp.y"
    { if(shouldExec) print_exp((yyvsp[(1) - (1)].expType),cout); ;}
    break;

  case 42:

/* Line 1455 of yacc.c  */
#line 280 "myComp.y"
    { if(shouldExec) print_str((yyvsp[(1) - (1)].stringData),cout); ;}
    break;

  case 44:

/* Line 1455 of yacc.c  */
#line 282 "myComp.y"
    { if(shouldExec) print_exp((yyvsp[(1) - (1)].expType),cout); ;}
    break;

  case 45:

/* Line 1455 of yacc.c  */
#line 284 "myComp.y"
    { if(shouldExec) print_str((yyvsp[(1) - (1)].stringData),cout); ;}
    break;

  case 46:

/* Line 1455 of yacc.c  */
#line 286 "myComp.y"
    {
						if(shouldExec)
						{
							if(!declared[(int)(yyvsp[(3) - (3)].value)])
							{
								yyerror("Error : variable undeclared use!");
							}

							string input;
							cin>>input;

							stringstream sin(input);

							char inputType;

							if( input[0]>='0' && input[0]<='9' )
							{
								if(input.find('.') != string::npos)
								{
									inputType = 'd';
								}
								else
								{
									inputType = 'i';
								}
							}
							else
							{
								inputType = 'c';
							}

							if( type[(int)(yyvsp[(3) - (3)].value)] == inputType )
							{
								if( inputType == 'c' )
								{
									char character;
									sin>>character;

									sym[(int)(yyvsp[(3) - (3)].value)] = character;
								}
								else
								{
									double number;
									sin>>number;

									sym[(int)(yyvsp[(3) - (3)].value)] = number;
								}
							}
							else
							{
								yyerror("Error : type mismatch!");
							}
						}
					;}
    break;

  case 47:

/* Line 1455 of yacc.c  */
#line 340 "myComp.y"
    {

						if(shouldExec)
						{
							if(!declared[(int)(yyvsp[(3) - (6)].value)])
							{
								yyerror("Error : variable undeclared use!");
							}

							string input;
							cin>>input;

							stringstream sin(input);

							char inputType;

							if( input[0]>='0' && input[0]<='9' )
							{
								if(input.find('.') != string::npos)
								{
									inputType = 'd';
								}
								else
								{
									inputType = 'i';
								}
							}
							else
							{
								inputType = 'c';
							}

							int arrIndex = sym[(int)(yyvsp[(3) - (6)].value)];
							if((int)(yyvsp[(5) - (6)].value) >= arrays[arrIndex].size) yyerror("Array index out of bound!!");

							if( type[(int)(yyvsp[(3) - (6)].value)] == inputType )
							{
								if( inputType == 'c' )
								{
									char character;
									sin>>character;

									arrays[arrIndex].start[(int)(yyvsp[(5) - (6)].value)] = character; 
								}
								else
								{
									double number;
									sin>>number;

									arrays[arrIndex].start[(int)(yyvsp[(5) - (6)].value)] = number; 
								}
							}
							else
							{
								yyerror("Error : type mismatch!");
							}
						}
					;}
    break;

  case 48:

/* Line 1455 of yacc.c  */
#line 400 "myComp.y"
    { (yyval.expType).value = (yyvsp[(1) - (1)].value); (yyval.expType).type = 'i' ;}
    break;

  case 49:

/* Line 1455 of yacc.c  */
#line 401 "myComp.y"
    { (yyval.expType).value = (yyvsp[(1) - (1)].value); (yyval.expType).type = 'd' ;}
    break;

  case 50:

/* Line 1455 of yacc.c  */
#line 402 "myComp.y"
    { (yyval.expType).value = (yyvsp[(1) - (1)].value); (yyval.expType).type = 'c' ;}
    break;

  case 51:

/* Line 1455 of yacc.c  */
#line 403 "myComp.y"
    { (yyval.expType).value = (yyvsp[(1) - (1)].value); (yyval.expType).type = 'b' ;}
    break;

  case 52:

/* Line 1455 of yacc.c  */
#line 404 "myComp.y"
    {
						if(!declared[(int)(yyvsp[(1) - (1)].value)])
						{
							fout<<"Error : varible undeclared use!"<<endl;
						}
						else
						{
							(yyval.expType).value=sym[(int)(yyvsp[(1) - (1)].value)];
							(yyval.expType).type=type[(int)(yyvsp[(1) - (1)].value)];
						}
					;}
    break;

  case 53:

/* Line 1455 of yacc.c  */
#line 416 "myComp.y"
    {
							if(!declared[(int)(yyvsp[(1) - (4)].value)])
							{
								fout<<"Error : varible undeclared use!"<<endl;
							}
							else
							{
								(yyval.expType).type=type[(int)(yyvsp[(1) - (4)].value)];

								int arrIndex = sym[(int)(yyvsp[(1) - (4)].value)];

								if((int)(yyvsp[(3) - (4)].value) >= arrays[arrIndex].size) yyerror("Array index out of bound!!");

								(yyval.expType).value = arrays[arrIndex].start[(int)(yyvsp[(3) - (4)].value)]; 
							}
						;}
    break;

  case 54:

/* Line 1455 of yacc.c  */
#line 433 "myComp.y"
    { (yyval.expType) = biOp('+', (yyvsp[(1) - (3)].expType), (yyvsp[(3) - (3)].expType)); ;}
    break;

  case 55:

/* Line 1455 of yacc.c  */
#line 434 "myComp.y"
    { (yyval.expType) = biOp('-', (yyvsp[(1) - (3)].expType), (yyvsp[(3) - (3)].expType)); ;}
    break;

  case 56:

/* Line 1455 of yacc.c  */
#line 435 "myComp.y"
    { (yyval.expType) = biOp('*', (yyvsp[(1) - (3)].expType), (yyvsp[(3) - (3)].expType)); ;}
    break;

  case 57:

/* Line 1455 of yacc.c  */
#line 436 "myComp.y"
    { (yyval.expType) = biOp('/', (yyvsp[(1) - (3)].expType), (yyvsp[(3) - (3)].expType)); ;}
    break;

  case 58:

/* Line 1455 of yacc.c  */
#line 438 "myComp.y"
    { (yyval.expType) = relOp(">", (yyvsp[(1) - (3)].expType), (yyvsp[(3) - (3)].expType)); ;}
    break;

  case 59:

/* Line 1455 of yacc.c  */
#line 439 "myComp.y"
    { (yyval.expType) = relOp("<", (yyvsp[(1) - (3)].expType), (yyvsp[(3) - (3)].expType)); ;}
    break;

  case 60:

/* Line 1455 of yacc.c  */
#line 440 "myComp.y"
    { (yyval.expType) = relOp(">=", (yyvsp[(1) - (3)].expType), (yyvsp[(3) - (3)].expType)); ;}
    break;

  case 61:

/* Line 1455 of yacc.c  */
#line 441 "myComp.y"
    { (yyval.expType) = relOp("<=", (yyvsp[(1) - (3)].expType), (yyvsp[(3) - (3)].expType)); ;}
    break;

  case 62:

/* Line 1455 of yacc.c  */
#line 442 "myComp.y"
    { (yyval.expType) = relOp("==", (yyvsp[(1) - (3)].expType), (yyvsp[(3) - (3)].expType)); ;}
    break;

  case 63:

/* Line 1455 of yacc.c  */
#line 444 "myComp.y"
    { (yyval.expType) = (yyvsp[(2) - (3)].expType); ;}
    break;

  case 64:

/* Line 1455 of yacc.c  */
#line 448 "myComp.y"
    { (yyval.type) = 'i'; ;}
    break;

  case 65:

/* Line 1455 of yacc.c  */
#line 449 "myComp.y"
    { (yyval.type) = 'd'; ;}
    break;

  case 66:

/* Line 1455 of yacc.c  */
#line 450 "myComp.y"
    { (yyval.type) = 'c'; ;}
    break;

  case 67:

/* Line 1455 of yacc.c  */
#line 451 "myComp.y"
    { (yyval.type) = 'b'; ;}
    break;



/* Line 1455 of yacc.c  */
#line 2146 "myComp.tab.c"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
	 error, discard it.  */

      if (yychar <= YYEOF)
	{
	  /* Return failure if at end of input.  */
	  if (yychar == YYEOF)
	    YYABORT;
	}
      else
	{
	  yydestruct ("Error: discarding",
		      yytoken, &yylval);
	  yychar = YYEMPTY;
	}
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule which action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
	{
	  yyn += YYTERROR;
	  if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
	    {
	      yyn = yytable[yyn];
	      if (0 < yyn)
		break;
	    }
	}

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
	YYABORT;


      yydestruct ("Error: popping",
		  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  *++yyvsp = yylval;


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined(yyoverflow) || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}



/* Line 1675 of yacc.c  */
#line 454 "myComp.y"



//------------------------- main function begins -----------------------------------

int main(int argc,char* argv[])
{
	for(int i=0;i<SYM_SIZE;i++)
	{
		declared[i] = false;
	}

	if(argc == 1) yyerror("Error : Too few arguments !");

	// input file
	init(argv[1]);

	// output file
	char* fileout = strcat(argv[1],".out");
	fout.open(fileout);

	yyparse();
	return 0;
}

int yyerror (char const *s)
{
	cout<<s<<"!";
	exit(0);
}

//---------------------------- auxilary functions ---------------------------------

void print_str(CString str, ostream& out)
{
	for( int i = 1; i < str.size - 1 ; i++ )
	{
		if(str.start[i] == '\\')
		{
			if(str.start[i+1] == 'n')
			{
				out<<'\n';
			}
			else if(str.start[i+1] == 'r')
			{
				out<<'\r';
			}
			else if(str.start[i+1] == 't')
			{
				out<<'\t';
			}
			else if(str.start[i+1] == '\\')
			{
				out<<'\\';
			}
			else
			{
				yyerror("Error : unknown escape character!");
			}
			i++;
			continue;
		}
		out<<str.start[i];
	}

	delete(str.start); 
}

void print_exp(Exp_type exp, ostream& out)
{
	if(exp.type == 'i')
	{
		out<<(int)exp.value;
	}
	else if(exp.type == 'c')
	{
		out<<(char)exp.value;
	}
	else
	{
		out<<exp.value;
	}
}


Exp_type biOp(char operation, Exp_type first,Exp_type second) 
{
	Exp_type result;

	if(first.type != second.type)
	{
		yyerror("Error : operands type didnot match!!");
	}
	else if(first.type == 'c')
	{
		yyerror("Error : This operation can't be done on characters!!");
	}
	else if(first.type == 'b')
	{
		yyerror("Error : This operation can't be done on booleans!!");
	}
	else
	{
		if(operation == '+')
		{
			result.value = first.value + second.value;
		}
		else if(operation == '-')
		{
			result.value = first.value - second.value;
		}
		else if(operation == '*')
		{
			result.value = first.value * second.value;
		}
		else if(operation == '/')
		{
			if(second.value == 0) yyerror("Cannot divide by zero!!");
			result.value = first.value / second.value;
		}
		
		result.type = first.type; 
	}

	return result;
}

Exp_type relOp(char* operation, Exp_type first, Exp_type second)
{
	Exp_type result;

	if(first.type != second.type)
	{
		yyerror("Error : operands type didnot match!!");
	}
	else
	{
		if(strcmp(operation,">"))
		{
			result.value = first.value < second.value;						//eikhane jhamela ase		
		}
		else if(strcmp(operation,"<"))
		{
			result.value = first.value > second.value;						//eikhane jhamela ase
		}
		else if(strcmp(operation,">="))
		{
			result.value = first.value >= second.value;
		}
		else if(strcmp(operation,"<="))
		{
			result.value = first.value <= second.value;
		}
		else if(strcmp(operation,"=="))
		{
			result.value = first.value == second.value;
		}

		result.type = 'b'; 
	}

	return result;
}

