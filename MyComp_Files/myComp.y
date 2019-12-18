%{
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

%}

%union {
	IfType ifType;
	double value;
	char type;
	Exp_type expType;
	Is_type isType;	
	CString stringData;
	ArrayDouble arrayDouble;
};

%token <value> ID NUM DNUM CNUM BNUM
%token <stringData> HEADER_NAME STRING

%token <ifType> IF
%token  ELSE FI WHILE ELIHW INT PRINT PRINT_CON LE GE EQ DOUBLE CHAR INCLUDE IND MAIN NIAM BOOL SWITCH HCTIWS IS SI MUST TSUM INPUT ARRAY
%right '='
%left '<' '>' LE GE EQ
%left '+' '-'
%left '*' '/'

%type <isType> is
%type <expType> exp
%type <type> type
%type <value> loopCond
%type <arrayDouble> isMustBlock must

%start s

%%

s: header_root main

header_root: header
	| header '\n' header_root				{ fout<<endl; }

header: /* empty string */
	| '#' '#' INCLUDE IND HEADER_NAME		{ cout<<"Header "<<$5.start<<" included"<<endl; }

main: MAIN body NIAM

body:	stmt '\n' body
	| stmt '\n'
	;

stmt:	dec
	| cond
	| loop
	| assgn
	| switch
	| print	
	| input
	|	/* empty line */
	;

dec:	type IND ID	{
						if(shouldExec)
							{
								if(declared[(int)$3])
							{
								yyerror("Error : Cannot redeclare variable!\n");
							}
							else
							{
								sym[(int)$3]=0;
								type[(int)$3]=$1;
								declared[(int)$3]=true; 
							}
						}
					}
	| ARRAY type IND ID '[' NUM ']' 	{
											if(shouldExec)
											{
												if(declared[(int)$4])
												{
													yyerror("Error : Cannot redeclare variable!\n");
												}
												else
												{
													sym[(int)$4]=nextArrayIndex;

													type[(int)$4]=$2;
													declared[(int)$4]=true;

													arrays[nextArrayIndex].start = new double[(int)$6];
													arrays[nextArrayIndex].size = (int)$6;

													nextArrayIndex++;
												}
											}
										}

