#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
	int id;
	char s[10];
}Item;

int itemCmp(const void *elem1, const void *elem2);

void main()
{
	Item a[] = {{22, "bb"}, {-11, "iii"}, {3, "abc"}, 
			{8, "a"}, {103, "dd"}, {17, "xyz"}, {19, ""}};
	int size = sizeof(a)/sizeof(a[0]), i;

	qsort(a,size, sizeof(a[0]), itemCmp); 
	for(i = 0; i< size; i++)
	{
		printf("%4d %10s\n", a[i].id, a[i].s);
	}
	getchar();
}

int itemCmp(const void *elem1, const void *elem2) 
{
	//return ((Item*)elem1)->id - ((Item*)elem2)->id;
	return strcmp(((Item*)elem1)->s, ((Item*)elem2)->s);
}