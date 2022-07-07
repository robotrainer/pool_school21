#include <stdio.h>
#include "data_process.h"
#include "../data_libs/data_io.h"
    // gcc data_module_entry.c data_process.c ../data_libs/data_io.c
    // ../data_libs/data_stat.c
int main() {
    double *data = (double*)malloc(sizeof(double));
    int n, flag = 0;
    // Don`t forget to allocate memory !

    input(data, &n, &flag);
    if (flag == 0) {
        if (normalization(data, n)) {
            output(data, n);
        } else {
            printf("ERROR");
        }
    } else {
        printf("n/a");
    }
    free(data);
    return 0;
}
