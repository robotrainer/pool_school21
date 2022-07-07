#include <stdio.h>
#include <stdlib.h>
#ifdef MACRO
#include "../data_libs/data_io_macro.h"
#else
#include "../data_libs/data_io.h"
#endif
#include "../yet_another_decision_module/decision.h"
#include "../data_module/data_process.h"

int main() {
    int n, flag = 0;
    double *data = (double*)malloc(sizeof(double));
    data[0] = 0;
    printf("LOAD DATA...\n");
    input(data, &n, &flag);

    printf("RAW DATA:\n\t");
    output(data, n);

    printf("\nNORMALIZED DATA:\n\t");
    normalization(data, n);
    output(data, n);

    printf("\nSORTED NORMALIZED DATA:\n\t");
    sort(data, n);
    output(data, n);

    printf("\nFINAL DECISION:\n\t");
    // make_decision(data, n);
    //...
    if (flag == 0) {
        if (make_decision(data, n)) {
        printf("YES");
        } else {
            printf("NO");
        }
    } else {
        printf("n/a");
    }
    free(data);
    return 0;
}
