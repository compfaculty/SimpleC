#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
void iterArray(void *arr, int size, int sizeofItem, void (*cb)(void* itemPtr))
{
    int i;
    void* p=arr;
    for(i = 0; i<size; i++)
    {
        cb(p);
        p = (char*)p + sizeofItem; //important  typecast pointer , cause pointers arithmetics doesnt work with void

    }
}
void printInt(void* ptrItem){
    int val = *(int*)ptrItem;
    printf("%d ", val);
}
void printSqrtInt(void* ptrItem){
    int val = *(int*)ptrItem ;
    printf("%lf ", sqrt((double)val));
}
void incrementItem(void* ptrItem){
    int* pInt = (int*)ptrItem ;
    *pInt = *pInt + 1;
}
void checkSig(int count, ...)
{
    int i;
    double tmp;
    int pos=0, neg=0;
    va_list ap;
    va_start(ap, count);
    for(i=1; i<=count; i++){
        tmp = va_arg(ap, double);
        if (tmp >=0){
            printf("\nPOSITIVE %.2lf ", tmp);
            pos++;
        }
        else{
            printf("\nNEGATIVE %.2lf ", tmp);
            neg++;
        }
    }
    printf("\nGENERAL: \npositive args %d\nnegative args %d", pos, neg);
    va_end(ap);
}

int main2()
{

    FILE* fp = fopen("data.dat","r");
    if (fp == NULL){
        perror("open file error");
    }
    printf("errno -%d  %s", errno, sys_errlist[errno]);
}

int simItems(int a[], int size, int index)
{

    if (index == size - 1){
        return a[index];
    }
    return sumItems(a, size, index+1) + a[index];
}
int main()
{
    //int a[10] = {1,2,3,4,5,6,7,8,9,10};
    //iterArray(a, 10, sizeof(int), printInt);
    checkSig(5, 1.2, -2.23, 666.666, -145.7, 10.0);
    printf("\nDONE!\n");
    main2();
    return 0;
}
