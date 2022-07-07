#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// struct data {
//     int year;
//     int mounth;
//     int day;
//     int hour;
//     int minute;
//     int second;
//     int status;
//     int code;
// };

// int check_file_existance(char *path);
// void parse_date(char *str, int date[3]);

int main() {
    return 0;
}

// void parse_date(char *str, int date[3]) {
//     char *token = strtok(str, ".");
//     date[0] = atoi(token);
//     for (int i = 1; i < 3; i++) {
//         token = strtok(NULL, ".");
//         date[i] = atoi(token);
//     }
// }

// int check_file_existance(char *path) {
//     int test = 0;
//     FILE *f;
//     if ((f = fopen(path, "rb"))) {
//         test = 1;
//         fclose(f);
//     }
//     return test;
// }

// void clear_data(char *path, int data1[3], int data2[3]) {
//     struct data line;
//     FILE *f = fopen(path, "rb");
//     count = 0;
//     while ((fread(&line, sizeof(struct data), 1, f))) {
        
//         count++;
//     }
// }
