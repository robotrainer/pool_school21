#include <stdio.h>
#include "s21_string_test.h"
#include "s21_string.h"

int main(){
    char* str = NULL;
    s21_strlen_test(str);
    return 0;
}

void s21_strlen_test(char* str) {
    str = "Hello";
    printf("%s %d ", str, s21_strlen(str));
    if (str !=  NULL)
        printf("SUCCESS ");
    else 
        printf("FAIL ");
    if (*str != '\0')
        printf("SUCCESS ");
    else 
        printf("FAIL ");
    if (s21_strlen(str) == 5)
        printf("SUCCESS");
    else 
        printf("FAIL");
}
