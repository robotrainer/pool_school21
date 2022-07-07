#include "s21_string.h"
#include "s21_string_test.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifdef STRLEN_TEST
#define FUNC() s21_strlen_test()
#endif
#ifdef STRCMP_TEST
#define FUNC() s21_strcmp_test()
#endif
#ifdef STRCPY_TEST
#define FUNC() s21_strcpy_test()
#endif
#ifndef FUNC
#define FUNC() s21_strlen_test()
#endif

int main() {
    FUNC();

    return 0;
}

void output(const char *data, int n) {
    printf("\"");

    for (int i = 0; i < n; i++) {
        if (data[i] == '\0')
            printf("\\0");
        else
            printf("%c", data[i]);
    }

    printf("\"\n");
}

void s21_strlen_test(void) {
    printf("STRLEN TEST\n\n");

    int r1 = s21_strlen(str1);
    output(str1, sizeof(str1));
    printf("length str = %d\n\n", r1);

    int r2 = s21_strlen(str2);
    output(str2, sizeof(str2));
    printf("length str = %d\n\n", r2);

    int r3 = s21_strlen(str3);
    output(str3, sizeof(str3));
    printf("length str = %d\n\n", r3);

    if ((r1 == STR1_LENGTH) && (r2 == STR2_LENGTH) && (r3 == STR3_LENGTH))
        printf("SUCCESS!");
    else
        printf("FAIL");
}

void s21_strcmp_test(void) {
    printf("STRCMP TEST\n\n");

    int r12 = s21_strcmp(str1, str2);
    printf("str1 = ");
    output(str1, sizeof(str1));
    printf("str2 = ");
    output(str2, sizeof(str2));
    printf("strcmp = %d\n\n", r12);

    int r13 = s21_strcmp(str1, str3);
    printf("str1 = ");
    output(str1, sizeof(str1));
    printf("str3 = ");
    output(str3, sizeof(str3));
    printf("strcmp = %d\n\n", r13);

    int r23 = s21_strcmp(str2, str3);
    printf("str2 = ");
    output(str2, sizeof(str2));
    printf("str3 = ");
    output(str3, sizeof(str3));
    printf("strcmp = %d\n\n", r23);

    if ((r12 == STR_CMP_12) && (r13 == STR_CMP_13) && (r23 == STR_CMP_23))
        printf("SUCCESS!");
    else
        printf("FAIL");
}

void s21_strcpy_test(void) {
    char str[13] = "123";
    printf("STRCPY TEST\n\n");

    printf("str = ");
    output(str, sizeof(str));
    printf("str2 = ");
    output(str2, sizeof(str2));
    s21_strcpy(str, str2);
    printf("result string = ");
    output(str, sizeof(str));
    int cmp12 = s21_strcmp(str, str2);
    printf("\n");

    printf("str = ");
    output(str, sizeof(str));
    printf("str3 = ");
    output(str3, sizeof(str3));
    s21_strcpy(str, str3);
    printf("result string = ");
    output(str, sizeof(str));
    int cmp13 = s21_strcmp(str, str3);
    printf("\n");

    printf("str = ");
    output(str, sizeof(str));
    printf("str1 = ");
    output(str1, sizeof(str1));
    s21_strcpy(str, str1);
    printf("result string = ");
    output(str, sizeof(str));
    int cmp23 = s21_strcmp(str, str1);
    printf("\n");

    if ((cmp12 == 0) && (cmp13 == 0) && (cmp23 == 0))
        printf("SUCCESS!");
    else
        printf("FAIL");
}

