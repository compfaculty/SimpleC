#include <stdio.h>
#include <math.h>
#include <float.h>

int add(int a, int b)
{
	return a+b;
}

int mult(int a, int b)
{
	return a*b;
}

void testCalc();
double calc1(int num);
double calc2(int num);
double calc3(int num);
double calc4(int num);

typedef struct
{
	double (*func)(int);
	char name[15];
}FuncInfo;

typedef double (*DblIntFunc_t)(int); 
// DblIntFunc_t is type for function pointer with prototype of double xxx(int num);

void main4()
{
	FuncInfo funcArr[] = {{calc1, "calc1"}, {calc2, "calc2"}, 
				{calc3, "calc3"}, {calc4, "calc4"}};
	int i, size = sizeof(funcArr)/sizeof(funcArr[0]);
	for(i = 0; i< size; i++)
	{
		testCalc(funcArr[i].func, funcArr[i].name);
	}
	getchar();

}

double calc1(int num)
{
	float absVal = abs((float)num);
	return sqrt((float)absVal*2);
}

double calc2(int num)
{
	return tan((float)num);
}

double calc3(int num)
{
	return sin((float)num);
}

double calc4(int num)
{
	return exp((float)num);
}

void testCalc(double (*func)(int), char* funcName)
{
	int i;
	int res;
	int minI = 0, maxI = 0;
	double maxRes = DBL_MIN, minRes = DBL_MAX;
	
	for(i = -15; i<=15; i++)
	{
		res = func(i);
		if(res < minRes)
		{
			minI = i;
			minRes = res;
		}
		if(res > maxRes)
		{
			maxI = i;
			maxRes = res;
		}
	}
	printf("------------ %s --------------\n", funcName);
	printf("max res is %lf in param = %d\n", maxRes, maxI);
	printf("min res is %lf in param = %d\n", minRes, minI);
}


