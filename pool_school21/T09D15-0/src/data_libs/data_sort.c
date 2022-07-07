#include "data_sort.h"

void sort(double *data, int n) {
  double x = data[0];
  for (int i = 0; i < n - 1; i++) {
    for (int j = 0; j < n - 1; j++) {
      if (data[j] > data[j + 1]) {
        x = data[j + 1];
        data[j + 1] = data[j];
        data[j] = x;
      }
    }
  }
}
