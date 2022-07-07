#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "door_struct.h"

#define DOORS_COUNT 15
#define MAX_ID 100000

int main() {
  struct door doors[DOORS_COUNT];

  initialize_doors(doors);
  sort(doors, DOORS_COUNT);
  output(doors, DOORS_COUNT);

  return 0;
}

// Doors initialization function
// ATTENTION!!!
// DO NOT CHANGE!
void initialize_doors(struct door* doors) {
  srand(time(0));

  int seed = rand() % MAX_ID;
  for (int i = 0; i < DOORS_COUNT; i++) {
    doors[i].id = (i + seed) % MAX_ID;
    doors[i].status = rand() % 2;
  }
}

void sort(struct door* doors, int n) {
  int first_door;
  for (int i = 0; i < n; i++) {
    for (int j = i; j < n - 1 - i; j++) {
      if (doors[j].id > doors[j + 1].id) {
        first_door = doors[j + 1].id;
        doors[j + 1].id = doors[j].id;
        doors[j].id = first_door;
      }
    }
  }
}

void output(struct door* doors, int n) {
  for (int i = 0; i < n; i++) {
    printf("%d, %d", doors[i].id, doors[i].status);
    if (i != n - 1) printf("\n");
  }
}
