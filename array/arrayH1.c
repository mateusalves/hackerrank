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
 * Complete the 'minimumBribes' function below.
 *
 * The function accepts INTEGER_ARRAY q as parameter.
 */
void printArray(long n, long *arr)
{
    for (int i = 0; i < n; i++)
        printf("%ld\t", arr[i]);
    printf("\n");
}

long arrayManipulation(int n, int queries_rows, int queries_columns, int **queries) {

    long *arr = (long *)calloc(n+1, sizeof(long *));
    long maxValue = 0, x = 0;

    for(int j = 0; j < queries_rows; j++)
    {
        arr[*(*(queries+j))] += *(*(queries+j)+2);
        if (*(*(queries + j ) + 1) + 1 <= n)
            arr[*(*(queries+j) + 1) + 1] -= *(*(queries+j)+2);
    }
    for(long k = 1; k <= n; k++)
    {
        x += arr[k];
        printf("X %ld\n", x);
        if (maxValue < x)
            maxValue = x;
    }
    free(arr);
    return maxValue;
}


int main(){
    int n = 10, m = 3;
    /*int q[3][3] = {{1, 5, 3}, {4, 8, 7}, {6, 9, 1}};*/
    n = 5;

    int q[3][3] = {{1, 2, 100}, {2, 5, 100}, {3, 4, 100}};

    int** queries = malloc(m * sizeof(int*));

    for (int i = 0; i < m; i++) {
        *(queries + i) = malloc(3 * (sizeof(int)));

        for (int j = 0; j < 3; j++) {
            printf("%d ", q[i][j]);
            *(*(queries + i) + j) = q[i][j];
        }
        printf("\n");
    }

    long result = arrayManipulation(n, m, 3, queries);

    printf("%ld\n", result);
    free(queries);
    return 0;
}


/*int main()*/
/*{*/
/*    [>FILE* fptr = fopen(getenv("OUTPUT_PATH"), "w");<]*/

/*    char** first_multiple_input = split_string(rtrim(readline()));*/

/*    int n = parse_int(*(first_multiple_input + 0));*/

/*    int m = parse_int(*(first_multiple_input + 1));*/

/*    int** queries = malloc(m * sizeof(int*));*/

/*    for (int i = 0; i < m; i++) {*/
/*        *(queries + i) = malloc(3 * (sizeof(int)));*/

/*        char** queries_item_temp = split_string(rtrim(readline()));*/

/*        for (int j = 0; j < 3; j++) {*/
/*            int queries_item = parse_int(*(queries_item_temp + j));*/

/*            *(*(queries + i) + j) = queries_item;*/
/*        }*/
/*    }*/

/*    long result = arrayManipulation(n, m, 3, queries);*/

/*    printf("%ld\n", result);*/

/*    [>fclose(fptr);<]*/

/*    return 0;*/
/*}*/

/*char* readline() {*/
/*    size_t alloc_length = 1024;*/
/*    size_t data_length = 0;*/

/*    [>FILE *ptrFile;<]*/

/*    [>ptrFile = fopen("input12.txt", "r");<]*/

/*    char* data = malloc(alloc_length);*/

/*    while (true) {*/
/*        char* cursor = data + data_length;*/
/*        char* line = fgets(cursor, alloc_length - data_length, stdin);*/

/*        if (!line) {*/
/*            break;*/
/*        }*/

/*        data_length += strlen(cursor);*/

/*        if (data_length < alloc_length - 1 || data[data_length - 1] == '\n') {*/
/*            break;*/
/*        }*/

/*        alloc_length <<= 1;*/

/*        data = realloc(data, alloc_length);*/

/*        if (!data) {*/
/*            data = '\0';*/

/*            break;*/
/*        }*/
/*    }*/

/*    if (data[data_length - 1] == '\n') {*/
/*        data[data_length - 1] = '\0';*/

/*        data = realloc(data, data_length);*/

/*        if (!data) {*/
/*            data = '\0';*/
/*        }*/
/*    } else {*/
/*        data = realloc(data, data_length + 1);*/

/*        if (!data) {*/
/*            data = '\0';*/
/*        } else {*/
/*            data[data_length] = '\0';*/
/*        }*/
/*    }*/

/*    return data;*/
/*}*/

/*char* ltrim(char* str) {*/
/*    if (!str) {*/
/*        return '\0';*/
/*    }*/

/*    if (!*str) {*/
/*        return str;*/
/*    }*/

/*    while (*str != '\0' && isspace(*str)) {*/
/*        str++;*/
/*    }*/

/*    return str;*/
/*}*/

/*char* rtrim(char* str) {*/
/*    if (!str) {*/
/*        return '\0';*/
/*    }*/

/*    if (!*str) {*/
/*        return str;*/
/*    }*/

/*    char* end = str + strlen(str) - 1;*/

/*    while (end >= str && isspace(*end)) {*/
/*        end--;*/
/*    }*/

/*    *(end + 1) = '\0';*/

/*    return str;*/
/*}*/

/*char** split_string(char* str) {*/
/*    char** splits = NULL;*/
/*    char* token = strtok(str, " ");*/

/*    int spaces = 0;*/

/*    while (token) {*/
/*        splits = realloc(splits, sizeof(char*) * ++spaces);*/

/*        if (!splits) {*/
/*            return splits;*/
/*        }*/

/*        splits[spaces - 1] = token;*/

/*        token = strtok(NULL, " ");*/
/*    }*/

/*    return splits;*/
/*}*/

/*int parse_int(char* str) {*/
/*    char* endptr;*/
/*    int value = strtol(str, &endptr, 10);*/

/*    if (endptr == str || *endptr != '\0') {*/
/*        exit(EXIT_FAILURE);*/
/*    }*/

/*    return value;*/
/*}*/
/*[>void getArray()<]*/
/*[>{<]*/
/*[>    char array[100000][3];<]*/
/*[>    FILE *ptr = NULL;<]*/

/*[>    int i = 0;<]*/

/*[>    ptr = fopen("input12.txt", "r");<]*/
/*[>    while(fgets(array[i], 128, ptr) != NULL)<]*/
/*[>    {<]*/
/*[>        array[i][strlen(array[i])-1] = '\0';<]*/
/*[>        i++;<]*/
/*[>    }<]*/
/*[>    int tot = 5;<]*/
/*[>    printf("\nThe content: \n");<]*/
/*[>        printf(" %s\n", array[0]);<]*/
/*[>        [>printf(" %s\n", array[1]);<]<]*/
/*[>        [>printf(" %s\n", array[2]);<]<]*/
/*[>    [>for (i = 0; i < tot; i++)<]<]*/
/*[>    [>{<]<]*/
/*[>    [>    printf(" %s\n", array[i]);<]<]*/
/*[>    [>}<]<]*/
/*[>    printf("\n");<]*/

/*[>}<]*/
