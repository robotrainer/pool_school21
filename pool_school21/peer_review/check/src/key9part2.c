/* Copyright 2021 <Cbasmati> */
#include <stdio.h>
#define LEN 100

int input(int *buffer, int *length);
void output(int *buffer, int length);
void sum(int *buff1, int len1, int *buff2,
        int len2, int *result, int *result_length);
void sub(int *buff1, int len1, int *buff2,
        int len2, int *result, int *result_length);
void swap(int *v1, int *v2);
void clear_buffer(int *buffer, int min, int max);
void remove_zeros(int *buffer, int *length);
int check_sum(int *buff1, int len1, int *buff2, int len2);
int check_sub(int *buff1, int len1, int *buff2, int len2);

int main() {
    int len1 = 0;
    int len2 = 0;
    int result_length;
    int buff1[LEN];
    int buff2[LEN];
    int result[LEN];
    int check = 1;
    if (!input(buff1, &len1)) {
        check = 0;
    }
    if (check) {
        if (!input(buff2, &len2)) {
            check = 0;
        }
    }
    if (check) {
        result_length = 0;
        clear_buffer(result, 0, LEN);
        if (check_sum(buff1, len1, buff2, len2)) {
            sum(buff1, len1, buff2, len2, result, &result_length);
            output(result, result_length);
        } else {
            printf("n/a\n");
        }
        result_length = 0;
        clear_buffer(result, 0, LEN);
        if (check_sub(buff1, len1, buff2, len2)) {
            sub(buff1, len1, buff2, len2, result, &result_length);
            remove_zeros(result, &result_length);
            clear_buffer(result, result_length + 1, LEN);
            if (result_length == 0) {
                result_length = 1;
                *result = 0;
            }
            output(result, result_length);
        } else {
            printf("n/a");
        }
    }
    if (!check) {
        printf("n/a");
    }
    return 1;
}

int input(int *buffer, int *length) {
    char digit, space;
    int check = 1;
    while (1) {
        if (scanf("%c%c", &digit, &space) != 2) {
            check = 0;
            break;
        }
        if ((digit < '0') || (digit > '9')) {
            check = 0;
            break;
        }
        *(buffer + *length) = (digit - '0');
        if (space == '\n') {
            (*length)++;
            break;
        }
        if (space != ' ') {
            check = 0;
            break;
        }
        (*length)++;
        if (*length >= LEN) {
            check = 0;
            break;
        }
    }
    remove_zeros(buffer, length);
    clear_buffer(buffer, *length + 1, LEN);
    return check;
}

void output(int *buffer, int length) {
    for (int *p = buffer; p - buffer < length; p++) {
        if (*p == EOF) {
            break;
        }
        printf("%d", *p);
        if (p - buffer < length) {
            printf(" ");
        }
    }
    printf("\n");
}

void sum(int *buff1, int len1, int *buff2,
        int len2, int *result, int *result_length) {
    int l;
    int r;
    int current_result = 0;
    int next_add = 0;
    if (len1 >= len2) {
        for (l = len1 - 1; l >= 0; l--) {
            if (l - (len1 - len2) < 0) {
                current_result = *(buff1 + l) + next_add;
            } else {
                current_result = (*(buff1 + l) +
                    *(buff2 + l - (len1 - len2))) + next_add;
            }
            next_add = current_result / 10;
            current_result = current_result % 10;
            *(result + *result_length) = current_result;
            (*result_length)++;
        }
    } else {
        for (l = len2 - 1; l >= 0; l--) {
            if (l - (len2 - len1) < 0) {
                current_result = *(buff2 + l) + next_add;
            } else {
                current_result = (*(buff2 + l) +
                    *(buff1 + l - (len2 - len1))) + next_add;
            }
            next_add = current_result / 10;
            current_result = current_result % 10;
            *(result + *result_length) = current_result;
            (*result_length)++;
        }
    }
    if (next_add) {
        *(result + *result_length) = next_add;
        (*result_length)++;
    }
    for (r = 0; r < *result_length / 2; r++) {
        swap((result + r), (result + *result_length - r - 1));
    }
}

void sub(int *buff1, int len1, int *buff2,
        int len2, int *result, int *result_length) {
    int l;
    int r;
    int current_result = 0;
    int next_sub = 0;
    if (len1 >= len2) {
        for (l = len1 - 1; l >= 0; l--) {
            if (l - (len1 - len2) < 0) {
                current_result = *(buff1 + l) + next_sub;
            } else {
                current_result = (*(buff1 + l) -
                    *(buff2 + l - (len1 - len2))) + next_sub;
            }
            next_sub = 0;
            if (current_result < 0) {
                current_result = current_result + 10;
                next_sub = -1;
            }
            *(result + *result_length) = current_result;
            (*result_length)++;
        }
    } else {
        for (l = len2 - 1; l >= 0; l--) {
            if (l - (len2 - len1) < 0) {
                current_result = *(buff2 + l) + next_sub;
            } else {
                current_result = (*(buff2 + l) -
                    *(buff1 + l - (len2 - len1))) + next_sub;
            }
            next_sub = 0;
            if (current_result < 0) {
                current_result = current_result + 10;
                next_sub = -1;
            }
            *(result + *result_length) = current_result;
            (*result_length)++;
        }
    }
    for (r = 0; r < *result_length / 2; r++) {
        swap((result + r), (result + *result_length - r - 1));
    }
}

void swap(int *v1, int *v2) {
    int temp;
    temp = *v2;
    *v2 = *v1;
    *v1 = temp;
}

void clear_buffer(int *buffer, int min, int max) {
    for (int i = min; i < max; i++) {
        *(buffer + i) = EOF;
    }
}

void remove_zeros(int *buffer, int *length) {
    int i;
    int zero_count = 0;
    for (i = 0; i < *length; i++) {
        if (*(buffer + i) != 0) {
            break;
        }
        zero_count++;
    }
    for (i = 0; i < *length - zero_count; i++) {
        *(buffer + i) = *(buffer + i + zero_count);
    }
    *length = *length - zero_count;
}

int check_sum(int *buff1, int len1, int *buff2, int len2) {
    int l = 0;
    int next_add = 0;
    int check = 1;
    if ((len1 == LEN) && (len2 == LEN)) {
        for (l = 0; l < len1; l++) {
            if (*(buff1 + l) + *(buff2 + l) + next_add >= 10) {
                next_add = 1;
            } else {
                next_add = 0;
            }
        }
        if (next_add) {
            check = 0;
        }
    }
    return check;
}

int check_sub(int *buff1, int len1, int *buff2, int len2) {
    int l = 0;
    int check = 1;
    int check_sub = 0;
    int result = 0;
    if (len1 == len2) {
        for (l = 0; l < len1; l++) {
            result = *(buff1 + l) - *(buff2 + l);
            if (result < 0) {
                check_sub--;
            }
            if (result > 0) {
                check_sub++;
            }
        }
    }
    if (check_sub < 0) {
        check = 0;
    }
    if (check) {
        if (len2 > len1) {
            check = 0;
        }
    }
    return check;
}
