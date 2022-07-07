#include "s21_string.h"

int s21_strlen(char *string) {
  int counter = 0;
  if (string == 0) {
    counter = 0;
  } else {
    while (string[counter] != '\0') {
      counter++;
    }
  }
  return counter;
}

int s21_strcmp(char *first_string, char *second_string) {
  int res;
  if (first_string == 0 || second_string == 0) {
    printf("n/a\n");
    res = 404;
  } else {
    while (*first_string == *second_string && (*first_string != '\0' || *second_string != '\0')) {
      first_string += 1;
      second_string += 1;
     }
     if (*first_string == *second_string)
       res = 0;
     else if (*first_string > *second_string)
       res = 1;
     else
       res = -1;
  }
  return res;
}

char* s21_strcpy(char *destination, char *source) {
  int i;
  for (i = 0; source[i] != '\0'; i++) {
    destination[i] = source[i];
  }
  destination[i] = '\0';
  return destination;
}

char* s21_strcat(char *destination, char* source) {
  int last = s21_strlen(destination);
  int i = 0;
  while (source[i] != '\0') {
    destination[last] = source[i];
    i++;
    last++;
  }
  return destination;
}

char* s21_strchr(char *string, int symbol) {
  int i = 0;
  char *s;
  while (string[i] != '\0') {
    if (string[i] == symbol)
      break;
    i++;
  }
  if (string[i] == symbol)
     s = &string[i];
  else
    s = "(null)";
  return s;
}
