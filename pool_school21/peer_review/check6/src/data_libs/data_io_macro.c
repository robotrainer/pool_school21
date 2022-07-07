#include "data_io_macro.h"

void input_int(int *data, int *n, int *flag) {
    char ch;
    if (scanf("%d%c", n, &ch) != 2 || ch != '\n') {
        *flag = 1;
        return;
    }

    data = (int*)realloc(data, *n * sizeof(int));

    for (int i = 0; i < *n; i++) {
        int num;
        if (scanf("%d", &num) != 1) {
            *flag = 1;
            break;
        }
        data[i] = num;
    }
}

void input_float(float *data, int *n, int *flag) {
    char ch;
    if (scanf("%d%c", n, &ch) != 2 || ch != '\n') {
        *flag = 1;
        return;
    }

    data = (float*)realloc(data, *n * sizeof(float));

    for (int i = 0; i < *n; i++) {
        float num;
        if (scanf("%f", &num) != 1) {
            *flag = 1;
            break;
        }
        data[i] = num;
    }
}

void input_double(double *data, int *n, int *flag) {
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

void input_char(char *data, int *n, int *flag) {
    char ch;
    if (scanf("%d%c", n, &ch) != 2 || ch != '\n') {
        *flag = 1;
        return;
    }

    data = (char*)realloc(data, *n * sizeof(char));

    for (int i = 0; i < *n; i++) {
        char num;
        if (scanf(" %c", &num) != 1) {
            *flag = 1;
            break;
        }
        data[i] = num;
    }
}


void output_double(double *data, int n) {
    for (int i = 0; i < n; i++) {
        printf("%.2lf", data[i]);
        if (i != n - 1) {
            printf(" ");
        }
    }
}

void output_float(float *data, int n) {
    for (int i = 0; i < n; i++) {
        printf("%.2f", data[i]);
        if (i != n - 1) {
            printf(" ");
        }
    }
}

void output_int(int *data, int n) {
    for (int i = 0; i < n; i++) {
        printf("%d", data[i]);
        if (i != n - 1) {
            printf(" ");
        }
    }
}

void output_char(char *data, int n) {
    for (int i = 0; i < n; i++) {
        printf("%c", data[i]);
        if (i != n - 1) {
            printf(" ");
        }
    }
}
