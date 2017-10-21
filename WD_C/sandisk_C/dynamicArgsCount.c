#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <assert.h>


int add(int count, ...)
{
	int i, sum  = 0;
	va_list ap;
	va_start(ap, count);
	for(i  = 1; i<= count; i++)
	{
		sum += va_arg(ap, int);
		
	}
	va_end(ap);
	return sum;
}

void count(int* positiveCntPtr, int* negativeCntPtr,...)
{
	double val;
	va_list ap;
	*positiveCntPtr = 0;
	*negativeCntPtr = 0;
	va_start(ap, negativeCntPtr);
	val = va_arg(ap, double);
	while(val != 0)
	{
		if(val <0) (*negativeCntPtr)++;
		else (*positiveCntPtr)++;
		val = va_arg(ap, double);
	}
	va_end(ap);
}

void printPtrData(int* p)
{
	assert(p != NULL);
	printf("value = %d\n", *p);
}


void main2()
{
	/*int sum;
	sum = add(7, 1,2,978,3,-43,6,78);
	printf("sum = %d\n",sum);
	sum = add(1, 123);
	printf("sum = %d\n",sum);*/
	//int positiveCnt, negativeCnt;
	/*long x = 123654564L;
	float f = 1.2F;*/
	
	/*count(&positiveCnt, &negativeCnt, -1.2, 3.56, 7.98, -3.33, -5.0, 12.12, 11.45, 9.77, 0.0);
	printf("positive cnt = %d negative cnt = %d\n", positiveCnt, negativeCnt);*/
	/*system("notepad");
	printf("\nla la la");*/
	/*int x = 3;
	int* ptr = &x;
	printPtrData(ptr);*/
	
	getchar();
}