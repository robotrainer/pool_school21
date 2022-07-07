#include <stdio.h>
#include <stdlib.h>

#include "../data_libs/data_io.h"
#include "decision.h"

int main() {
  double *data;
  int n;
  char trigger;
  if (scanf("%d%c", &n, &trigger) == 2 && trigger == '\n' && n != 0) {
    // Don`t forget to allocate memory !
    data = (double *)malloc(n * sizeof(double));
    input(data, n);
    if (make_decision(data, n)) {
      printf("YES");
    } else {
      printf("NO");
    }
    free(data);
  } else {
    printf("n/a");
  }
}
