#ifndef Libpa_H
#define Libpa_H

/* Create an array filled with random numbers*/
int *array_create_random(int size, int min, int max);
/* Print the contents of an array of integers */
void array_print(int *array, int size);

/* Searching */
int binary_search(int *array);

/* Sorting */
int bubble_sort(int *array);
int selection_sort(int *array);
int insertion_sort(int *array);
int merge_sort(int *array);
int quick_sort(int *array);

#endif