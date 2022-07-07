#include "decision.h"
#include "../data_libs/data_io.h"
    /*
        gcc yet_another_decision_module_entry.c 
        ../data_libs/data_io.c ../data_libs/data_stat.c decision.c
    */
int main() {
    int n, flag = 0;
    double *data = (double*)malloc(sizeof(double));
    input(data, &n, &flag);
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
