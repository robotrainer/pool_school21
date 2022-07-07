#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct data {
    int year;
    int mounth;
    int day;
    int hour;
    int minute;
    int second;
    int status;
    int code;
};

int parse_date(char *str, int date[3]);
int search(char *str, int date[3], int *found);
int check_file_existance(char *path);
int check_input(char *str);

int main() {
    char path[1025];
    scanf("%1024[^\n]", path);
    if (check_file_existance(path) == 1) {
        char date_str[11];
        scanf("%10s", date_str);
        if (check_input(date_str) == 1) {
            int date[3];
            int test = parse_date(date_str, date);
            if (test == 1) {
                int found = 0;
                int code = search(path, date, &found);
                if (found == 1) {
                    printf("%d", code);
                    FILE *f = fopen("src/code.txt", "w");
                    fprintf(f, "%d", code);
                    fclose(f);
                } else {
                    printf("n/a");
                }
            } else {
                printf("n/a");
            }
        } else {
            printf("n/a");
        }
    } else {
        printf("n/a");
    }
    return 0;
}

int parse_date(char *str, int date[3]) {
    char *token = strtok(str, ".");
    int test = 1;
    if (strlen(token) == 0)
        test = 0;
    date[0] = atoi(token);
    for (int i = 1; i < 3 && test == 1; i++) {
        token = strtok(NULL, ".");
        date[i] = atoi(token);
        if (strlen(token) == 0)
            test = 0;
    }
    return test;
}

int search(char *str, int date[3], int *found) {
    struct data line;
    FILE *f = fopen(str, "rb");
    int code = 0;
    while ((fread(&line, sizeof(struct data), 1, f)) && *found == 0) {
        if (line.year == date[2] && line.mounth == date[1] &&
            line.day == date[0]) {
            code = line.code;
            *found = 1;
        }
    }
    return code;
}

int check_file_existance(char *path) {
    int test = 0;
    FILE *f;
    if ((f = fopen(path, "rb"))) {
        test = 1;
        fclose(f);
    }
    return test;
}

int check_input(char *str) {
    int dots = 0;
    int test = 1;
    for (int i = 0; i < strlen(str) && test == 1; i++) {
        if (!(str[i] >= '0' && str[i] <= '9') && str[i] != '.') {
            test = 0;
        }
        if (str[i] == '.') {
            dots++;
        }
    }
    if (dots != 2)
        test = 0;
    return test;
}
