#include <math.h>
#define EPSILON 1e-10

double count_min(FILE *f);

double count_min(FILE *f)
{
    double min = 0., current = 0.;
    int count = 0;

    if (fscanf(f, "%lf", &min) != 1)
    {
        printf("File is empty");
        return 0;
    }

    count = 1;

    while (fscanf(f, "%lf", &current) == 1)
    {
        printf("Before: min=%lf, current=%lf, count=%d\n",
               min, current, count);

        if (current < min)
        {
            min = current;
            count = 1;
        }
        else if (fabs(min - current) < EPSILON)
        {
            count += 1;
        }

        printf("After: min=%lf, current=%lf, count=%d\n",
               min, current, count);
    }

    return count;
}

int main(void)
{
    FILE *f = fopen("input_data.txt", "r");

    if (f == NULL)
    {
        printf("File error");
        return -1;
    }
    else
    {
        printf("Answer: %lf", count_min(f));
        return 0;
    }
}
