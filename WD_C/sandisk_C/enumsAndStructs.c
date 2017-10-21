#include <stdio.h>
#include <string.h>

typedef struct
{
	char name[19];
	char instructorName[30];
	int duration;
}Course;




typedef enum
{
	milk = 1,
	dark,
	white
}ChocolateType;

void func(ChocolateType type)
{

}

void main4()
{	
	Course arr[3];
	Course c1 = {"advanced c", "katia", 40};
	Course* p = &c1;
	//printf("%d",sizeof(c1));


	arr[0].duration = 20;
	strcpy(arr->name, "python");

	c1.duration = 42;
	strcpy(p->name, "c++");
	printf("name = %s, teacher name = %s duration = %d\n", p->name, 
		c1.instructorName, p->duration);

	getchar();

}