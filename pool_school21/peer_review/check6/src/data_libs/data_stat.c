#include "data_stat.h"

double min(double *data, int n) {
    double min = *data;
    for (double *p = data; p - data < n; p++) {
        if (min > *p) {
            min = *p;
        }
    }
    return min;
}

double max(double *data, int n) {
    double max = *data;
    for (double *p = data; p - data < n; p++) {
        if (max < *p) {
            max = *p;
        }
    }
    return max;
}

double mean(double *data, int n) {
    double sum = 0;
    int i;
    for (i = 0; i < n; ++i)
    sum += data[i];
    return sum / n;
}

double variance(double *data, int n) {
    double sum = 0;
    double m = mean(data, n);
    int i;
    for (i = 0; i < n; ++i)
    sum += (data[i] - m) * (data[i] - m);
    return sum / n;
}
