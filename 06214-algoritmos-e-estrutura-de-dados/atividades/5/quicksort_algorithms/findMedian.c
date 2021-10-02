//Link for this challenge: https://www.hackerrank.com/challenges/find-the-median/
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

char *readline();
char *ltrim(char *);
char *rtrim(char *);
char **split_string(char *);

int parse_int(char *);

/*
 * Complete the 'findMedian' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts INTEGER_ARRAY arr as parameter.
 */

int findMedian(int arr_count, int *arr)
{
    int *a = quickSort(arr_count, arr);
    for (int i = 0; i < arr_count; i++)
    {
        printf("%d ", a[i]);
    }
    return -1;
}

int *quickSort(int arr_count, int *arr, int *result_count)
{
    *result_count = arr_count;

    if (arr_count == 2)
    {
        if (arr[0] < arr[1])
        {
            return arr = {arr[0], arr[1]};
        }
        else
        {
            return arr = {arr[1], arr[0]};
        }
    }

    int *left = malloc(arr_count * sizeof(int));
    int *equal = malloc(arr_count * sizeof(int));
    int *right = malloc(arr_count * sizeof(int));

    

    //Storing the pivot
    int pivot = arr[0];

    //Dividing
    int index_left = 0, index_equal = 0, index_right = 0;
    for (int i = 0; i < arr_count; i++)
    {
        if (arr[i] < pivot)
            left[index_left++] = arr[i];
        else if (arr[i] == pivot)
            equal[index_equal++] = arr[i];
        else
            right[index_right++] = arr[i];
    }

    //Let's quicksort the left and the right
    *left = quickSort(index_left, left, &index_left);
    *right = quickSort(index_right, right, &index_right);

    //Group all together
    int *a = malloc(arr_count * sizeof(int));
    memcpy(a, left, index_left * sizeof(int));
    memcpy(a + index_left, equal, index_equal * sizeof(int));
    memcpy(a + index_left + index_equal, right, index_right * sizeof(int));

    //Getting free of our Arrays
    free(left);
    free(equal);
    free(right);

    return a;
}

int main()
{
    FILE *fptr = fopen(getenv("OUTPUT_PATH"), "w");

    int n = parse_int(ltrim(rtrim(readline())));

    char **arr_temp = split_string(rtrim(readline()));

    int *arr = malloc(n * sizeof(int));

    for (int i = 0; i < n; i++)
    {
        int arr_item = parse_int(*(arr_temp + i));

        *(arr + i) = arr_item;
    }

    int result = findMedian(n, arr);

    fprintf(fptr, "%d\n", result);

    fclose(fptr);

    return 0;
}

char *readline()
{
    size_t alloc_length = 1024;
    size_t data_length = 0;

    char *data = malloc(alloc_length);

    while (true)
    {
        char *cursor = data + data_length;
        char *line = fgets(cursor, alloc_length - data_length, stdin);

        if (!line)
        {
            break;
        }

        data_length += strlen(cursor);

        if (data_length < alloc_length - 1 || data[data_length - 1] == '\n')
        {
            break;
        }

        alloc_length <<= 1;

        data = realloc(data, alloc_length);

        if (!data)
        {
            data = '\0';

            break;
        }
    }

    if (data[data_length - 1] == '\n')
    {
        data[data_length - 1] = '\0';

        data = realloc(data, data_length);

        if (!data)
        {
            data = '\0';
        }
    }
    else
    {
        data = realloc(data, data_length + 1);

        if (!data)
        {
            data = '\0';
        }
        else
        {
            data[data_length] = '\0';
        }
    }

    return data;
}

char *ltrim(char *str)
{
    if (!str)
    {
        return '\0';
    }

    if (!*str)
    {
        return str;
    }

    while (*str != '\0' && isspace(*str))
    {
        str++;
    }

    return str;
}

char *rtrim(char *str)
{
    if (!str)
    {
        return '\0';
    }

    if (!*str)
    {
        return str;
    }

    char *end = str + strlen(str) - 1;

    while (end >= str && isspace(*end))
    {
        end--;
    }

    *(end + 1) = '\0';

    return str;
}

char **split_string(char *str)
{
    char **splits = NULL;
    char *token = strtok(str, " ");

    int spaces = 0;

    while (token)
    {
        splits = realloc(splits, sizeof(char *) * ++spaces);

        if (!splits)
        {
            return splits;
        }

        splits[spaces - 1] = token;

        token = strtok(NULL, " ");
    }

    return splits;
}

int parse_int(char *str)
{
    char *endptr;
    int value = strtol(str, &endptr, 10);

    if (endptr == str || *endptr != '\0')
    {
        exit(EXIT_FAILURE);
    }

    return value;
}
