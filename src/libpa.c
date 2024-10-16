#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <libpa.h>

int main()
{
    int size = 10;
    int *array = array_create_random(size, 0, 10);
    array_print(array, size);

    // bubble_sort(array, size);
    // array_print(array, size);

    // selection_sort(array, size);
    // array_print(array, size);

    // insertion_sort(array, size);
    // array_print(array, size);

    // printf("*** Quicksort ***\n");
    // quicksort(array, 0, size - 1);
    // array_print(array, size);

    printf("*** Mergesort ***\n");
    merge_sort(array, size);
    array_print(array, size);

    // Searching
    binary_search(array, size, 8);

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

int binary_search(int *array, int size, int key)
{
    int lo = 0;
    int hi = size - 1;

    while (lo <= hi)
    {
        int mid = lo + (hi - lo) / 2;

        if (key == array[mid])
        {
            printf("Found key at %d\n", mid);
            return mid;
        }
        if (key < array[mid])
        {
            hi = mid - 1;
        }
        else
        {
            lo = mid + 1;
        }
    }
    printf("No key found\n");
    return -1;
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

void merge_sort(int *array, int size)
{
    if (size < 2)
    {
        return;
    }

    int mid = size / 2;

    int l_array[mid];
    int r_array[size - mid];

    for (int i = 0; i < mid; i++)
    {
        l_array[i] = array[i];
    }
    for (int i = mid; i < size; i++)
    {
        r_array[i - mid] = array[i];
    }

    merge_sort(l_array, mid);
    merge_sort(r_array, size - mid);

    merge(array, l_array, r_array, mid, size - mid);
}

/* Given a left and right array combine them to create 1 sorted array */
void merge(int *parent_array, int l_array[], int r_array[], int l_size, int r_size)
{
    int i, j, k = 0;

    while (i < l_size && j < r_size)
    {
        if (l_array[i] <= r_array[j])
        {
            parent_array[k] = l_array[i];
            i++;
        }
        else
        {
            parent_array[k] = r_array[j];
            j++;
        }
        k++;
    }

    // Clean up
    while (i < l_size)
    {
        parent_array[k] = l_array[i];
        i++;
        k++;
    }
    while (j < r_size)
    {
        parent_array[k] = r_array[j];
        j++;
        k++;
    }
}

void quicksort(int *array, int lo, int hi)
{
    // Detects if the inputted array bounds are equal to 1
    if (lo >= hi)
    {
        return;
    }
    // Sort the array and return a partition for the next array bounds
    int partition = quicksort_partition(array, lo, hi);
    quicksort(array, lo, partition - 1);
    quicksort(array, partition + 1, hi);
}

int quicksort_partition(int *array, int lo, int hi)
{
    int pivot = array[hi];
    // Index needs to start outside, left of the array bounds
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
