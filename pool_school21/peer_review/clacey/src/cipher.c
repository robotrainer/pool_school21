
#include <stdio.h>

void func_menu1();
void func_menu2();
int func_print(const char* name);
int func_add(const char* nameadd);

char _file_name[255];
int _file_name_set = 0;

void main() {
  int menu = -1;

  while (1) {
    scanf("%d", &menu);

    switch (menu) {
      case 1:
        func_menu1();
        break;

      case -1:
        return;

      case 2:
        func_menu2();
        break;

      default:
        printf("n/a\n");
    }
  }
}

void func_menu1() {
  scanf("%s", _file_name);
  _file_name_set = 1;
  func_print(_file_name);
}

void func_menu2() {
  if (1 != _file_name_set) {
    printf("n/a\n");
    return;
  }
  func_add(_file_name);
  func_print(_file_name);
}

int func_print(const char* name) {
  FILE* fp;
  fp = fopen(name, "rt");
  if (fp == NULL) {
    printf("n/a\n");
    return 0;
  }

  char ch;
  ch = getc(fp);
  if (EOF == ch) {
    printf("n/a\n");
    return 0;
  }
  while (ch != EOF) {
    putchar(ch);
    ch = getc(fp);
  }
  fclose(fp);
  printf("\n");
}

int func_add(const char* nameadd) {
  char string2[255];
  scanf("%s", string2);

  FILE* fp2;
  fp2 = fopen(nameadd, "at");
  if (fp2 == NULL) {
    printf("n/a\n");
    return 0;
  }
  fputs(string2, fp2);
  fclose(fp2);
}
