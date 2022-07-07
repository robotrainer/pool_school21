#include <dirent.h>
#include <stdio.h>
#include <string.h>
int File_open(FILE *fp);
int File_scan(FILE *fp, char *str);
void Filename(char *file);
void Caesar(FILE *fp, char *str);

int main() {
  int key = 0;
  char file[1000];
  char str[10000];
  FILE *fp = NULL;
  while (key != -1) {
    scanf("%d", &key);
    switch (key) {
      case 1:
        Filename(file);
        fp = fopen(file, "r");
        if (File_open(fp)) {
          printf("n/a\n");
          break;
        }
        if (File_scan(fp, str)) {
          printf("n/a\n");
          break;
        }
        break;
      case 2:

        scanf("%9999[^\n]s", str);
        if (File_open(fp) != 1) {
          fp = fopen(file, "a");
          fprintf(fp, "%s", str);
          fclose(fp);
          fp = fopen(file, "r");
          File_scan(fp, str);
        } else {
          printf("n/a\n");
        }
        break;
      case 3:
        Caesar(fp, str);
        break;
      case -1:
        return 0;
        break;
      default:
        printf("n/a\n");
        break;
    }
    fpurge(stdin);
  }
  return 0;
}
void Filename(char *file) { scanf("%999s", file); }

int File_open(FILE *fp) {
  int flag = 0;
  if (fp == NULL) flag = 1;
  return flag;
}
int File_scan(FILE *fp, char *str) {
  int flag = 0;
  fscanf(fp, "%9999[!-🌕 \n]s", str);
  if (strlen(str) == 0) {
    flag = 1;
  } else {
    printf("%s\n", str);
  }
  fclose(fp);
  return flag;
}

void Caesar(FILE *fp, char *str) {
  char put[1000];
  DIR *d;
  struct dirent *dir;
  int sdvig;
  if (scanf("%d", &sdvig)) {
    sdvig = sdvig % 26;
    scanf("%s", put);
    d = opendir(put);
    if (d) {
      while ((dir = readdir(d)) != NULL) {
        fp = fopen(dir->d_name, "r");
        if (fp != NULL) {
          fscanf(fp, "%9999[!-🌕 \n]s", str);
          fclose(fp);
          fp = fopen(dir->d_name, "w");
          int i = strlen(str);
          for (int j = 0; j < i; j++) {
            if (str[j] >= 'a' && str[j] <= 'z') {
              if (str[j] + sdvig <= 'z' && str[j] + sdvig >= 'a') {
                str[j] = str[j] + sdvig;
              } else if (sdvig > 0) {
                str[j] = str[j] - 26 + sdvig;
              } else {
                str[j] = str[j] + 26 + sdvig;
              }
            } else if (str[j] >= 'A' && str[j] <= 'Z') {
              if (str[j] + sdvig <= 'Z' && str[j] + sdvig >= 'A') {
                str[j] = str[j] + sdvig;
              } else if (sdvig > 0) {
                str[j] = str[j] - 26 + sdvig;
              } else {
                str[j] = str[j] + 26 + sdvig;
              }
            }
            fprintf(fp, "%c", str[j]);
          }
          fclose(fp);
        }
      }
      closedir(d);
    } else {
      printf("n/a\n");
    }
  } else {
    printf("n/a\n");
  }
}
