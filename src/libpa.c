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

    // insertion_sort(array, size);
    // array_print(array, size);

    printf("*** Quicksort ***\n");
    quicksort(array, 0, size - 1);
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

void quicksort(int *array, int lo, int hi)
{
    if (lo >= hi)
    {
        return;
    }
    int partition = quicksort_partition(array, lo, hi);
    quicksort(array, lo, partition - 1);
    quicksort(array, partition + 1, hi);
}

int quicksort_partition(int *array, int lo, int hi)
{
    int pivot = array[hi];
    int index = lo - 1;

    for (int i = lo; i < hi; i++)
    {
        if (array[i] <= pivot)
        {
            index++;
            int temp = array[i];
            array[i] = array[index];
            array[index] = temp;
        }
    }
    index++;
    array[hi] = array[index];
    array[index] = pivot;
    return index;
}
