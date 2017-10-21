#include "file.h"

extern int num;

void write(Data arr[], int size, char filePath[])
{
	FILE* fp = fopen(filePath, "w");
	if(fp == NULL)
	{
		perror("open file error");
	}
	else
	{
		fwrite(arr, sizeof(Data), size, fp);
		printf("glob num = %d\n", num);
		fclose(fp);
	}

}