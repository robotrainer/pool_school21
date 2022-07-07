/* Copyright 2021 <Cbasmati> */
#include <stdio.h>
#define NMAX 10

int get_length(int *length);
int input(int *buffer, int *length);
void output(int *buffer, int length);
int sum_numbers(int *buffer, int length);
int find_numbers(int *buffer, int length, int number, int *numbers);

int main() {
    int Length;
    int number;
    int check = 1;
    int numbers_length = 0;
    if (!get_length(&Length)) {
        check = 0;
    }
    int buffer[Length];
    int numbers[Length];
    if (check) {
        if (!input(buffer, &Length)) {
            check = 0;
        }
    }
    if (check) {
        number = sum_numbers(buffer, Length);
        if (number == 0) {
            check = 0;
        }
    }
    if (check) {
        find_numbers(buffer, Length, number, numbers);
        while (*(numbers + numbers_length) != '\0') {
            numbers_length++;
        }
        if (numbers_length == 0) {
            check = 0;
        }
    }
    if (check) {
        printf("%d\n", number);
        output(numbers, numbers_length);
    }
    if (!check) {
        printf("n/a");
    }
    return 1;
}

int sum_numbers(int *buffer, int length) {
    int sum = 0;
    for (int *p = buffer; p - buffer < length; p++) {
        if ((*p % 2 == 0) && ((p - buffer) % 2 == 0)) {
            sum += *p;
        }
    }
    return sum;
}

int find_numbers(int *buffer, int length, int number, int *numbers) {
    int i = 0;
    int j = 0;
    for (int *p = buffer; p - buffer < length; p++) {
        if ((*p != 0) && (number % *p == 0)) {
            *(numbers + i) = *p;
            i++;
        }
    }
    for (j = i; j < length; j++) {
        *(numbers + j) = '\0';
    }
    return 1;
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
