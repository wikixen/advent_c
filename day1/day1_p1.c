#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void quicksort(int array[], int start, int end);
int partition(int array[], int start, int end);
void swap(int *a, int *b);

int main(void) {
  // Open & read file contents into file array
  FILE *fp = fopen("input.txt", "r");

  int c, i=0;
  char file[14000] = {0};
  while ((c = fgetc(fp)) != EOF){
    file[i] = c;
    i++;
  }
  i = 0;
  fclose(fp);

  // Split array into tokens & store separate items in diff array
  char delimit[] = "\t\r\n\v\f '   '";
  char *token = strtok(file, delimit);
  int nums[2000] = {0};
  while (token)
  {
    nums[i] = atoi(token);
    token = strtok(NULL, delimit);
    i++;
  }
  i = 0;

  // Split nums into two separate arr
  int list1[1000] = {0};
  int list2[1000] = {0};
  int k = 0;
  for (size_t j = 0; j < (sizeof(nums)/sizeof(nums[0])); j++)
  {
    if (j%2==0)
    {
      list1[i] = nums[j];
      i++;
      // printf("%d\t", nums[j]);
    } 
    else if(j%2==1) 
    {
      list2[k] = nums[j];
      k++;
      // printf("%d\n", nums[j]);
    }
  }

  // Sorting
  quicksort(list1, 0, (sizeof(list1) / sizeof(list1[0])) - 1);
  quicksort(list2, 0, (sizeof(list2) / sizeof(list2[0])) - 1);

  int sum = 0;
  for (size_t j = 0; j < 1000; j++)
  {
    sum += abs(list1[j] - list2[j]);
  }
  printf("%d\n",sum);
}

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
    if (array[j]<pivot)
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
