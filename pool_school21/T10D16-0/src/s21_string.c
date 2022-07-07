#include "s21_string.h"

#include <stdio.h>

int s21_strlen(const char *str) {
  int len = 0;
  if (str == NULL) {
    len = -1;
  } else {
    for (; *(str + len); len++) {
    }
  }
  return len;
}

int s21_strcmp(const char *str1, const char *str2) {
  int rtn = -2;
  if (str1 != NULL && str2 != NULL) {
    for (; *str1 && *str1 == *str2; str1++, str2++) {
    }
    int result = *str1 - *str2;
    if (result > 0)
      rtn = 1;
    else if (result < 0)
      rtn = -1;
    else
      rtn = 0;
  }
  return rtn;
}

char *s21_strcpy(char *destination, const char *source) {
  if (source != NULL) {
    for (int i = 0; (destination[i] = source[i]) != '\0'; i++) {
    }
  }
  return destination;
}

char *s21_strcat(char *destination, const char *append) {
  int len = 0;
  for (; destination[len] != '\0'; len++) {
  }
  for (; *append; append++, len++) {
    destination[len] = *append;
  }
  return destination;
}

char *s21_strchr(char *str, int ch) {
  char *rtn = NULL;
  if (str != NULL) {
    for (; *str && *str != ch; str++) {
    }
    if (*str != '\0') rtn = str;
  }
  return rtn;
}
