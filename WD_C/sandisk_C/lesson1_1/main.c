#include <stdio.h>
#include <stdlib.h>
#include "utils.h"
#include "myarrays.h"
#include "mystring.h"
#include "mystructures.h"
#define SIZE 10
void printit(int arr[], int size){
    int *ptr;
    for(ptr = arr; ptr < &arr[SIZE]; ptr++){
        printf("%d\n", *ptr);
    }
}
int main(int argc, char **argv)
{
    int arr[SIZE], *iptr, value;
    for(iptr = arr, value=1; iptr < &arr[SIZE]; iptr++, ++value){
        *iptr = value;
    }
    printit(arr, 1);
    //int elem = 0;
    //int count = 0;
    //int a[] = {1,2,9,23,2,122,12,7,5,9,9,9,23};
    //int a_size = sizeof(a)/sizeof(int);
    //max_count(a, a_size, &elem, &count);
    //printf("The element %d was found %d times \n", elem, count);
    //char *s1=  "12349999";
    //char *s2 = "5678";
    //char *res = exchange(s1, s2);
    //printf("Result %s\n", res);
    //char *s = "qweasdhjkjasdkjjkjasd";
    //char *sub = "asd";
    //int i, count = 0;
    //int arr[strlen(s)];
    //printf("%d\n", sizeof(arr));
    //countsub(s,sub, &count, arr);
    //printf("Found indexes: %d\n", count);
    //int *tmp = countsub2(s, sub);
    //for(i = 0; i < 3; i++){
    //  printf("%d ", tmp[i]);
    //}
    //free(tmp);

//    int size;
//    char** names;
//    printf("enter num names:");
//    scanf("%d", &size);
//    names = (char**)malloc(size*sizeof(char*));
//    initNames(names, size);

//    char *p = NULL;
//    doMalloc(&p);
//    strcpy(p, "katia");
//    free(p);
//    int *data;
//    int *arr2;
//    int i, size=0;
//    printf("Enter array size:");
//    scanf("%d", &size);
//    data = buildArr(size);
//    initArr(data, size);
//    for(i=0; i < size; i++){
//        printf("%d ", data[i]);
//    }
//    printf("\n");
//
//    buildArr2(&arr2, size);
//    initArr(arr2, size);
//    int i, count = 0;
//    printf("Insert size\n");
//    scanf("%d", &count);
//    Person *arr;
//    buildArrPerson(&arr, count);
//    initArrPerson(arr, count);
//    for(i=0; i < count; i++){
//        printf("Person %d: %d %lf %s\n", i, arr[i].age, arr[i].hight, arr[i].fullName);
//    }
//    //printf("\n");
//    Person *tmp;
//    tmp = findLongestNamePerson(arr, count);
//    printf("Person longest name is %d %lf %s\n", tmp->age, tmp->hight, tmp->fullName);
//    free(arr);
    return 0;
}
