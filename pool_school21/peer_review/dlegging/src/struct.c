#include <stdio.h>

#include "struct.h"

Data get_by_id(FILE *stream, int id) {
    struct Data data;
    fseek(stream, id * sizeof(struct Data), SEEK_SET);
    fread(&data, sizeof(struct Data), 1, stream);
    return data;
}

void set_by_id(FILE *stream, int id, Data *data) {
    fseek(stream, id * sizeof(struct Data), SEEK_SET);
    fwrite(data, sizeof(struct Data), 1, stream);
}

long int size(char *filename) {
    FILE *file = fopen(filename, "rb");
    fseek(file, 0, SEEK_END);
    long int size = ftell(file) / sizeof(Data);
    fclose(file);
    return size;
}
