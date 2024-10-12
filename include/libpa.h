#ifndef Libpa_H
#define Libpa_H

/* Create an array filled with random numbers*/
int *array_create_random(int size, int min, int max);
/* Print the contents of an array of integers */
void array_print(int *array, int size);

/* Searching */
int binary_search(int *array, int size);

/* Sorting */
int bubble_sort(int *array, int size);
int selection_sort(int *array, int size);
int insertion_sort(int *array, int size);
int merge_sort(int *array, int size);
void quicksort(int *array, int lo, int hi);
int quicksort_partition(int *array, int lo, int hi);

#endif