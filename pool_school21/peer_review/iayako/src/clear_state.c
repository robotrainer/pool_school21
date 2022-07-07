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

long int sum(DATE d);
void print_bin(FILE *bin, char *path, int n);
void bs(FILE *bin, char *path, int n);
int count_el(char *path);
int check_file(char *path);
int check_empty(FILE *bin, char *path);
int add_el(char *path, int *n);
int s21_strlen(char str[]);
char *s21_strcat(char *str1, char *str2);

int main() {
  FILE *bin = NULL;
  FILE *buf = NULL;
  char path_input[30];
  char path[63] = "../";
  scanf("%29s", path_input);
  s21_strcat(path, path_input);
  if (check_file(path)) {
    printf("n/a");
    return 0;
  }
  bin = fopen(path, "rb");
  buf = fopen(path, "a+b");
  int n = count_el(path);
  bs(bin, path, n);
  DATE d;
  int year1, year2;
  int month1, month2;
  int day1, day2;
  int left, right;
  if (scanf("%d.%d.%d", &day1, &month1, &year1) != 3) {
    printf("n/a");
    return 0;
  }
  if (scanf("%d.%d.%d", &day2, &month2, &year2) != 3) {
    printf("n/a");
    return 0;
  }
  for (int i = 0; i < n; ++i) {
    fread(&d, sizeof(d), 1, bin);
    if ((d.y == year1) && (d.m == month1) && (d.d = day1)) {
      left = i;
      break;
    }
    fwrite(&d, sizeof(d), 1, buf);
  }
  for (int i = left; i < n; ++i) {
    fread(&d, sizeof(d), 1, bin);
    if ((d.y == year2) && (d.m == month2) && (d.d = day2)) {
      right = i;
      break;
    }
  }
  for (int i = right; i < n; ++i) {
    fseek(bin, sizeof(d), SEEK_CUR);
    fread(&d, sizeof(d), 1, bin);
    fwrite(&d, sizeof(d), 1, buf);
  }
  fclose(bin);
  fclose(buf);
  bin = fopen(path, "w");
  buf = fopen(path, "rb");
  for (int i = 0; i < n - (right - left + 1); ++i) {
    fread(&d, sizeof(d), 1, buf);
    fwrite(&d, sizeof(d), 1, bin);
  }
  fclose(bin);
  fclose(buf);
  buf = fopen(path, "w");
  remove("buf");
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

int check_empty(FILE *bin, char *path) {
  int empty = 0;
  bin = fopen(path, "rb");
  if (feof(bin)) {
    empty = 1;
    fclose(bin);
  }
  return empty;
}

void print_bin(FILE *bin, char *path, int n) {
  DATE d;
  bin = fopen(path, "rb");
  int i = 0;
  while (i < n) {
    fread(&d, sizeof(d), 1, bin);
    printf("%d %d %d %d %d %d %d %d\n", d.y, d.m, d.d, d.h, d.min, d.sec,
           d.status, d.code);
    ++i;
  }
  fclose(bin);
}

long int sum(DATE d) {
  long int sum = d.y * 10000000000 + d.m * 100000000 + d.d * 1000000 +
                 d.h * 10000 + d.min * 100 + d.sec;
  return sum;
}

void bs(FILE *bin, char *path, int n) {
  DATE d;
  DATE s1;
  DATE s2;
  bin = fopen(path, "r+b");
  for (int i = 0; i < n - 1; ++i) {
    for (int j = n - 1; j > i; --j) {
      fseek(bin, sizeof(d) * (j - 1), SEEK_SET);
      fread(&s1, sizeof(d), 1, bin);
      fread(&s2, sizeof(d), 1, bin);
      if (sum(s1) > sum(s2)) {
        d = s1;
        fseek(bin, sizeof(d) * (j - 1), SEEK_SET);
        fwrite(&s2, sizeof(d), 1, bin);
        fwrite(&d, sizeof(d), 1, bin);
      }
    }
  }
  fclose(bin);
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

int add_el(char *path, int *n) {
  int err = 0;
  FILE *bin;
  DATE d;
  bin = fopen(path, "a+b");
  if (scanf("%d %d %d %d %d %d %d %d", &d.y, &d.m, &d.d, &d.h, &d.min, &d.sec,
            &d.status, &d.code) != 8) {
    err = 1;
  }
  fwrite(&d, sizeof(d), 1, bin);
  *n = *n + 1;
  fclose(bin);
  return err;
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
