#include <stdio.h>
#define NMAX 10

int input(int *buffer, int *length, int *number);
void output(int *buffer, int length);
int cycle_shift(int *buffer, int length, int number);

int main() {
    int n, data[NMAX], number;
    int result = input(data, &n, &number);

    if (result) {
        cycle_shift(data, n, number);
        output(data, n);
    } else {
        printf("n/a");
    }

    return 0;
}

int input(int *buffer, int *length, int *number) {
    int rtn = 0;
    scanf("%d", length);
    if (*length <= NMAX && *length > 0) {
        char ch;
        for (int *p = buffer; p - buffer < *length; p++) {
            if (scanf("%d", p) != 1) break;
            ch = getchar();
            if (ch != ' ') {
                if (ch == '\n' && p - buffer + 1 == *length) {
                    char ch_;
                    if (scanf("%d%c", number, &ch_) == 2 && ch_ == '\n') {
                        rtn = 1;
                        break;
                    }
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

int cycle_shift(int *buffer, int length, int number) {
    int n = number % length;
    if (n >= 0) {
        int tmp[NMAX];
        for (int i = 0; i < n; ++i) {
            tmp[i] = buffer[i];
        }
        for (int i = 0; i < length; ++i) {
            if (i >= length - n) {
                buffer[i] = tmp[i - (length - n)];
            } else {
                buffer[i] = buffer[i + n];
            }
        }
    } else {
        n = (-1) * n;
        int tmp[NMAX];
        for (int i = 0; i < n; ++i) {
            tmp[i] = buffer[length - 1 - i];
        }
        for (int i = length - 1; i > 0; --i) {
            buffer[i] = buffer[i-n];
        }
        for (int i = 0; i < n; ++i) {
            buffer[i] = tmp[n - 1 -i];
        }
    }
    return 0;
}
