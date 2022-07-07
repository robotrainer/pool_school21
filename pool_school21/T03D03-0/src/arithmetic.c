#include <stdio.h>

int sum(int a, int b);
int difference(int a, int b);
int product(int a, int b);
int quotient(int a, int b);

int main(void) {
    float a = 0;
    float b = 0;

    printf("Введите два целых числа через пробел:\n");
    scanf("%f %f", &a, &b);

    if ((float)((int)a) == a && (float)((int)b) == b) {
        printf("%d %d %d ", sum(a, b), difference(a, b), product(a, b));
        if (b != 0) {
            printf("%d\n", quotient(a, b));
        } else {
            printf("n/a\n");
        }
    } else {
        printf("Вы ввели не целое число!\n");
    }

    return (0);
}

int sum(int a, int b) {
    return (a + b);
}

int difference(int a, int b) {
    return (a - b);
}

int product(int a, int b) {
    return (a * b);
}

int quotient(int a, int b) {
    return (a / b);
}
