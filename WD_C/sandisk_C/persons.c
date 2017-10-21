#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct
{
	int day;
	int month;
	int year;
}Date;


typedef struct
{
	Date birthday;
	int age;
	double height;
	//etc
	char* fullName;
}Person;

void initPerson(Person* per)
{	
	char tmpName[40];
	printf("enter name, age, height: ");
	scanf("%s%d%lf",tmpName, &((*per).age), &(per->height));
	per->fullName = (char*)malloc(sizeof(char)*(strlen(tmpName) + 1));
	strcpy(per->fullName, tmpName);
	printf("enter day, month, year for %s: ", tmpName);
	scanf("%d%d%d",&(per->birthday.day), &(per->birthday.month), &(per->birthday.year));

}

void initPersons(Person* persons, int size)
{
	int i;
	for(i = 0;i<size;i++)
	{
		initPerson(&(persons[i]));
	}
}

void printPersons(Person* persons, int size)
{
	int i;
	for(i = 0;i<size;i++)
	{
		printf("%d) name = %s age = %d height = %lf date: %d/%d/%d\n", i+1,
			persons[i].fullName, persons[i].age, persons[i].height,
			persons[i].birthday.day,persons[i].birthday.month,persons[i].birthday.year);
	}
}

void freeAll(Person* persons, int size)
{
	int i;
	for(i = 0;i<size;i++)
	{
		free(persons[i].fullName);
	}
	free(persons);
}

void main6()
{
	int size = 2;
	Person* persons;
	int ind;

	persons = (Person*)malloc(sizeof(Person) * size);
	initPersons(persons, size);
	printPersons(persons, size);
	//ind = findLongestNameIndex(persons, size);
	freeAll(persons, size);
	fflush(stdin);
	getchar();

}