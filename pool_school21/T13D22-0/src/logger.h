#ifndef LOGGER_H_
#define LOGGER_H_

#include <stdio.h>

#include "log_levels.h"

FILE* log_init(char* filename);
int logcat(FILE* log_file, char* path, char* message, enum log_level level);
int log_close(FILE* log_file);
#endif  // LOGGER_H_