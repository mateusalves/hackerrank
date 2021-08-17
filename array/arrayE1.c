#include <assert.h>
#include <ctype.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* readline();
char* ltrim(char*);
char* rtrim(char*);
char** split_string(char*);

int parse_int(char*);

/*
 * Complete the 'hourglassSum' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts 2D_INTEGER_ARRAY arr as parameter.
 */

int sumArray(int arr_rows, int arr_columns, int arr[arr_rows][arr_columns]){
    int summedArray = 0;

    for(int i = 0; i < arr_rows; i++)
        for (int j = 0; j < arr_columns; j++ )
        {
            if ((i == 1 && j == 0) || (i == 1 && j == 2))
                continue;
            summedArray += arr[i][j];
        }

    return summedArray;
}

int getMax(int hourglassSumResults[]){

    int maxValue = hourglassSumResults[0];
    for(int o = 0; o < 16; o++)
        if(maxValue < hourglassSumResults[o])
           maxValue = hourglassSumResults[o];
    return maxValue;
}

int hourglassSum(int arr_rows, int arr_columns, int** arr) {

    int numberOfResults = 0;
    int hourglassSumResults[16];
    int hourglass[3][3];


    for (int n = 0; n < 4; n++)
        for (int m = 0; m < 4; m++)
        {
            for(int k = m; k < 3+m; k++)
            {
                for(int l = 0+n; l < 3+n; l++)
                {
                    hourglass[k-m][l-n] = arr[k][l];
                    printf("%d ", hourglass[k-m][l-n]);
                }
                printf("\n");
            }
            printf("\n");
            hourglassSumResults[numberOfResults++] = sumArray(3, 3, hourglass);
            printf("hourglassSumResults[%d] = %d\n", numberOfResults - 1, hourglassSumResults[numberOfResults - 1]);
        }

    return getMax(hourglassSumResults);

}

int main(){

    int arr_rows = 6;
    int arr_columns = 6;
    int arrExample[][6] = {{1, 1, 1, 0, 0, 0},
                           {0, 1, 0, 0, 0, 0},
                           {1, 1, 1, 0, 0, 0},
                           {0, 0, 2, 4, 4, 0},
                           {0, 0, 0, 2, 0, 0},
                           {0, 0, 1, 2, 4, 0}};

    // dynamically create an array of pointers of size 'arr_rows'
    int **arr = (int **)malloc( arr_rows * sizeof(int *));

    // dynamically allocate memory of size 'arr_columns' for each row
    for( int r = 0; r < arr_rows; r++)
    {
        arr[r] = (int *) malloc(arr_columns * sizeof(int));
    }


    for (int i = 0; i < arr_rows; i++)
        for (int j = 0; j < arr_columns; j++)
            *(*(arr + i) + j) = arrExample[i][j];

    int result;
    result = hourglassSum(arr_rows, arr_columns, arr);
    /*result = hourglassSum(arr_rows, arr_columns, arrExample);*/

    //int *test = arrExample[0];


    /*result = hourglassSum(arr_rows, arr_columns, &test);*/

    printf("Max Value %d\n", result);


    // deallocate memory
    for (int i = 0; i < arr_rows; i++)
        free(arr[i]);
    free(arr);

    return 0;
}
