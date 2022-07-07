#include <stdio.h>

int main() {
  double *data;
  int n;

  printf("LOAD DATA...\n");
  input(data, n);

  printf("RAW DATA:\n\t");
  output(data, n);

  printf("\nNORMALIZED DATA:\n\t");
  normalisation(data, n);
  output(data, n);

  printf("\nSORTED NORMALIZED DATA:\n\t");
  sort(data, n);
  output(data, n);

  printf("\nFINAL DECISION:\n\t");
  make_decision(data, n);
}
