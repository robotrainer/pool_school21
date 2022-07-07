#include <stdio.h>
#include "data_sort.h"

void sort(double *data, int n) {
    for (int i = 1; i < n; i++) {
        int k = i;
        while (k > 0 && data[k-1] > data[k]) {
            double v = data[k-1];
            data[k-1] = data[k];
            data[k] = v;
            k = k-1;
        }
    }
}
