#include <stdio.h>
#include <stdlib.h>

#include "decision.h"
#include "../data_libs/data_io.h"

int main() {
    double *data;
    int n;

    data = (double *) malloc(n * sizeof(double));
    if (input(data, &n) == 1) {
        if (make_decision(data, n) == 1) {
            printf("YES");
        } else {
            printf("NO");
        }
    } else {
        printf("n/a");
    }
    free(data);
}
