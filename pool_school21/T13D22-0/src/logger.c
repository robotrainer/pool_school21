#include "logger.h"

#include <time.h>

#include "log_levels.h"

FILE* log_init(char* filename) {
  FILE* file;
  file = fopen(filename, "a+");
  return file;
}

int logcat(FILE* log_file, char* path, char* message, enum log_level level) {
  long int s_time;
  struct tm m_time;
  char buf[26] = "";
  const char* level_list[6] = {"DEBUG", "TRACE", "INFO", "WARNING", "ERROR"};
  s_time = time(NULL);
  localtime_r(&s_time, &m_time);
  asctime_r(&m_time, buf);
  for (int i = 0; i < 26; i++)
    if (buf[i] == '\n') buf[i] = '\0';
  fprintf(log_file, "%s\t-\t%s - FILE %s - %s\n", level_list[level], buf, path,
          message);
  return 0;
}

int log_close(FILE* log_file) {
  fclose(log_file);
  return 0;
}
