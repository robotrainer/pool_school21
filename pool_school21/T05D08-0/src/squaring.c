#include <stdio.h>
#define NMAX 10

int input(int *a, int *n);
void output(int *a, int n);
void squaring(int *a, int n);

int main() {
    int n, data[NMAX];
    int result;

    result = input(data, &n);
    if (!result) {
        squaring(data, n);
        output(data, n);
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

void squaring(int *a, int n) {
    for (int *p = a; p - a < n; p++) {
        (*p) *= (*p);
    }
}
