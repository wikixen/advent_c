#include <stdbool.h>

#define TABLE_SIZE 1000

typedef struct
{
  int locationID;
  int count;
} location;

location* hashMap[TABLE_SIZE];

void initMap() {
  for (size_t i = 0; i < TABLE_SIZE; i++)
  {
    hashMap[i] = NULL;
  } 
}

bool addToMap(location *l) {
  if (l == NULL) return false;

  int index = l->locationID;
  if (hashMap[index] != NULL) return false;
  
  hashMap[index] = l;
  
  return true;
}

location *searchMap(int locationID) {
  if (hashMap[locationID] != NULL)
  {
    return hashMap[locationID];
  }
  else return NULL;
}

void printMap() {
  for (size_t i = 0; i < TABLE_SIZE; i++)
  {
    if (hashMap[i] == NULL)
    {
      printf("%i\t---\n", i);
    }
    else
    {
      printf("%i\t--%i\n", hashMap[i]->locationID,hashMap[i]->count);
    }
  }
}