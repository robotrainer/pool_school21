#include "data_io.h"

#include <stdio.h>

void input(double *data, int n) {
  for (int i = 0; i < n; i++) {
    if (scanf("%lf", &data[i]) != 1) {
      printf("n/a");
      break;
    }
  }
}

void output(double *data, int n) {
  for (int i = 0; i < n; i++) {
    printf("%.2lf ", data[i]);
  }
}
