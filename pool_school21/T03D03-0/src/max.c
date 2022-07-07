#include <stdio.h>

int main(void) {
    int a, b;

    printf("Введите два числа через пробел:\n");
    scanf("%d%d", &a, &b);

    if ((char)a == a && (char)b == b) {
        if (a > b)
            printf("%d", a);
    } else {
    printf("n/a\n");
    }

    return (0);
}
