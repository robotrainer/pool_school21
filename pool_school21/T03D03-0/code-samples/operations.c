/*
Программа, рассчитывающая сумму и произведение введенных чисел
*/

#include <stdio.h>

int sum(int a, int b);
int mul(int a, int b);

void main(){
    int x, y;
    scanf("%d %d", &x, &y);
    printf("%d %d", sum(x, y), mul(x, y));
}

int sum(int a, int b){
    return a + b;
}

int mul(int a, int b){
    return a * b;
}
