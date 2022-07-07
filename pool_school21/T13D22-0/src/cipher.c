#include "work_with_file.h"

int main() {
  FILE *file = NULL;
  char path[SIZE];
  int mode = 0;
  int result = 1;
  while (mode != -1) {
    if (scanf("%d", &mode) == 1) {
      if (mode < -1 || mode > 2 || mode == 0) result = !result;
      if (mode == 1) {
        result = read_file(file, path);
      }
      if (mode == 2) {
        result = write_in_file(file, path);
      }
    } else {
      result = !result;
      scanf("%*s");
    }
    if (!result) {
      printf("n/a\n");
      result = !result;
    }
  }
  return 0;
}
