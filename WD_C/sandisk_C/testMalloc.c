#define _CRT_NO_ERROR
#include <stdio.h>
#include <stdlib.h>

int main()
{
	int maxVal;
	int num, i;
	int* counters;
	printf("enter max range val: ");
	scanf("%d", &maxVal);//0-maxVal(10)
	counters = (int*)calloc(maxVal + 1,sizeof(int));
	if(counters == NULL)
	{
		printf("memory allocation error!!!");
		return 1;
	}
	printf("enter values: 0 - %d, -1 to stop: ",maxVal);
	while(1)
	{
		scanf("%d", &num);
		if(num == -1) break;
		if(num >=0 && num<= maxVal)
			counters[num]++;
		else
			printf("incorrect input!!!!!!\n");
	}

	for(i=0; i<=maxVal; i++)
		printf("num %d appears %d times\n", i,counters[i]);

	free(counters);

	//int i = 0;
	//int size = 12;
	//int* p = (int*)malloc(size * sizeof(int));//int p[12]
	//for(i = 0; i< size; i++)
	//{
	//	p[i] = i + 1;
	//	printf("%d\n",p[i]);
	//}

	//free(p);
	fflush(stdin);
	getchar();
}