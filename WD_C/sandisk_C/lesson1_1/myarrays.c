#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "myarrays.h"

int *buildArray(int SIZE)
{
    return (int*)malloc(SIZE*sizeof(int));
}

void buildArray_p(int **arr, int size)
{
    *arr = (int*)malloc(size*sizeof(int));
}

int initArray(int arr[], int SIZE)
{
    int i;
    printf("insert your data\n");
    for(i=0; i < SIZE; i++){
        scanf("%d", &arr[i]);
    }
}
int compare_int(const void* a, const void* b)
{
    int *arg1 = (int*)a;
    int *arg2 = (int*)b;
    if (*arg1 < *arg2) return -1;
    if (*arg1 > *arg2) return 1;
    return 0;
}
void max_count(int arr[], int arr_size, int *element, int* count)
{
    int max = 1;
    //sort array
    qsort(arr, arr_size, sizeof(int), compare_int);
    *element = *arr;
    *count = 0;
    int i ;
    for(i =0; i < arr_size; i++)
    {
        //go throw sorted array and increment max until current elem == next element
        if(*(arr + i) == *(arr + i + 1)){
            max++;
        }
        //now current != next
        else {

            if (max > *count){
                *count = max;
                *element = *(arr + i);
                max = 0;
            }
        }
    }
}
int findmax(int arr[], int size)
{
    int i;
    int max = 0;
    for(i = 0; i< size; i++){
        if(arr[i] > max){
            max = arr[i];
        }
    }
    return max;
}
int findmin(int arr[], int size)
{
    int i, min = 0;
    for(i = 0; i< size; i++){
        if(arr[i] < min){
            min = arr[i];
        }
    }
    return min;
}
int findmax_p(int *arr, int size)
{
    int i = 0;
    int max = 0;
    while (i < size){
        if (*(arr++) > max){
            max = *arr;
        }
        i++;
    }
    return max;
}
int findmin_p(int *arr, int size)
{
    int i = 0;
    int min = 0;
    for(i = 0; i < size; i++, arr++)
        {
            if (*arr < min){
            min = *arr;
            }
        }
    return min;
}

void findMinMax(double *arr, int size, double* pMin, double* pMax)
{
    int i;
    *pMin = *pMax = *arr;
    for(i = 0; i < size; i++, arr++)
    {
        if(*arr > *pMax)
            *pMax = *arr;
        else if(*arr < *pMin)
                *pMin = *arr;
    }
}

void initNames(char* names[], int size)
{
    int i;
    char tmp[128];
    for(i=0; i < size; i++){
        printf("Enter name %d ", i+1);
        gets(tmp);// we dont need to clean tmp cause strlen , and strcpy take '\0' into account
        names[i] = (char*)malloc((strlen(tmp) + 1)*sizeof(char));
        strcpy(names[i], tmp);
    }
}
