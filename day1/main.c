#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "quicksort.h"
#include "hashmap.h"

void readFile(char file[]); // Open & read file contents into file array
void tokenizeToInt(int nums[], char file[]); // Split array into tokens & store separate items in diff array
void splitTokens(int nums[], int leftArray[], int rightArray[], int n); // Split nums into two separate arr
int sumArrays(int leftArray[], int rightArray[]);



int main(void)
{
  char file[14000] = {0};
  readFile(file);

  int nums[2000] = {0};
  tokenizeToInt(nums, file);

  int leftArray[1000] = {0};
  int rightArray[1000] = {0};
  splitTokens(nums, leftArray, rightArray, (sizeof(nums) / sizeof(nums[0])));

  quicksort(leftArray, 0, (sizeof(leftArray) / sizeof(leftArray[0])) - 1);
  quicksort(rightArray, 0, (sizeof(rightArray) / sizeof(rightArray[0])) - 1);

  // Answer to part 1
  // printf("%d\n",sumArrays(leftArray, rightArray));
  
  // Answer to part 2
  initMap();

  for (size_t i = 0; i < TABLE_SIZE; i++)
  {
    location temp = {.locationID = leftArray[i], .count = 0};
    addToMap(&temp);
  }

  printMap();

  // location *temp = searchMap(leftArray[0]);

  // if (temp == NULL)
  // {
  //   printf("Not Found");
  // }
  // else
  // {
  //   printf("Found");
  // }
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

void splitTokens(int nums[], int leftArray[], int rightArray[], int n)
{
  int j = 0, k = 0;
  for (size_t i = 0; i < n; i++)
  {
    if (i % 2 == 0)
    {
      leftArray[j] = nums[i];
      j++;
    }
    else if (i % 2 == 1)
    {
      rightArray[k] = nums[i];
      k++;
    }
  }
}

int sumArrays(int leftArray[], int rightArray[])
{
  int sum = 0;

  for (size_t j = 0; j < 1000; j++)
  {
    sum += abs(leftArray[j] - rightArray[j]);
  }
  return sum;
}


