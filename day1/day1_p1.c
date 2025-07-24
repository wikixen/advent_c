#include <stdio.h>
#include <string.h>
#include <stdlib.h>

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

  // Split nums into two separate arr
  int list1[1000] = {0};
  int list2[1000] = {0};
  for (size_t j = 0; j < sizeof nums; j++)
  {
    if (j%2==0)
    {
      list1[j] = nums[j];
    }
  }
  
}