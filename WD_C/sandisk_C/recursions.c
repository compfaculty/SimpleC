#include <stdio.h>
#include <math.h>

int sumNumbers(int n)
{
	if(n == 1) return 1;
	return sumNumbers(n - 1) + n;
}

int sumItems(int a[], int size, int index)
{
	if(index == size - 1)//last element to sum
	{
		return a[index];
	}
	return sumItems(a, size, index+1) + a[index];
}

int minArrayVal(int a[], int size, int index)
{
	int min;
	if(index == size -1) return a[index];
	min = minArrayVal(a, size, index + 1);
	return (min < a[index])? min: a[index];	
}

void hanoi(char source, char temp, char dest, int n);

void main5()
{
	//printf("%d\n", sumNumbers(10));
	int a[] = {1,2,-301,88,9,32,567,-11,8};
	printf("%d\n",minArrayVal(a, sizeof(a)/sizeof(int), 0));
	getchar();
}