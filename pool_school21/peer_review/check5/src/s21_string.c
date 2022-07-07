#include <stdio.h>
#include "s21_string.h"

int s21_strlen(char *str) {
    int length = 0;
    for(; *(str + length);length++);
    return length;
}
