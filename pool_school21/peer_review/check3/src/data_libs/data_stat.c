#include "data_stat.h"

double max(double *data, int n) {
  double max = *data;
  for (double *p = data; p - data < n; p++) {
    if (*p > max) max = *p;
  }
  return max;
}
double min(double *data, int n) {
  double min = *data;
  for (double *p = data; p - data < n; p++) {
    if (*p < min) min = *p;
  }
  return min;
}
double mean(double *data, int n) {
  double mean;
  for (double *p = data; p - data < n; p++) {
    mean = *p * 1.0 / n + mean;
  }
  return mean;
}
double variance(double *data, int n) {
  double varianceF;
  double varianceV;
  double mean;
  for (double *p = data; p - data < n; p++) {
    mean = *p * 1.0 / n + mean;
  }
  for (double *p = data; p - data < n; p++) {
    varianceV = *p * *p * 1.0 / n + varianceV;
  }
  varianceF = varianceV - mean * mean;
  return varianceF;
}
