#include <stdio.h>
#include <math.h>
#define NMAX 10

int input(int *a, int *n);
void output(int *a, int n);
int max(int *a, int n);
int min(int *a, int n);
double mean(int *a, int n);
double variance(int *a, int n);

void output_result(int max_v,
                   int min_v,
                   double mean_v,
                   double variance_v);

int main() {
    int n, data[NMAX];
    int result;

    result = input(data, &n);
    if (!result) {
        output(data, n);
        output_result(max(data, n),
                      min(data, n),
                      mean(data, n),
                      variance(data, n));
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

void output(int *a, int n) {
    for (int *p = a; p - a < n; p++) {
        printf("%d", *p);
        if (p - a + 1 < n)
            printf(" ");
    }
}


int max(int *a, int n) {
    int max = *(a + 0);
    for (int *p = a; p - a < n; p++) {
        if (*p > max)
            max = *p;
    }
    return max;
}

int min(int *a, int n) {
    int min = *(a + 0);
    for (int *p = a; p - a < n; p++) {
        if (*p < min)
            min = *p;
    }
    return min;
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

void output_result(int max_v,
                   int min_v,
                   double mean_v,
                   double variance_v) {
    printf("\n%d %d %.6f %.6f", max_v, min_v, mean_v, variance_v);
}
