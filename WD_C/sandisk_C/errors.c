#include <stdio.h>
#include <stdlib.h>

FILE* fp;
int* p;

void closeFile()
{
	printf("in closeFile\n");
	fclose(fp);
	getchar();
}

void freeMemory()
{
	printf("in freeMemory\n");
	free(p);
	getchar();
}

void getMemory()
{
	printf("in func\n");
	p = (int*)malloc(10*sizeof(int));
	atexit(freeMemory);
	p[0] = 11;
	p[1] = p[0]*2;
	printf("end func\n");
}


main3()
{
	printf("in main\n");
	fp = fopen("C:\\Katia\\test1.txt", "r");
	if(fp == NULL)
	{
		perror("open file error");
		
	}
	atexit(closeFile);
	getMemory();
	//printf("\nerrno = %d, message = %s", errno, sys_errlist[errno]);
	
	printf("end main\n");
	getchar();
}

