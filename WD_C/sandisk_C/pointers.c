#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "infra.h"

void printInt(void* ptrItem)
{
	int val = *(int*)ptrItem;
	printf("%d\n", val);
}

void printSqrtInt(void* ptrItem)
{
	int val = *(int*)ptrItem;
	printf("%lf\n", sqrt((double)val));
}

void incrementItem(void* ptrItem)
{
	/*int* pItem = (int*)ptrItem;
	*pItem = *pItem + 1;*/
	*(int*)ptrItem = *(int*)ptrItem + 1;
}

void func(int* px)
{
	*px = *px + 1;
}

void func1(int** ptrP)
{
	*ptrP = (int*)malloc(2*4);
}

void main()
{
	/*int a[10] = {1,2,3,4,5,6,7,8,9,10};
	iterArray(a, 10, sizeof(int), incrementItem);
	iterArray(a, 10, sizeof(int), printInt);*/

	int x = 2;
	int* p = NULL;
	func1(&p);
	//func(&x);
	printf("p = %x", p);

	getchar();
}

