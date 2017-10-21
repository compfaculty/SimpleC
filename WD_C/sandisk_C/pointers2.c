#include <stdio.h>

#define SIZE 20

void initArray(int arr[], int size)
{
	int i;
	for(i=0; i<size; i++)
	{
		arr[i] = i+1;
		//*arr = i+1; arr++
	}
}

//void main()
//{
//	int i;
//	int arr[SIZE];
//	initArray(arr, SIZE);
//	for(i=0; i<SIZE; i++)
//		printf("%d\n", arr[i]);
//	getchar();
//}

void swap(int* pa, int* pb)
{
	int tmp = *pa;
	*pa = *pb;
	*pb = tmp;
}

void main1()
{
	int a = 2,b = 17;
	printf("before: a = %d b = %d\n", a,b);
	swap(&a,&b);
	 
	printf("after: a = %d b = %d\n", a,b);

	getchar();
}