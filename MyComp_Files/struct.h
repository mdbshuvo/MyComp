typedef struct 
{
	double value;
	char type;
}Exp_type;

typedef struct 
{
	Exp_type caseExp;
	double value;
}Is_type;

typedef struct 
{
	char* start;
	int size;
}CString;

typedef struct 
{
	double *startCase;
	double *startValue;
	char type;
	int size;
}ArrayDouble;

// use in code
typedef struct 
{
	int size;
	double* start;
}Array;

typedef struct 
{
	bool ifExec;
	bool shouldChanged;
}IfType;