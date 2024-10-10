#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <libpa.h>

int main()
{
    int size = 10;
    int *array = array_create_random(size, 0, 255);

    array_print(array, size);

    return 0;
}

int *array_create_random(int size, int min, int max)
{
    // min and max are inclusive
    srandom(time(NULL));
    int *array = (int *)malloc(sizeof(int) * size);

    for (int i = 0; i < size; i++)
    {
        array[i] = min + random() % (max - min + 1);
    }

    return array;
}

void array_print(int *array, int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d: %d\n", i, array[i]);
    }
}

int quick_sort(int *array)
{
}