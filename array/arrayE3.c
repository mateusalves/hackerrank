#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
    int n;
    int sum = 0;

    scanf("%d", &n);
    int *arr = (int *) malloc(n * sizeof(int));

    for(int i = 0; i < n; i++)
        scanf("%d", &(*(arr + i)));

    for (int j = 0; j < n; j++)
        sum += *(arr + j);
    printf("%d\n", sum);

    free(arr);
    return 0;
}

