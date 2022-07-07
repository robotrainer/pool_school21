#include <stdio.h>
#include <stdlib.h>

#include "../data_libs/data_io.h"
#include "data_process.h"

int main() {
  double *data = NULL;
  int n;

  data = (double *)malloc(n * sizeof(double));
  // Don`t forget to allocate memory !
  if (input(data, &n) == 1) {
    if (normalization(data, n) == 1) {
      output(data, n);
      free(data);
    } else {
      printf("ERROR");
    }
  } else {
    printf("ERROR");
  }
}
