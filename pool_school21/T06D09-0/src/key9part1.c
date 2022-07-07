#include <stdio.h>
#define NMAX 10

int input(int *buffer, int *length);
void output(int *buffer, int length);
int sum_numbers(int *buffer, int length);
int find_numbers(int *buffer, int length, int sum, int *new_buffer);

int main() {
    int n, data[NMAX], new_data[NMAX];

    int result = input(data, &n);
    if (result) {
        int sum = sum_numbers(data, n);
        if (sum > 0) {
            int numbers = find_numbers(data, n, sum, new_data);
            printf("%d\n", sum);
            output(new_data, numbers);
        } else {
        printf("n/a");
        }
    } else {
        printf("n/a");
    }
    return 0;
}

int sum_numbers(int *buffer, int length) {
    int sum = 0;
    for (int *p = buffer; p - buffer < length; p++) {
        if (*p % 2 == 0 && ((p - buffer) % 2) == 0) {
            sum += *p;
        }
    }
    return sum;
}

int input(int *buffer, int *length) {
    int rtn = 0;
    scanf("%d", length);
    if (*length <= NMAX && *length > 0) {
        char ch;
        for (int *p = buffer; p - buffer < *length; p++) {
            if (scanf("%d", p) != 1) break;
            ch = getchar();
            if (ch != ' ') {
                if (ch == '\n' && p - buffer + 1 == *length) {
                    rtn = 1;
                    break;
                }
            }
        }
    }
    return rtn;
}

void output(int *buffer, int length) {
    for (int *p = buffer; p - buffer < length; p++) {
        printf("%d", *p);
        if (p - buffer + 1 < length)
            printf(" ");
    }
}

int find_numbers(int *buffer, int length, int sum, int *new_buffer) {
    int *i = new_buffer;
    int count = 0;
    for (int *p = buffer; p - buffer < length; p++) {
        if (*p != 0 && sum % *p == 0) {
            *(i + count) = *p;
            count++;
            }
    }
    return count;
}
