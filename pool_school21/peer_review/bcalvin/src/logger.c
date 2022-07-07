#include "logger.h"

#include <stdio.h>

FILE* log_init(char* filename) {
  FILE* f = fopen(filename, "w");
  return f;
}

int logcat(FILE* log_file, char* message, enum log_level level) {
  char str[10];
  char* p = str;
  switch (level) {
    case DEBUG:
      p = "DEBUG";
      break;
    case TRACE:
      p = "TRACE";
      break;
    case INFO:
      p = "INFO";
      break;
    case WARNING:
      p = "WARNING";
      break;
    case ERROR:
      p = "ERROR";
      break;
  }
  long int time_o;
  struct tm* t;
  time_o = time(NULL);
  t = localtime(&time_o);
  char strt[64] = "";
  strftime(strt, 64, "%H:%M:%S", t);
  fprintf(log_file, "%s %s %s", p, message, strt);
  fprintf(log_file, "\n");
  return 0;
}

void s_strcat(char* str1, char* str2) {
  int i = 0;
  int j = 0;
  for (; str1[i] != '\0'; i++) {
  }
  for (; str2[j] != '\0'; j++) {
    str1[i + j] = str2[j];
  }
  str1[i + j] = '\0';
}

int log_close(FILE* log_file) {
  fclose(log_file);
  return 0;
}
