#include <stdio.h>

typedef struct
{
	unsigned char type : 4;
	unsigned char val1 : 2;
	unsigned char val2 : 1;
	unsigned char val3 : 3;
}Data;


void main()
{
	Data d;
	d.type=11;
	d.val2 = 0;
	printf("%d", sizeof(d));
	//unsigned char mask1 = 0X78, mask2 = 0XB2;//mask1 = 01111000, mask2 = 10110010
	//										//		   10110010

	//unsigned char res1 = mask1 & mask2, res2 = mask1 ^ mask2;
	//unsigned int val = 564658701;
	//printf("and = %X, xor = %X ", res1, res2);
	//mask2<<=1;
	//printf("10110010<<1 = %X",mask2);     //01100100   
	//
	getchar();
}