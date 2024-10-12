#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <libpa.h>

int main()
{
    int size = 10;
    int *array = array_create_random(size, 0, 255);
    array_print(array, size);

    // bubble_sort(array, size);
    // array_print(array, size);

    // selection_sort(array, size);
    // array_print(array, size);

    insertion_sort(array, size);
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
    // printf("=============\n");
    for (int i = 0; i < size; i++)
    {
        printf("%d: %d\n", i, array[i]);
    }
}

int bubble_sort(int *array, int size)
{
    printf("*** Bubble Sort ***\n");
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (array[j] > array[j + 1])
            {
                // swap
                int temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
    return 0;
}

int insertion_sort(int *array, int size)
{
    printf("*** Insertion Sort ***\n");
    for (int i = 1; i < size; i++)
    {
        int current = array[i];
        int j = i - 1;
        while (j >= 0 && array[j] >= current)
        {
            array[j + 1] = array[j];
            j--;
        }
        array[j + 1] = current;
    }

    return 0;
}

int selection_sort(int *array, int size)
{
    printf("*** Selection Sort ***\n");
    for (int i = 0; i < size - 1; i++)
    {
        int min = i;
        for (int j = i + 1; j < size; j++)
        {
            if (array[j] < array[min])
            {
                min = j;
            }
        }
        int temp = array[i];
        array[i] = array[min];
        array[min] = temp;
    }
    return 0;
}

int quick_sort(int *array, int size)
{
}