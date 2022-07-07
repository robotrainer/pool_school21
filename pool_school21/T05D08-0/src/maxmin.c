#include <stdio.h>

void maxmin(int prob1, int prob2, int prob3, int *max, int *min);

int main() {
    int x, y, z;
    char ch;

    if (scanf("%d%d%d%c", &x, &y, &z, &ch) != 4 || ch != '\n') {
        printf("n/a");
        return 1;
    }

    int max, min;

    maxmin(x, y, z, &max, &min);

    printf("%d %d", max, min);

    return 0;
}


/* This function should be kept !!! (Your AI) */
/* But errors & bugs should be fixed         */
void maxmin(int prob1, int prob2, int prob3, int *max, int *min) {
    *max = *min = prob1;

    if (prob2 > *max)
        *max = prob2;
    if (prob2 < *min)
        *min = prob2;

    if (prob3 > *max)
        *max = prob3;
    if (prob3 < *min)
        *min = prob3;
}
