#include <stdio.h>
#include <stdlib.h>
#define SIZE 10
#define MIN 2
#define MAX 10
#define SUM (MIN+MAX)
#define MAX2(n1,n2) ((n1)>(n2)?(n1):(n2))
#define MAX4(n1,n2,n3,n4) (MAX2(MAX2(n1,n2), MAX2(n3,n4)))
#define AVG(a,b) ((float)((a)+(b))/2)

int main()
{
    int a[SIZE];

    printf("Hello world! %.2f\n", AVG(3,4));
    return 0;
}
