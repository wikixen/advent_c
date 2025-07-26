#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "quicksort.h"

void readFile(char file[]); // Open & read file contents into file array
void tokenizeToInt(int nums[], char file[]); // Split array into tokens & store separate items in diff array

int main(void) {
  char file[14000] = {0};
  readFile(file);

  int nums[2000] = {0};
  tokenizeToInt(nums, file);

  // Split nums into two separate arr
  int list1[1000] = {0};
  int list2[1000] = {0};
  int j = 0, k = 0;
  for (size_t i = 0; i < (sizeof(nums)/sizeof(nums[0])); i++)
  {
    if (i%2==0)
    {
      list1[j] = nums[i];
      j++;
    } 
    else if(i%2==1) 
    {
      list2[k] = nums[i];
      k++;
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

void readFile(char file[]) {
  FILE *fp = fopen("/home/bennyhernandez/Code/advent_c/day1/input.txt", "r");

  int c, i = 0;
  while ((c = fgetc(fp)) != EOF)
  {
    file[i] = c;
    i++;
  }
  fclose(fp);
}

void tokenizeToInt(int nums[], char file[])
{
  char delimit[] = "\t\r\n\v\f '   '";
  char *token = strtok(file, delimit);
  int i = 0;
  while (token)
  {
    nums[i] = atoi(token);
    token = strtok(NULL, delimit);
    i++;
  }
}
