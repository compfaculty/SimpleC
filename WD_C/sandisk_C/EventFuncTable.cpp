#include <stdio.h>

void f1(int n)
{
	printf("param val = %d\n", n);
}

void f2(int n)
{
	printf("param val * 2 = %d\n", n*2);
}

void f3(int n)
{
	printf("param val * 3 = %d\n", n*3);
}

void f4(int n)
{
	printf("param val * 4 = %d\n", n*4);
}

void f5(int n)
{
	printf("param val * 5 = %d\n", n*5);
}

void f6(int n)
{
	printf("param val * 6= %d\n", n*6);
}

void newFunc(int n)
{
	printf("in NEW func, val = %d\n", n);
}

typedef void (*VoidIntFunc_t)(int);

VoidIntFunc_t changeEvent(VoidIntFunc_t arr[], int size, int position, VoidIntFunc_t newFunc)
{
	if(position >=1 && position <= size)
	{
		VoidIntFunc_t tmpFunc = arr[position - 1];
		arr[position - 1] = newFunc;
		return tmpFunc;
	}
	return NULL;
}

void executeEvent(VoidIntFunc_t arr[], int size, int position, int funcVal)
{
	if(position >=1 && position <= size)
	{
		arr[position - 1](funcVal);
	}
	else
	{
		//error!!!
	}
}

void main5()
{
	//void (*p[6])(int);
	VoidIntFunc_t arr[] = {f1,f2,f3,f4,f5,f6};
	int size = 6;
	VoidIntFunc_t oldFunc = changeEvent(arr, size, 3, newFunc);
	executeEvent(arr, size, 3, 101);
	oldFunc = changeEvent(arr, size, 3, oldFunc);
	executeEvent(arr, size, 3, 101);

	getchar();
}