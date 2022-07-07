#include "data_io.h"

void input(double *data, int *n, int *flag) {
    char ch;
    if (scanf("%d%c", n, &ch) != 2 || ch != '\n') {
        *flag = 1;
        return;
    }

    data = (double*)realloc(data, *n * sizeof(double));

    for (int i = 0; i < *n; i++) {
        double num;
        if (scanf("%lf", &num) != 1) {
            *flag = 1;
            break;
        }
        data[i] = num;
    }
}

void output(double *data, int n) {
    for (int i = 0; i < n; i++) {
        printf("%.2lf", data[i]);
        if (i != n - 1) {
            printf(" ");
        }
    }
}
