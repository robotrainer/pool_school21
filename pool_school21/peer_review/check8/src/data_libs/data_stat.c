#include "data_stat.h"

#include <stdio.h>
double max(double *data, int n) {
  double max_v = *data;
  for (int i = 0; i < n; i++) {
    if (data[i] > max_v) {
      max_v = data[i];
    }
  }
  return max_v;
}

double min(double *data, int n) {
  double min_v = *data;
  for (int i = 0; i < n; i++) {
    if (data[i] < min_v) {
      min_v = data[i];
    }
  }
  return min_v;
}

double mean(double *data, int n) {
  double smean = 0;
  double mean_v;
  for (int i = 0; i < n; i++) {
    smean = smean + data[i];
  }
  mean_v = smean / n;
  return mean_v;
}

double variance(double *data, int n) {
  double var_v;
  double svar = 0;
  double q = mean(data, n);
  for (int i = 0; i < n; i++) {
    svar = svar + ((data[i]) * (data[i]));
  }
  var_v = svar / n - q * q;
  return var_v;
}

void sort(double *data, int n) {
  for (int i = 0; i < n - 1; i++) {
    for (int j = 0; j < n - 1; j++) {
      if (data[j] > data[j+1]) {
        int temp = data[j];
        data[j] = data[j+1];
        data[j+1] = temp;
      }
    }
  }
}