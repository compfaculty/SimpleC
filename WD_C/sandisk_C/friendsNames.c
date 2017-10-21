#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void initNames(char* names[], int size)
{
	int i;
	char tmp[128];
	for(i = 0; i< size; i++)
	{
		printf("enter name %d: ", i+1);
		gets(tmp);
		names[i] = (char*)malloc((strlen(tmp) + 1)*sizeof(char));
		strcpy(names[i], tmp);
	}
}

void printNames(char* names[], int size)
{
	int i;
	for(i = 0; i< size; i++)
	{
		printf("%s\n", names[i]);
	}
}

void freeNames(char* names[], int size)
{
	int i;
	for(i = 0; i< size; i++)
	{
		free(names[i]);
	}
}

void main2()
{
	int size;	
	char** names;
	//int size = sizeof(names)/ sizeof(char*);
	printf("enter num of names: ");
	scanf("%d", &size);
	getchar();
	names = (char**)malloc(size*sizeof(char*));
	initNames(names, size);
	printNames(names, size);
	freeNames(names, size);
	free(names);
	getchar();

	
}