#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>
const int  ROW = 6;
const int COLUMN = 6;
const int HOUR_LENGHT = 3;
const int HOUR_HIGHT = 3;
int calculate_hour_glass_summ(int matrix[][COLUMN]);
int main(){
    int arr[ROW][COLUMN];
    int arr_i, arr_j;
//    for(arr_i = 0; arr_i < ROW; arr_i++){
//       for( arr_j = 0; arr_j < COLUMN; arr_j ++){
//
//          scanf("%d",&arr[arr_i][arr_j]);
//       }
//    }
    int arr2[][6] = {{1, 1, 1, 0, 0, 0},
                     {0, 1, 0, 0, 0, 0},
                     {1, 1, 1, 0, 0, 0},
                     {0, 9, 2, -4, -4, 0},
                     {0, 0, 0, -2, 0, 0},
                     {0, 0, -1, -2, -4, 0}
                    };
    printf("The max is %d\n", calculate_hour_glass_summ(arr2));
    return 0;
}
int calculate_hour_glass_summ(int matrix[][COLUMN]){
    int *head_p = matrix;
    int i, j, tmp_sum;
    int max = INT_MIN;
    for(j = 0; j < COLUMN - HOUR_HIGHT+1; j++){
        for(i = 0; i < ROW - HOUR_LENGHT+1; i++){
            tmp_sum = *(head_p + i) + *(head_p + i + 1) + *(head_p + i + 2) + *(head_p + ROW + i + 1) + *(head_p + 2*ROW + i) + *(head_p + 2*ROW + i + 1) + *(head_p + 2*ROW + i + 2);
            printf("iter %d  summ %d\n", i, tmp_sum);
            if ( tmp_sum > max) {
                max = tmp_sum;
            }
        }
        head_p += ROW;
    }
    return max;
}
