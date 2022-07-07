#include <stdio.h>
#include <stdlib.h>

#include "../data_libs/data_io.h"
#include "decision.h"

int main() {
  double *data = NULL;
  int n;

  scanf("%d", &n);
  data = (double *)calloc(n, sizeof(double));

  input(data, n);

  if (make_decision(data, n))
    printf("YES");
  else
    printf("NO");

  free(data);
  return 0;
}
