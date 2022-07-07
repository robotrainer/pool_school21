#include "work_with_file.h"

#include <string.h>

#include "log_levels.h"
#include "logger.h"

int read_file(FILE *file, char *path) {
  FILE *f = log_init("LOG.txt");
  int rtn = 1;
  scanf("%255s", path);
  file = fopen(path, "rt");
  if (file != NULL) {
    fseek(file, 0, SEEK_END);
    long pos = ftell(file);
    if (pos > 0) {
      logcat(f, path, "FILE IS NOT EMPTY", INFO);
      char string[SIZE];
      rewind(file);
      while (fgets(string, sizeof(string), file)) {
        printf("%s", string);
      }
    } else {
      logcat(f, path, "FILE IS EMPTY", WARNING);
      rtn = 0;
    }
    fclose(file);
  } else {
    logcat(f, path, "FILE DOES NOT EXIST", ERROR);
    rtn = 0;
  }
  if (rtn) {
    logcat(f, path, "FILE READ", INFO);
    printf("\n");
  }
  log_close(f);
  return rtn;
}

int write_in_file(FILE *file, char *path) {
  FILE *f = log_init("LOG.txt");
  int rtn = 1;
  char string[SIZE];
  getchar();
  fgets(string, sizeof(string), stdin);
  if (string[strlen(string) - 1] == '\n') string[strlen(string) - 1] = '\0';
  file = fopen(path, "r+");
  if (file != NULL) {
    fseek(file, 0, SEEK_END);
    long pos = ftell(file);
    if (pos != 0) fprintf(file, "%c", '\n');
    fprintf(file, "%s", string);
    rewind(file);
    while (fgets(string, sizeof(string), file)) {
      printf("%s", string);
    }
    fclose(file);
  } else {
    logcat(f, path, "FILE IS NOT OPEN FOR WRITING", ERROR);
    rtn = 0;
  }
  if (rtn) {
    printf("\n");
    logcat(f, path, "WRITING TO FILE SUCCESSFULLY", INFO);
  }
  log_close(f);
  return rtn;
}
