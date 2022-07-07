#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int Write_in();
int read();
int List(int *chose);

int main() {
int chose = 0;
if (List(&chose) == 1) return 1;
return 0;
}

int List(int *chose) {
char name[100] = "";
int control = 0;
while(*chose != -1) {
    int a = 0;
scanf("%d", chose);
    if (*chose == 1) {
      if (read(name) == 1) printf("n/a\n");
    } else if (*chose == 2) {
      if (Write_in(name) == 1) printf("n/a\n");
    } else if (*chose == -1) {
      control = 1;
      } else {
      printf("n/a\n");
while ((a = getchar()) !='\n') {
    continue;
}
}
}
return control;
}

int read(char *name) {
    char path[100];
    char name1[50] = "";
int control = 1;
FILE *file;
scanf("%99s", path);
name[strlen(name)] = '\0';
  if (strcmp(name, name1) == 0) {
    strcat(name, path);
    file = fopen(name, "r");
  } else {
    strcat(name, path);
    file = fopen(name1, "r");
  }
  if (file != NULL) {
    int x;
    while ((x = fgetc(file)) != EOF) {
        if (x != EOF) {
            fprintf(stdout, "%c", x);
            control = 0;
            } else {
                control = 1;
                }
                }
                fclose(file);
} else {
                    control = 1;
                     }
                     return control;
                     }

int Write_in(char *name) {
    char word[255];
    int control = 0;
    FILE *file;
     file = fopen(name, "r+");
     if (file != NULL) {
     fseek(file, 0, SEEK_END);
     long pos = ftell(file);
     if (pos != 0) {
    scanf("%s", word);
    fputs(word, file);
    fputs("\n", file);
     } else {
    scanf("%s", word);
    fputs(word, file);
    fputs("\n", file);
     }
     char c[255];
    rewind(file);
    getchar();
    while (fgets(c, 255, file)) {
      printf("%s", c);
    }
    fclose(file);
  } else {
    control = 1;
  }
  return control;
}
