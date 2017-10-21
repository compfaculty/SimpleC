#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utils.h"

void swap(int* pa, int* pb)
{
	int tmp = *pa;
	*pa = *pb;
	*pb = tmp;
}


