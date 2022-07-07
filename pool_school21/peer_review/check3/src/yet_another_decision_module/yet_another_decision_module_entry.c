#include <stdio.h>
#include <stdlib.h>

#include "../data_libs/data_io.h"
#include "../data_libs/data_stat.h"
#include "decision.h"

int main() {
  double *data;
  int n;

  scanf("%d", &n);
  data = (double *)malloc(n * sizeof(double));
  input(data, n);

  if (make_decision(data, n)) {
    // output(data, n);

    printf("YES");
  } else {
    printf("NO");
  }
  free(data);
}
