#include <stdio.h>
#include <stdlib.h>

int input(int *a, int *length);
void output(int *a, int length);
void sort(int *a, int length);

int main() {
    int n, result;
    int *data;
    if (scanf("%d", &n) == 1 && n > 0) {
        data = (int*) calloc(n, sizeof(int));
        if (data != NULL) {
            result = input(data, &n);
            if (result) {
                sort(data, n);
                output(data, n);
            } else {
                printf("n/a");
            }
            free(data);
            *data = 0;
        }
    } else {
        printf("n/a");
    }
    return 0;
}

int input(int *a, int *length) {
    int rtn = 0;
    for (int *p = a; p - a < *length; p++) {
        char ch;
        if (scanf("%d", p) != 1) break;
        ch = getchar();
        if (ch != ' ') {
            if (ch == '\n' && p - a + 1 == *length) {
                rtn = 1;
                break;
            }
        }
    }
    return rtn;
}

void output(int *a, int length) {
    for (int *p = a; p - a < length; p++) {
        printf("%d", *p);
        if (p - a + 1 != length)
            printf(" ");
    }
}

void sort(int *a, int length) {
    int numder;
    for (int *p = a; p - a < length - 1; p++) {
        for (int *i = a; i - a < length - 1; i++) {
            if (*i > *(i + 1)) {
                numder = *(i + 1);
                *(i + 1) = *i;
                *i = numder;
            }
        }
    }
}
