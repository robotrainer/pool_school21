/* Copyright 2021 <Cbasmati> */
#include <stdio.h>
#define NMAX 10

int get_length(int *length);
int get_shift(int *shift);
int input(int *buffer, int *length);
void output(int *buffer, int length);
void shift_numbers(int *buffer, int length, int shift);

int main() {
    int length;
    int shift;
    int buffer[NMAX];
    int check = 1;
    if (!get_length(&length)) {
        check = 0;
    }
    if (check) {
        if (!input(buffer, &length)) {
            check = 0;
        }
    }
    if (check) {
        if (!get_shift(&shift)) {
            check = 0;
        }
    }
    if (check) {
        shift = (shift % length);
        if (shift == 0) {
            check = 0;
        }
    }
    if (check) {
        shift_numbers(buffer, length, shift);
        output(buffer, length);
    }
    if (!check) {
        printf("n/a");
    }
    return 1;
}

void shift_numbers(int *buffer, int length, int shift) {
    int i;
    int tmp;
    if (shift > 0) {
        for (i = 0; i < shift; i++) {
            tmp = *buffer;
            for (int *p = buffer; (p - buffer) < (length - 1); p++) {
                *p = *(p + 1);
            }
            *(buffer + length - 1) = tmp;
        }
    } else {
        shift = -shift;
        for (i = 0; i < shift; i++) {
            tmp = *(buffer + length - 1);
            for (int *p = (buffer + length - 1); (p - buffer) > 0; p--) {
                *p = *(p - 1);
            }
            *buffer = tmp;
        }
    }
}

int input(int *buffer, int *length) {
    char str[100];
    int input_count = 0;
    int check = 1;
    for (int *p = buffer; p - buffer < *length; p++) {
        if (scanf("%d", p) == 1) {
            input_count++;
        }
    }
    if (input_count != *length) {
        check = 0;
    }
    if (check) {
        if (scanf("%[^\n]", str)) {
            check = 0;
        }
    }
    return check;
}

void output(int *numbers, int length) {
    for (int *p = numbers; p - numbers < length; p++) {
        printf("%d", *p);
        if (p - numbers < length - 1) {
            printf(" ");
        }
    }
    printf("\n");
}

int get_length(int *length) {
    int check = 1;
    if (scanf("%d", length) != 1) {
        check = 0;
    }
    if (check) {
        if ((*length < 1) || (*length > NMAX)) {
            check = 0;
        }
    }
    return check;
}

int get_shift(int *shift) {
    int check = 1;
    if (scanf("%d", shift) != 1) {
        check = 0;
    }
    return check;
}
