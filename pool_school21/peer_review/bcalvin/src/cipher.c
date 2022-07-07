#include <stdio.h>

#include "logger.h"
#define NMAX 10000

void init_file(FILE* file, char* text, int* n, char* path, int* file_exist);
void output(FILE* file, char* path, char* text);
int empty_file(FILE* file);
void encrypt(char* data, int* key);
void Quest_3();
void write_file(char* data, FILE* f, char* path, int* key);
void clean_file();
void log_cases(int n);

int main(void) {
  FILE* file = NULL;
  char path[BUFSIZ];
  int file_exist = 0;
  char* p_path = &path[BUFSIZ];
  char text[NMAX];
  char* p_text = &text[NMAX];
  int n = 0;
  while (1) {
    scanf("%d", &n);
    init_file(file, p_text, &n, p_path, &file_exist);
    if (n == -1) break;
  }
  return 0;
}

void init_file(FILE* file, char* text, int* n, char* path, int* file_exist) {
  switch (*n) {
    case 1:
      scanf("%s", path);
      if ((file = fopen(path, "r")) == NULL) {
        printf("n/a");
        log_cases(5);
        file = fopen(path, "a+");
        printf("\n");
        log_cases(3);
        break;
      } else {
        *file_exist = 1;
        if (empty_file(file) == 0) {
          printf("n/a");
          printf("\n");
          break;
        } else {
          output(file, path, text);
          printf("\n");
          break;
        }
      }
    case 2:
      scanf("%*[^\n]");
      scanf("%*c");
      fgets(text, BUFSIZ, stdin);
      if (*file_exist == 1) {
        file = fopen(path, "a");
        fprintf(file, "%s", text);
        fclose(file);
        output(file, path, text);
        printf("\n");
        break;
      } else {
        printf("n/a");
        log_cases(5);
        printf("\n");
        break;
      }
    case 3:
      Quest_3();
      break;
    case -1:
      break;
    default:
      printf("n/a");
      log_cases(5);
      printf("\n");
      break;
  }
}

int empty_file(FILE* file) {
  fseek(file, 0, SEEK_END);
  long pos = ftell(file);
  return pos;
}

void output(FILE* file, char* path, char* text) {
  int i = 0;
  file = fopen(path, "r");
  while (fgets(text, 1024, file)) {
    printf("%s", text);
    i++;
  }
  fclose(file);
}

void Quest_3() {
  FILE* f1;
  FILE* f2;
  char data_1[NMAX];
  char data_2[NMAX];
  char path1[] = "ai_modules/m1.c";
  char path2[] = "ai_modules/m2.c";
  int key = 0;
  scanf("%d", &key);

  if ((f1 = fopen(path1, "r")) == NULL || (f2 = fopen(path2, "r")) == NULL) {
    printf("n/a");
  } else {
    write_file(data_1, f1, path1, &key);
    write_file(data_2, f2, path2, &key);
    clean_file();
  }
}

void write_file(char* data, FILE* f, char* path, int* key) {
  int i = 0;
  while ((data[i] = fgetc(f)) != EOF) {
    i++;
  }
  encrypt(data, key);
  fclose(f);
  f = fopen(path, "w");
  fprintf(f, "%s", data);
  fclose(f);
}

void encrypt(char* data, int* key) {
  for (int i = 0; data[i] != '\0'; i++) {
    if (data[i] >= 'a' && data[i] <= 'z') {
      data[i] = data[i] + *key;
      if (data[i] > 'z') data[i] = data[i] - 'z' + 'a' - 1;
    } else if (data[i] >= 'A' && data[i] <= 'Z') {
      data[i] = data[i] + *key;
      if (data[i] > 'Z') data[i] = data[i] - 'Z' + 'A' - 1;
    }
  }
}

void clean_file() {
  FILE* f1;
  FILE* f2;
  char path1[] = "ai_modules/m1.h";
  char path2[] = "ai_modules/m2.h";
  if ((f1 = fopen(path1, "r")) == NULL || (f2 = fopen(path2, "r")) == NULL) {
    printf("n/a");
    log_cases(5);
  } else {
    f1 = fopen(path1, "w");
    f2 = fopen(path2, "w");
    fclose(f1);
    fclose(f2);
  }
}

void log_cases(int n) {
  FILE* f_return;
  f_return = log_init("log.txt");
  switch (n) {
    case 1:
      logcat(f_return, "File created", DEBUG);
      break;
    case 2:
      logcat(f_return, "File created", TRACE);
      break;
    case 3:
      logcat(f_return, "File created", INFO);
      break;
    case 4:
      logcat(f_return, "File created", WARNING);
      break;
    case 5:
      logcat(f_return, "File doesn't exist or input error", ERROR);
      break;
  }
  log_close(f_return);
}
