#ifndef DATA_IO_MACRO_H
#define DATA_IO_MACRO_H
#include <stdio.h>
#include <stdlib.h>
#define input(data, n, flag) \
    _Generic((data), \
    float *: input_float,\
    int *: input_int,\
    double *: input_double,\
    char *: input_char\
    ) (data, n, flag)
#define output(data, n) \
    _Generic((data), \
    float *: output_float,\
    int *: output_int,\
    double *: output_double,\
    char *: output_char\
    ) (data, n)

void input_float(float *data, int *n, int *flag);
void input_int(int *data, int *n, int *flag);
void input_double(double *data, int *n, int *flag);
void input_char(char *data, int *n, int *flag);
void output_float(float *data, int n);
void output_int(int *data, int n);
void output_double(double *data, int n);
void output_char(char *data, int n);

#endif
