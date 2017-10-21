#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mystructures.h"



void buildArrayPerson(Person **arr, int size)
{
    *arr = (Person*)malloc(size*sizeof(Person));
}

void initPerson(Person *per){
    char tmpName[40];
    printf("Enter name, age, height:");
    scanf("%s%d%lf", tmpName, &(per->age), &(per->hight));
    per->fullName = (char*)malloc(sizeof(char)*(strlen(tmpName) + 1));// +1 for '/0'
    strcpy(per->fullName, tmpName);
    printf("Enter day, month, year");
    scanf("%d%d%d", &(per->birthdate.day), &(per->birthdate.month), &(per->birthdate.year));
}

void initArrayPerson(Person arr[], int size)
{
    int i;
    printf("insert your data\n");
    for(i=0; i < size; i++){
        initPerson(&arr[i]);
    }
}

Person *findLongestNamePerson(Person *arr, int size)
{
    int i, max, tmp_max = 0;
    for(i=0;i < size; i++){
        if( tmp_max < strlen(arr[i].fullName)){
            tmp_max = strlen(arr[i].fullName);
            max = i;
        }
    }
    return &(arr[max]);
}

void initBook(GenericBook *pBook, ActiveField field){
    switch(field)
    {
        case BaseBookType:
            strcpy(pBook->basebook.name, "book me");
            pBook->basebook.pages = 1234;
            pBook->basebook.price = 123.99;
            break;
        case StudyBookType:
            strcpy(pBook->studybook.book.name, "book me 2");
            pBook->studybook.book.pages = 2345;
            pBook->studybook.book.price = 1233.99;
            pBook->studybook.grade = 'A';
            break;
    }
}
