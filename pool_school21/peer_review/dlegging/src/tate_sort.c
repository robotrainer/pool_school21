#include <stdio.h>
#include <string.h>

#include "struct.h"

void menu(int type, char *filename);
long int size(char *filename);
int max(Data* data1, Data* data2);

void read_file(char *filename);
void sort_file(char *filename);
void add_file(char *filename);

int main() {
    char buf[100] = "../";
    char filename[100];
    scanf("%50s", filename);
    strncat(buf, filename, 90);

    int type;
    if (scanf("%d", &type) == 1) {
        menu(type, buf);
    } else {
        printf("n/a");
    }

    return 0;
}

void menu(int type, char *filename) {
    switch (type) {
        case 0:
            read_file(filename);
            break;
        case 1:
            sort_file(filename);
            break;
        case 2:
            add_file(filename);
            break;
        default:
            printf("n/a");
            break;
    }
}

void read_file(char *filename) {
    int size_file = size(filename);
    FILE *f = fopen(filename, "rb");
    if (f != NULL) {
        for (int i = 0; i < size_file - 1; i++) {
            Data data = get_by_id(f, i);
            printf("%d %d %d %d %d %d %d %d\n", data.year, data.month, data.day, data.hour,
                                                data.minute, data.second, data.status, data.code);
        }
        Data data = get_by_id(f, size_file - 1);
        printf("%d %d %d %d %d %d %d %d",   data.year, data.month, data.day, data.hour,
                                            data.minute, data.second, data.status, data.code);
        fclose(f);
    } else {
        printf("n/a");
    }
}

void sort_file(char *filename) {
    int size_file = size(filename);
    FILE *f = fopen(filename, "r+b");

    for (int i = 0; i < size_file - 1; i++) {
        for (int j = 0; j < size_file - i - 1; j++) {
            Data data1 = get_by_id(f, j);
            Data data2 = get_by_id(f, j + 1);
            if (max(&data1, &data2)) {
                set_by_id(f, j + 1, &data1);
                set_by_id(f, j, &data2);
            }
        }
    }
    fclose(f);
    read_file(filename);
}

int max(Data* data1, Data* data2) {
    int result = 0;
    if (data1->year > data2->year) {
        result = 1;
    }
    if (data1->year == data2->year) {
        if (data1->month > data2->month) {
            result = 1;
        }
        if (data1->month == data2->month) {
            if (data1->day > data2->day) {
                result = 1;
            }
        }
    }
    return result;
}

void add_file(char *filename) {
    int size_file = size(filename);
    FILE *f = fopen(filename, "r+b");
    Data data;
    if (scanf("%d %d %d %d %d %d %d %d",    &data.year, &data.month, &data.day, &data.hour,
                                            &data.minute, &data.second, &data.status, &data.code) == 8) {
        set_by_id(f, size_file, &data);
        fclose(f);
        sort_file(filename);
    } else {
        printf("n/a");
    }
}
