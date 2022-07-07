#include "data_io.h"
#include <stdio.h>

int input(double *data, int *n) {
    int test, out = 1;
    char sim;
    test = scanf("%d%c", n, &sim);
    if (test != 2 || sim != '\n' || *n <= 0) {
        out = 0;
    } else {
        for (double *p = data; p - data < *n; p++) {
            if (scanf("%lf", p) != 1) {
                out = 0;
                break;
            }
        }
    }
    return out;
}

void output(double *data, int n) {
    for (double *p = data; p - data < n; p++) {
        if (p - data < n-1) {
            printf("%.2lf ", *p);
        }
        if (p - data == n-1) {
            printf("%.2lf", *p);
        }
    }
}
