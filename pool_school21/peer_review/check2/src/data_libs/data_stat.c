#include "data_stat.h"
#include <stdio.h>

double max(double *data, int n) {
    double max_v = data[0];
    for (int i = 1; i < n; i++) {
        if (data[i] > max_v)
            max_v = data[i];
    }
    return max_v;
}

double min(double *data, int n) {
    double min_v = data[0];
    for (int i = 1; i < n; i++) {
        if (data[i] < min_v)
            min_v = data[i];
    }
    return min_v;
}

double mean(double *data, int n) {
    double mean_v = 0;
    for (int i = 0; i < n; i++) {
        mean_v = mean_v + data[i];
    }
    return mean_v/n;
}

double variance(double *data, int n) {
    double variance_v = 0;
    double m = mean(data, n);
    for (int i = 0; i < n; i++) {
        variance_v = variance_v + (data[i] - m) * (data[i] - m);
    }
    return variance_v/n;
}
