#include <stdlib.h>
#include <stdio.h>
#include <string.h>


void doMalloc(char** ptr)
{
	int size = 5;
	printf("enter len of your name: ");
	//scanf("%d", &size);//5+ was enterd
	//getchar();
	*ptr = (char*)malloc(sizeof(char)*(size+1));
}

void main()
{
	char* p = NULL;
	doMalloc(&p);
	strcpy(p,"katia");

	free(p);
}