cond: IF '(' exp { if( shouldExec) { if( !$3.value ) { $1.shouldChanged = true; shouldExec = false; } else { $1.ifExec = true; } } } ')' '\n' body { if( $1.shouldChanged && !shouldExec && !$1.ifExec) { shouldExec = true; $1.shouldChanged = false; } else if(shouldExec) { shouldExec = false; $1.shouldChanged = true; } } ELSE '\n' body FI 	{
					
					if($1.shouldChanged) shouldExec = true;
					if(shouldExec)
					{
						//if-else implement
						if($3.type != 'b')
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
				}
	;

loop:	WHILE '(' loopCond ')' '\n' body ELIHW	{
							if(shouldExec)
							{
								//loop implement
								cout<<"While loop executed "<<$3<<" times"<<endl;
							}
						}
	;

loopCond: NUM '.' '.' NUM	{ $$ = $4 - $1; }

switch: SWITCH '(' exp ')' '\n' isMustBlock HCTIWS {

										if(shouldExec)
										{
											bool isExecuted = false;

											for(int  i = $6.size - 1; i > 0; i--)
											{
												if($6.startCase[i] == $3.value)
												{
													cout<<"The value selected is : "<<$6.startValue[i]<<endl;
													isExecuted = true;
													break;
												}
											}

											if(!isExecuted)
											{
												cout<<"The value selected is : "<<$6.startValue[0]<<endl;
											}

											delete($6.startCase);
											delete($6.startValue);
										}
									}

isMustBlock: is '\n' isMustBlock	{
										if($1.caseExp.type == $3.type || $3.type == 'u')
										{
											if($3.size >= MAX_SWITCH_IS_NUM)
											{
												yyerror("Error : Switch cannot be that long!");
											}

											$$.startCase = $3.startCase;
											$$.startValue = $3.startValue;
											$$.size = $3.size;
											$$.type = $1.caseExp.type;
											$$.startCase[$$.size] = $1.caseExp.value;
											$$.startValue[$$.size] = $1.value;
											$$.size++;
										}
										else
										{
											yyerror("Error : Type mismatch in switch!");
										}
									}
	| must '\n'		{ $$ = $1; }

is: IS exp ':' '\n' NUM '\n' SI 		{
									$$.caseExp = $2;
									$$.value = $5;
								}

must: MUST ':' '\n' NUM '\n' TSUM	{
									double * arrayCase = new double[MAX_SWITCH_IS_NUM];
									double * arrayValue = new double[MAX_SWITCH_IS_NUM];
									arrayCase[0] = 0;
									arrayValue[0] = $4;

									$$.type = 'u';
									$$.startCase = arrayCase; 
									$$.startValue = arrayValue; 
									$$.size = 1;
								}

assgn:	ID '=' exp	{
						if(shouldExec)
						{
							if(!declared[(int)$1])
							{
								yyerror("Error : varible undeclared use!\n");
							} 
							else if(type[(int)$1] != $3.type)
							{
								yyerror("Error : type mismatch!\n");
							}
							else
							{
								sym[(int)$1]=$3.value;
							}
						}
					}
	| ID '[' NUM ']' '=' exp	{
									if(shouldExec)
									{
										if(!declared[(int)$1])
										{
											yyerror("Error : varible undeclared use!\n");
										} 
										else if(type[(int)$1] != $6.type)
										{
											yyerror("Error : type mismatch!\n");
										}
										else
										{
											int arrIndex = sym[(int)$1];

											if((int)$3 >= arrays[arrIndex].size) yyerror("Array index out of bound!!");

											arrays[arrIndex].start[(int)$3] = $6.value; 
										}
									}
								}
	;

print: PRINT IND print_exp
	| PRINT_CON IND print_exp_con 

print_exp: 	exp { if(shouldExec) print_exp($1,fout); } IND print_exp 		

	| STRING { if(shouldExec) print_str($1,fout); } IND print_exp			

	| exp	{ if(shouldExec) print_exp($1,fout); }

	| STRING 	{ if(shouldExec) print_str($1,fout); }

print_exp_con: 	exp  { if(shouldExec) print_exp($1,cout); } IND print_exp_con 		

	| STRING { if(shouldExec) print_str($1,cout); } IND print_exp_con			

	| exp	{ if(shouldExec) print_exp($1,cout); }

	| STRING 	{ if(shouldExec) print_str($1,cout); }

input: INPUT IND ID {
						if(shouldExec)
						{
							if(!declared[(int)$3])
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

							if( type[(int)$3] == inputType )
							{
								if( inputType == 'c' )
								{
									char character;
									sin>>character;

									sym[(int)$3] = character;
								}
								else
								{
									double number;
									sin>>number;

									sym[(int)$3] = number;
								}
							}
							else
							{
								yyerror("Error : type mismatch!");
							}
						}
					}
	| INPUT IND ID '[' NUM ']' {

						if(shouldExec)
						{
							if(!declared[(int)$3])
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

							int arrIndex = sym[(int)$3];
							if((int)$5 >= arrays[arrIndex].size) yyerror("Array index out of bound!!");

							if( type[(int)$3] == inputType )
							{
								if( inputType == 'c' )
								{
									char character;
									sin>>character;

									arrays[arrIndex].start[(int)$5] = character; 
								}
								else
								{
									double number;
									sin>>number;

									arrays[arrIndex].start[(int)$5] = number; 
								}
							}
							else
							{
								yyerror("Error : type mismatch!");
							}
						}
					}


exp:	NUM 		{ $$.value = $1; $$.type = 'i' }
	| DNUM			{ $$.value = $1; $$.type = 'd' }
	| CNUM 			{ $$.value = $1; $$.type = 'c' }
	| BNUM 			{ $$.value = $1; $$.type = 'b' }
	| ID 			{
						if(!declared[(int)$1])
						{
							fout<<"Error : varible undeclared use!"<<endl;
						}
						else
						{
							$$.value=sym[(int)$1];
							$$.type=type[(int)$1];
						}
					}

	| ID '[' NUM ']'	{
							if(!declared[(int)$1])
							{
								fout<<"Error : varible undeclared use!"<<endl;
							}
							else
							{
								$$.type=type[(int)$1];

								int arrIndex = sym[(int)$1];

								if((int)$3 >= arrays[arrIndex].size) yyerror("Array index out of bound!!");

								$$.value = arrays[arrIndex].start[(int)$3]; 
							}
						}

	| exp '+' exp	{ $$ = biOp('+', $1, $3); }
	| exp '-' exp	{ $$ = biOp('-', $1, $3); }
	| exp '*' exp	{ $$ = biOp('*', $1, $3); }
	| exp '/' exp	{ $$ = biOp('/', $1, $3); }

	| exp '>' exp	{ $$ = relOp(">", $1, $3); }
	| exp '<' exp	{ $$ = relOp("<", $1, $3); }
	| exp GE exp	{ $$ = relOp(">=", $1, $3); }
	| exp LE exp	{ $$ = relOp("<=", $1, $3); }
	| exp EQ exp	{ $$ = relOp("==", $1, $3); }

	| '(' exp ')'	{ $$ = $2; }
	;


type:	INT 	{ $$ = 'i'; }
	|	DOUBLE	{ $$ = 'd'; }
	|	CHAR	{ $$ = 'c'; }
	|	BOOL	{ $$ = 'b'; }
	;

%%


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
