#include "s21_string.h"
#include <stdio.h>
#include <stdlib.h>

int s21_strlen(const char *data) {
    const char *c = data;

    if (data == NULL)
        return -1;

    while (*data != '\0') {
        data++;
    }

    return data - c;
}

int s21_strcmp(const char *s1, const char *s2) {
    int minlen;
    int l1 = s21_strlen(s1);
    int l2 = s21_strlen(s2);

    if (l1 < l2)
        minlen = l1;
    else
        minlen = l2;

    for (int i = 0; i < minlen; i++) {
        if (s1[i] != s2[i])
            return s1[i] - s2[i];
    }

    if (l1 == l2)
        return 0;
    else if (l1 < l2)
        return 0 - (int)s2[minlen];
    else
        return (int)s1[minlen];
}

char* s21_strcpy(char *dest, const char *source) {
    int n = s21_strlen(source);

    for (int i = 0; i <= n; i++) {
        dest[i] = source[i];
    }

    return dest;
}

