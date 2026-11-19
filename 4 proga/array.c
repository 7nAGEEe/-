#include "sum_func.h"
#include <stdlib.h>

int main(void)
{
    int len = 0, capacity = 2, result = 0;
    double current = 0.;
    double *arr;

    FILE *f = fopen("input_data.txt", "r");

    if (f == NULL)
    {
        printf("Can't open the file");
        return -1;
    }

    arr = (double *)malloc(capacity * sizeof(double));

    if (arr == NULL)
    {
        printf("Memory error");
        return -1;
    }

    while (fscanf(f, "%lf", &current) == 1)
    {
        if (len == capacity)
        {
            capacity *= 2;
            double *arr2 = (double *)realloc(arr, capacity * sizeof(double));
            if (arr2 == NULL)
            {
                printf("Memory error");
                free(arr);
                return -1;
            }
            arr = arr2;
        }
        arr[len] = current;
        len ++;
    }
    result = equal_local_min(arr, len);
    printf("Answer is: %d", result);
    free(arr);
    return 0;
}