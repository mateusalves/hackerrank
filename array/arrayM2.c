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

/*char* readline();*/
/*char* ltrim(char*);*/
/*char* rtrim(char*);*/
/*char** split_string(char*);*/

int parse_int(char*);

/*
 * Complete the 'minimumBribes' function below.
 *
 * The function accepts INTEGER_ARRAY q as parameter.
 */

// Complete the minimumSwaps function below.
int minimumSwaps(int arr_count, int* arr) {
    int minSwaps = 0;
    int swapped;

    for(int j = 0; j < arr_count; j++)
    {
        swapped = 0;
        if (*(arr + j) != j+1)
        {
            for(int i = j+1; i < arr_count; i++)
            {
                printf("%d %d\n", *(arr+i), j+1);
                if (*(arr + i) == j + 1)
                {
                    *(arr + i) = *(arr + j);
                    *(arr + j) = j + 1;
                    minSwaps++;
                    swapped = 1;
                    break;
                }
            }
        }
    }

    return minSwaps;
}

int main(){
    int n = 4;
    int arr[] = {4, 3, 1, 2};
    int result;

    result = minimumSwaps(n, arr);

    printf("%d\n", result);

}

