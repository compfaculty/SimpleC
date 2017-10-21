#ifndef SIMPLE_H_INCLUDED
#define SIMPLE_H_INCLUDED



#endif // SIMPLE_H_INCLUDED
//count max element in array
int compare_int(const void* a, const void* b);
void max_count(int arr[], int arr_size, int *element, int* count);
//find max element in array
int findmax(int arr[], int size);
//find min element in array
int findmin(int arr[], int size);
//find max element in array using pointer
int findmax_p(int *arr, int size);
//find min element in array using pointer
int findmin_P(int *arr, int size);
//find min&max elements in array using pointer
void findMinMax(double *arr, int size, double* pMin, double* pMax);
//build array of size
int *buildArray(int SIZE);
void buildArray_p(int **arr, int size);
//init array from stdin
int initArray(int arr[], int SIZE);
//another example init array of strings
void initNames(char* names[], int size);
