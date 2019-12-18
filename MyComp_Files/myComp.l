%{
	#include <iostream>
	#include <stdlib.h>
	#include <map>
	#include <fstream>
	#include <cstring>

	using namespace std;

	#include "struct.h"
	#include "myComp.tab.h"
	extern YYSTYPE yylval;

	ofstream lexout("lexout.txt");
	int yyerror (char const *s);
	int nextIndex = 1;
	map<string,int> indexMap;
%}

NUM [0-9]+
DNUM {NUM}[.]{NUM}
CNUM ['].[']
BNUM "true"|"false"
STRING ["][^"\n]*["]
ID [_a-zA-Z][_a-zA-Z0-9]*
HEADER_NAME [_a-zA-Z][_a-zA-Z0-9]*[.]"h"
LINE .*[\n]
SINGLE_LINE_COMMENT [/][/]{LINE}
MULTI_LINE_COMMENT [/][*](([*]+[^/*])|[^*])*[*]+[/]

%%

if		{lexout<<yytext<<endl;return(IF);}
else	{lexout<<yytext<<endl;return(ELSE);}
fi		{lexout<<yytext<<endl;return(FI);}
while	{lexout<<yytext<<endl;return(WHILE);}
elihw	{lexout<<yytext<<endl;return(ELIHW);}
switch	{lexout<<yytext<<endl;return(SWITCH);}
hctiws	{lexout<<yytext<<endl;return(HCTIWS);}
is		{lexout<<yytext<<endl;return(IS);}
si		{lexout<<yytext<<endl;return(SI);}
must	{lexout<<yytext<<endl;return(MUST);}
tsum	{lexout<<yytext<<endl;return(TSUM);}
print 	{lexout<<yytext<<endl;return(PRINT);}
printCon 	{lexout<<yytext<<endl;return(PRINT_CON);}
int		{lexout<<yytext<<endl;return(INT);}
double	{lexout<<yytext<<endl;return(DOUBLE);}
char	{lexout<<yytext<<endl;return(CHAR);}
bool 	{lexout<<yytext<<endl;return(BOOL);}	
include {lexout<<yytext<<endl;return(INCLUDE);}
main 	{lexout<<yytext<<endl;return(MAIN);}
niam 	{lexout<<yytext<<endl;return(NIAM);}
input 	{lexout<<yytext<<endl;return(INPUT);}
array 	{lexout<<yytext<<endl;return(ARRAY);}
true 	{lexout<<yytext<<endl; yylval.value = 1; return(BNUM); }
false 	{lexout<<yytext<<endl; yylval.value = 0; return(BNUM); }

{STRING} 	{ 
				lexout<<yytext<<endl;
				//cout<<yytext<<endl;
				yylval.stringData.start = yytext;
				yylval.stringData.size = yyleng;
				return(STRING); 
			}

{HEADER_NAME} 	{
					lexout<<yytext<<endl;
					yylval.stringData.start = yytext;
					yylval.stringData.size = yyleng;
					return(HEADER_NAME);
				}

{NUM}	{
			lexout<<yytext<<endl;
			yylval.value = atoi(yytext);
			return(NUM);
		}
		
{DNUM}	{
			lexout<<yytext<<endl;
			yylval.value = atof(yytext);
			return(DNUM);
		}		

{CNUM}	{
			lexout<<yytext<<endl;
			yylval.value = yytext[1];
			return(CNUM);
		}

{ID}	{
			lexout<<yytext<<endl;
			int index = indexMap[yytext];
			//cout<<"id "<<yytext<<" has index "<<index<<endl;

			if(index == 0)
			{
				index = nextIndex;
				indexMap[yytext]=index;
				nextIndex++;
			}

			yylval.value = index;
			return(ID);
		}

"->"	{lexout<<yytext<<endl;return(IND);}
"<="	{lexout<<yytext<<endl;return(LE);}
">="	{lexout<<yytext<<endl;return(GE);}
"=="	{lexout<<yytext<<endl;return(EQ);}

[-+=/*()\n<>.#:]	{lexout<<yytext<<endl;return *yytext;}
"["					{lexout<<yytext<<endl;return *yytext;}
"]"					{lexout<<yytext<<endl;return *yytext;}

{SINGLE_LINE_COMMENT}	{lexout<<yytext<<endl;}
{MULTI_LINE_COMMENT}	{lexout<<yytext<<endl;}
[ \t]	

.	{lexout<<yytext<<endl;cout<<"not recognized symbol : "<<yytext<<endl;}


%%


void init(char* file)
{
	yyin = fopen(file,"r");
}

int yywrap() 
{
	return 1;
}
