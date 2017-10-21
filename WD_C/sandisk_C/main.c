#include "file.h"
#include "write2File.h"
#include <stdio.h>
#include "C:\\Katia\\MyLib\\MyLib\\addMult.h"
//#include "div.h"

int num = 17;
void func();

void main()
{
	Data a[] = {{2, "message1"}, {4, "message2"}, {13, "message3"}};
	int i;
	//write(a, sizeof(a)/sizeof(a[0]), "c:\\katia\\stam.txt");
	for(i = 1; i<=5; i++)
		func();

	printf("\nsum = %d\n",add(1,5));
	getchar();
}

void func()
{
	int n = 1;
	static int staticN = 1;
	
	printf("n = %d staticN = %d\n", n , staticN);
	n++;
	staticN++;
}