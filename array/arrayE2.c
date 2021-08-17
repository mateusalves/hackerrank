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

int* rotLeft(int a_count, int* a, int d, int* result_count)
{
    int *rotatedA = (int *)malloc(a_count * sizeof(int));
    int i;

    for (i = 0; i < a_count-d; i++)
        *(rotatedA + i) = *(a + d + i);

    int j;

    for (j = 0; j < d; j++)
        *(rotatedA + i + j)  = *(a+j);

    *(result_count) = i + j;

    return rotatedA;
}


int main()
{
    int T, N, K;

    scanf("%d", &T);
    scanf("%d%d", &N, &K);

    int A[N];
    for (int i = 0; i < N; i++)
        scanf("%d", &A[i]);

    for (int j = N - K; j < N ; j++)
        printf("%d ", A[j]);

    for (int k = 0; k < N - K; k++)
        printf("%d ", A[k]);
    printf("\n");

    int n = 5, d = 4;
    int result_count;
    int *result;

    int a[] = {1, 2, 3, 4, 5};

    result = rotLeft(n, a, d, &result_count);


   for (int i = 0; i < result_count; i++) {
        printf("%d", *(result + i));

        if (i != result_count - 1) {
            printf(" ");
        }
    }

    free(result);
    printf("\n");
}

