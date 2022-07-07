#include <stdio.h>
#include <time.h>

enum log_level { DEBUG, TRACE, INFO, WARNING, ERROR };

FILE* log_init(char* filename);
int logcat(FILE* log_file, char* message, enum log_level level);
int log_close(FILE* log_file);
