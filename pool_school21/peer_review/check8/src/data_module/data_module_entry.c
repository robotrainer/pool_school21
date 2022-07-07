#include <stdio.h>
#include <stdlib.h>

#include "../data_libs/data_io.h"
#include "data_process.h"

int main() {
  double *data = NULL;
  int n;
  char trigger;
  if (scanf("%d%c", &n, &trigger) == 2 && trigger == '\n' && n != 0) {
    // Don`t forget to allocate memory !
    data = (double *)malloc(n * sizeof(double));
    input(data, n);
    if (normalization(data, n)) {
      output(data, n);
    } else {
      printf("ERROR");
    }
    free(data);
  } else {
    printf("n/a");
  }
}
