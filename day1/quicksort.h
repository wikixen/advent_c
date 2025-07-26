/**
 * Handmade quicksort that I made cause I didn't realize
 * stdlib already has qsort :)
 */
#include <stdio.h>
#include <stdlib.h>

void quicksort(int array[], int start, int end);
int partition(int array[], int start, int end);
void swap(int *a, int *b);

void quicksort(int array[], int start, int end)
{
  if (start < end)
  {
    int pivot = partition(array, start, end);

    quicksort(array, start, pivot - 1);
    quicksort(array, pivot + 1, end);
  }
}

int partition(int array[], int start, int end)
{
  int pivot = array[end];
  int i = start - 1;

  for (size_t j = start; j < end; j++)
  {
    if (array[j] < pivot)
    {
      i++;
      swap(&array[i], &array[j]);
    }
  }

  i++;
  swap(&array[i], &array[end]);
  return i;
}

void swap(int *a, int *b)
{
  int temp = *a;
  *a = *b;
  *b = temp;
}
