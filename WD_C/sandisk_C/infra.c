#include <stdio.h>

void iterArray(void* arr, int size, int sizeofItem, void(*cb)(void* itemPtr))
{
	//loop on arr items and activate cb function on each item
	int i;
	void* p = arr;
	for(i = 0; i<size; i++)
	{
		cb(p);
		p = (char*)p + sizeofItem;
	}
}