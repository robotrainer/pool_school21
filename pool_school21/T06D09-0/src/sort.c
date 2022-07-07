#include <stdio.h>
#define NMAX 10

int input(int *a);
void output(int *a);
void sort(int *a);

int main() {
    int data[NMAX], result;
    result = input(data);
    if (result) {
        sort(data);
        output(data);
    } else {
        printf("n/a");
    }
    return 0;
}

int input(int *a) {
    int rtn = 0;
    for (int *p = a; p - a < NMAX; p++) {
        char ch;
        if (scanf("%d", p) != 1) break;
        ch = getchar();
        if (ch != ' ') {
            if (ch == '\n' && p - a + 1 == NMAX) {
                rtn = 1;
                break;
            }
        }
    }
    return rtn;
}

void output(int *a) {
    for (int *p = a; p - a < NMAX; p++) {
        printf("%d", *p);
        if (p - a + 1 != NMAX)
            printf(" ");
    }
}

void sort(int *a) {
    int numder;
    for (int *p = a; p - a < NMAX - 1; p++) {
        for (int *i = a; i - a < NMAX - 1; i++) {
            if (*i > *(i + 1)) {
                numder = *(i + 1);
                *(i + 1) = *i;
                *i = numder;
            }
        }
    }
}
