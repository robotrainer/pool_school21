#include <stdio.h>

#define SIZE 255

typedef struct remember_state {
  int year;
  int month;
  int day;
  int hour;
  int minute;
  int second;
  int status;
  int code;
} state;

void read_state(FILE* fstream);
void print_state(state* STATE);
void sort_state(FILE* file);

int main() {
  char path[SIZE];
  int mode;
  int result = 1;
  scanf("%255s", path);
  FILE* file = fopen(path, "r+b");
  if (file != NULL) {
    if (scanf("%d", &mode) == 1 && mode >= 0 && mode <= 2) {
      if (mode == 0) {
        read_state(file);
      }
      if (mode == 1) {
        read_state(file);
        sort_state(file);
        printf("********\n");
        // read_state(file);
      }
      if (mode == 2) {
      }
      fclose(file);
    } else {
      result = !result;
    }
  } else {
    result = !result;
  }
  if (!result) printf("n/a");
  return 0;
}

void read_state(FILE* file) {
  state STATE[1];
  while (fread(STATE, sizeof(STATE), 1, file)) {
    print_state(STATE);
  }
}

void print_state(state* STATE) {
  printf("%d %d %d %d %d %d %d %d\n", STATE->year, STATE->month, STATE->day,
         STATE->hour, STATE->minute, STATE->second, STATE->status, STATE->code);
}

void sort_state(FILE* file) {
  state STATE1, STATE2;
  // fseek(file, 0, SEEK_END);
  // long pos = ftell(file);
  // long count = pos / sizeof(STATE1);
  // rewind(file);
  int i = 0;
  while (i < 5) {
    fread(&STATE1, sizeof(STATE1), 1, file);
    fread(&STATE2, sizeof(STATE1), 1, file);
    fseek(file, -2 * sizeof(STATE1), SEEK_CUR);
    long pos = ftell(file);
    printf("%ld\n", pos);
    fwrite(&STATE2, sizeof(STATE2), 1, file);
    fwrite(&STATE1, sizeof(STATE1), 1, file);
    fseek(file, -1 * sizeof(STATE1), SEEK_CUR);
    i++;
  }
}