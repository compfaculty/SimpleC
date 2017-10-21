#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>
int solve(int n, int s_size, int* s, int d, int m){
    // Complete this function
    int i;
    int *head = s;
    int *tail = &s[s_size-1];
    int splits = 0;
    if (s_size == 1 && )
    while (head != tail){
        int tmp=0;
        int* tmp_p = head;
        for(i=0; i < m; i++){
            tmp += *(tmp_p++);
        }
        if (tmp == d){
            splits++;
        }
        head++;
    }
    return splits;
}
int main(){
    int s[] = {4};
    int d = 4;
    int n = 1;
    int len = 1;
    int res ;
    res = solve(len,len,s,d,n);
    return 0;
}
int main2(){
    int n;
    int i;
    scanf("%d",&n);
    char* src = (char*)malloc(n+1);
    for(i = 0; i < n; i++){
        *(src + i) = 0x20;
    }
    *(src + n) ='\0';
    for(i = n-1; i >= 0; i--){
        *(src + i) = 0x23;
        printf("%s\n", src);
    }
    free(src);
    return 0;
}
