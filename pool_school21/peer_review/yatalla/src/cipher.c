#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int printFile(char *str);
int writeFile(char *str);
int shifr_file();

int main() {
  int menu = 0;
  int error = 0;
  char str[256] = "";
  while (menu != -1) {
    if ((scanf("%d", &menu) != 1)) {
      error = 1;
    }
    if (error == 0 && menu == 1) {
      scanf("%255s", str);
      error = printFile(str);
    }
    if (error == 0 && menu == 2) {
      error = writeFile(str);
      if (error == 0) {
        error = printFile(str);
      }
    }
    if (error == 0 && menu == 3) {
      error = shifr_file();
    }
    if (error == 0 && menu == -1) {
      error = 0;
    }
    if ((menu > 3) || (menu < -1)) {
      error = 1;
    }
    if (menu == 0) {
      error = 1;
    }
    if (error == 1) {
      printf("n/a\n");
      error = 0;
    }
  }
  printf("\n");
  return 0;
}

int printFile(char *str) {
  int error = 0;
  char *flag = NULL;
  FILE *ptrFile = fopen(str, "r");
  if ((ptrFile) != NULL) {
    char data[1000] = "";
    flag = (fgets(data, 256, ptrFile));
    if (flag == NULL) {
      error = 1;
    }
    while (flag != NULL) {
      printf("%s", data);
      flag = (fgets(data, 256, ptrFile));
    }
    fclose(ptrFile);
  } else {
    error = 1;
  }
  printf("\n");
  return error;
}

int writeFile(char *str) {
  int error = 0;
  char mas2[1000];
  FILE *ptrFile;
  getchar();
  fgets(mas2, 255, stdin);
  ptrFile = fopen(str, "r");
  if ((ptrFile) != NULL) {
    fclose(ptrFile);
    ptrFile = fopen(str, "a");
    if ((ptrFile) != NULL) {
      fputs(mas2, ptrFile);
      printf("\n");
      fclose(ptrFile);
    }
  } else {
    error = 1;
  }
  return error;
}

int shifr_file() {
  int error = 0, i, j = 0, sd = 0;
  char f_name[100] = "";
  FILE *ptrFile;
  DIR *dir;
  if ((scanf("%d", &sd) != 1)) {
    error = 1;
  }
  struct dirent *de;
  dir = opendir("../src/ai_modules");
  while (j < 100) {
    de = readdir(dir);
    if (de) {
      if (de->d_type == 8) {
        char f2_name[100] = "../src/ai_modules/";
        int len = strlen(de[0].d_name);
        if (de[0].d_name[len - 1] == 'h' && de[0].d_name[len - 2] == '.') {
          for (i = 0; i < len; i++) {
            f_name[i] = de[0].d_name[i];
          }
          strncat(f2_name, f_name, 100);
          ptrFile = fopen(f2_name, "w");
          fclose(ptrFile);
        }
        if (de[0].d_name[len - 1] == 'c' && de[0].d_name[len - 2] == '.') {
          for (i = 0; i < len; i++) {
            f_name[i] = de[0].d_name[i];
          }
          char *str2;
          strncat(f2_name, f_name, 100);
          ptrFile = fopen(f2_name, "r");
          j = 0;
          while (fgetc(ptrFile) != EOF) {
            j++;
          }
          fclose(ptrFile);
          int lenf = j;
          str2 = (char *)malloc(lenf * sizeof(char));
          j = 0;
          char c;
          FILE *ptrFile2 = fopen(f2_name, "r");
          while ((str2[j] = fgetc(ptrFile2)) != EOF) {
            j++;
          }
          for (i = 0; i < lenf; i++) {
            if (str2[i] >= 65 && str2[i] <= 122) {
              c = str2[i];
              c = c + sd;
              str2[i] = c;
            }
          }
          fclose(ptrFile2);
          ptrFile = fopen(f2_name, "w");
          j = 0;
          while (j < lenf) {
            fputc(str2[j], ptrFile);
            j++;
          }
          free(str2);
          fclose(ptrFile);
        }
      }
    }
    j++;
  }
  closedir(dir);
  return error;
}
