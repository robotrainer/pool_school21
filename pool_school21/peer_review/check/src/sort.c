/* Copyright 2021 <Cbasmati> */
#include <stdio.h>
#define NMAX 10

int input(int *a);
void output(int *a);
void sort(int *a);

int main() {
    int data[NMAX];
    int check = 1;
    if (!input(data)) {
        printf("n/a");
        check = 0;
    }
    if (check) {
        printf("\n");
        sort(data);
        output(data);
    }
    return 0;
}

int input(int *a) {
    char str[100];
    int input_count = 0;
    int check = 1;
    for (int *p = a; p - a < NMAX; p++) {
        if (scanf("%d", p) == 1) {
            input_count++;
        }
    }
    if (input_count != NMAX) {
        check = 0;
    }
    if (check) {
        if (scanf("%[^\n]", str)) {
            check = 0;
        }
    }
    return check;
}

void output(int *a) {
    for (int *p = a; (p - a) < NMAX; p++) {
        printf("%d", *p);
        if ((p - a) < NMAX - 1) {
            printf(" ");
        }
    }
}

void sort(int *a) {
    int i;
    int min_i;
    int tmp_i;
    for (i = 0; i < NMAX - 1; i++) {
        min_i = i;
        for (int *p = (a + i + 1); (p - a) < NMAX ; p++) {
            if (*p < *(a + min_i)) {
                min_i = (p - a);
            }
        }
        tmp_i = *(a + min_i);
        *(a + min_i) = *(a + i);
        *(a + i) = tmp_i;
    }
}
