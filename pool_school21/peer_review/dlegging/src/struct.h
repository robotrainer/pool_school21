#ifndef SRC_STRUCT_H_
#define SRC_STRUCT_H_

typedef struct Data {
    int year;
    int month;
    int day;
    int hour;
    int minute;
    int second;
    int status;
    int code;
} Data;

Data get_by_id(FILE *stream, int id);
void set_by_id(FILE *stream, int id, Data *data);

long int size(char *filename);

#endif  // SRC_STRUCT_H_
