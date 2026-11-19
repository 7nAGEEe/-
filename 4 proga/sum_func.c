#include "sum_func.h"
#include <math.h>

int equal_local_min(double *arr, int len)
{
    int flag = 0;
    double first_min = 0.;

    for (int i = 1; i < len - 1; i ++)
    {
        if ((arr[i] < arr[i-1]) && (arr[i] < arr[i+1]))
        {
            if (flag == 0)
            {
                flag = 1;
                first_min = arr[i];
            }
            else 
            {
                if (fabs(arr[i] - first_min) >= eps)
                return 0;
            }
        }
    }
    return 1;
}