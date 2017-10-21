#include <stdio.h>

void printArr(const int* arr, int size)
{
	int i;
	//arr[0] = 1765; - error
	for(i=0; i<size; i++)
		printf("%d ", arr[i]);
}

void swap(int* const pa, int* const pb)
{
	int tmp = *pa;
	*pa = *pb;
	*pb = tmp;
}

void main3()
{
	int* pp = NULL;
	char name[] = "daniel";
	char val[] = "kjhkj";
	void* p;
	p = val;
	//p = name + 2;
	putchar(*((char*)p));
	p = (char*)p + 1;//+ 1 byte

	putchar(*((char*)p));

	getchar();

}

void main2()
{
	int arr[] = {1,2,3,4,56};
	int a = 2, b = 3;
	int* p = &a;
	//const int* const p = &a;
	//swap(&a, &b);
	//printArr(a, sizeof(a)/sizeof(a[0]));
	/*
	const int maxAge = 150;
	int a = 2, b = 3;
	const int* p;
	p = &a;
	p = &b;*/
	getchar();
}

void main1()
{
	int a[] = {1,2,3,4,5,6,7,8,9,10};
	int* p = a-1;//WARNING!!
	int* pMid = a+4;
	int i;
	for(i=1; i<=10; i++)
		printf("%d ", p[i]);
	printf("\n");
	
	for(i = -4; i<=5; i++)
	{
		printf("%d ", pMid[i]);
	}


	getchar();
}