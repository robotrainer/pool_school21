/* Copyright 2021 <Cbasmati> */
#include <stdio.h>
#define NMAX 10

int input(int *a);
void output(int *a);
void fast_sort(int *a, int n);
void copy_arr(int *a, int *b);
void pyramid_sort(int *a, int n);
void pyramid(int *a, int n, int i);
void swap(int *a, int *b);

int main() {
    int data_a[NMAX];
    int data_b[NMAX];
    int check = 1;
    if (!input(data_a)) {
        printf("n/a");
        check = 0;
    }
    if (check) {
        copy_arr(data_a, data_b);
        pyramid_sort(data_a, NMAX);
        fast_sort(data_b, NMAX);
        output(data_a);
        printf("\n");
        output(data_b);
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

void fast_sort(int *a, int n) {
    int i = 0;
    int j = n - 1;
    int mid = *(a + (n /2));
    int tmp = 0;
    do {
        while (*(a + i) < mid) {
            i++;
        }
        while (*(a + j) > mid) {
            j--;
        }
        if (i <= j) {
            tmp = *(a + i);
            *(a + i) = *(a + j);
            *(a + j) = tmp;
            i++;
            j--;
        }
    } while (i <= j);
    if (j > 0) {
        fast_sort(a, j + 1);
    }
    if (i < n) {
        fast_sort((a + i), n - i);
    }
}

void pyramid_sort(int *a, int n) {
    int i;
    for (i = n / 2 - 1; i >= 0; i--) {
        pyramid(a, n, i);
    }
    for (i = n - 1; i > 0; i--) {
        swap((a), (a + i));
        pyramid(a, i, 0);
    }
}

void pyramid(int *a, int n, int i) {
    int max = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    if ((l < n) && (*(a + l) > *(a + max))) {
        max = l;
    }
    if ((r < n) && (*(a + r) > *(a + max))) {
        max = r;
    }
    if (max != i) {
        swap((a + i), (a + max));
        pyramid(a, n, max);
    }
}

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void copy_arr(int *a, int *b) {
    int i = 0;
    for (int *p = a; (p - a) < NMAX; p++) {
        *(b + i) = *(a + i);
        i++;
    }
}
