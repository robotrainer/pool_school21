#include <stdio.h>

typedef struct {
  int y;
  int m;
  int d;
  int h;
  int min;
  int sec;
  int status;
  int code;
} DATE;

int s21_strlen(char str[]);
char *s21_strcat(char *str1, char *str2);
int check_file(char *path);
int count_el(char *path);
int check_empty(FILE *bin, char *path);
void outf(int code);

int main() {
  FILE *bin = NULL;
  char path_input[30];
  char path[63] = "../";
  scanf("%29s", path_input);
  s21_strcat(path, path_input);
  if (check_file(path) || check_empty(bin, path)) {
    printf("n/a");
    return 0;
  }
  DATE d;
  int year;
  int month;
  int day;
  bin = fopen(path, "rb");
  if (scanf("%d.%d.%d", &day, &month, &year) == 3) {
    int n = count_el(path);
    for (int i = 0; i < n; ++i) {
      fread(&d, sizeof(d), 1, bin);
      if ((d.y == year) && (d.m == month) && (d.d = day)) {
        outf(d.code);
        return 0;
      }
    }
  }
  printf("n/a");
  fclose(bin);
}

void outf(int code) {
  FILE *out;
  out = fopen("../src/code.txt", "a");
  fprintf(out, "%d", code);
  fclose(out);
}

int check_file(char *path) {
  FILE *bin;
  int ex = 1;
  if ((bin = fopen(path, "rb"))) {
    fclose(bin);
    ex = 0;
  }
  return ex;
}

int s21_strlen(char str[]) {
  int i = 0;
  while (str[i] != '\0') ++i;
  return i;
}

char *s21_strcat(char *str1, char *str2) {
  int n = s21_strlen(str1);
  int i;
  for (i = 0; str2[i] != '\0'; ++i) str1[n + i] = str2[i];
  str1[n + i] = '\0';
  return str1;
}

int count_el(char *path) {
  FILE *bin;
  DATE d;
  int n = 0;
  bin = fopen(path, "rb");
  while (!feof(bin)) {
    fread(&d, sizeof(d), 1, bin);
    ++n;
  }
  fclose(bin);
  return n - 1;
}

int check_empty(FILE *bin, char *path) {
  int empty = 0;
  bin = fopen(path, "rb");
  if (feof(bin)) {
    empty = 1;
    fclose(bin);
  }
  return empty;
}
