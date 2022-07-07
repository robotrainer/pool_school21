#include <stdio.h>
#include <math.h>
#define NMAX 30

int input(int *a, int *n);
double mean(int *a, int n);
double variance(int *a, int n);
int find_number(int *a, int n, double mean_v, double variance_v);

int main() {
    int n, data[NMAX];
    int result;

    result = input(data, &n);
    if (!result) {
        printf("%d", find_number(data, n, mean(data, n), variance(data, n)));
    } else {
        printf("n/a");
        return 1;
    }
    return 0;
}

int input(int *a, int *n) {
    scanf("%d", n);
    if (*n <= NMAX && *n > 0) {
        char ch;
        for (int *p = a; p - a < *n; p++) {
            scanf("%d", p);
            ch = getchar();
            if (ch != ' ') {
                if (ch == '\n' && p - a + 1 == *n) {
                    return 0;
                } else {
                    return 1;
                }
            }
        }
    }
    return 1;
}

double mean(int *a, int n) {
    double sum = 0;
    for (int *p = a; p - a < n; p++) {
        sum += (*p);
    }
    return sum / n;
}

double variance(int *a, int n) {
    double sum = 0;
    for (int *p = a; p - a < n; p++) {
        sum += pow((*p) - mean(a, n), 2);
    }
    return sum / n;
}

int find_number(int *a, int n, double mean_v, double variance_v) {
    for (int *p = a; p - a < n; p++) {
        if (*p % 2 == 0 && *p >= mean_v && *p != 0 &&\
            *p <= mean_v + 3 * sqrt(variance_v)) {
            return *p;
        }
    }
    return 0;
}
