#include <stdio.h>
#include <stdlib.h>

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

void mode0(char *path);
void mode1(char *path);
void mode2(char *path);
int count_sets(char *path);
int check_file_existance(char *path);

int main() {
    char path[1024];
    scanf("%1024[^\n]", path);
    if (check_file_existance(path) == 1) {
        int mode;
        if (scanf("%d", &mode) == 1) {
            if (mode == 0) {
                mode0(path);
            } else if (mode == 1) {
                mode1(path);
            } else if (mode == 2) {
                mode2(path);
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

void mode0(char *path) {
    FILE *ptr;
    struct data line;
    ptr = fopen(path, "rb");
    while ((fread(&line, sizeof(struct data), 1, ptr))) {
        printf("%d %d %d %d %d %d %d %d\n", line.year, line.mounth, line.day,
            line.hour, line.minute, line.second, line.status, line.code);
    }
    fclose(ptr);
}

void swap_sets(struct data line1, struct data line2, char *path, int pos, FILE *edit) {
    fseek(edit, pos*8*sizeof(int), SEEK_SET);
    fwrite(&line2, sizeof(struct data), 1, edit);
    fseek(edit, (pos+1)*8*sizeof(int), SEEK_SET);
    fwrite(&line1, sizeof(struct data), 1, edit);
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

int count_sets(char *path) {
    FILE *f = fopen(path, "rb");
    int count = 0;
    struct data test;
    while ((fread(&test, sizeof(struct data), 1, f))) {
        count++;
    }
    fclose(f);
    return count;
}

int compare_sets(struct data line1, struct data line2, char *path, int pos, FILE *edit) {
    int swap = 0;
    if (line1.year > line2.year) {
        swap_sets(line1, line2, path, pos, edit);
        swap = 1;
    } else if (line1.mounth > line2.mounth && line1.year == line2.year) {
        swap_sets(line1, line2, path, pos, edit);
        swap = 1;
    } else if (line1.day > line2.day && line1.mounth == line2.mounth && line1.year == line2.year) {
        swap_sets(line1, line2, path, pos, edit);
        swap = 1;
    } else if (line1.hour > line2.hour && line1.day == line2.day &&
        line1.mounth == line2.mounth && line1.year == line2.year) {
        swap_sets(line1, line2, path, pos, edit);
        swap = 1;
    } else if (line1.minute > line2.minute && line1.hour == line2.hour && line1.day == line2.day &&
        line1.mounth == line2.mounth && line1.year == line2.year) {
        swap_sets(line1, line2, path, pos, edit);
        swap = 1;
    } else if (line1.second > line2.second && line1.minute == line2.minute &&
        line1.hour == line2.hour && line1.day == line2.day && line1.mounth == line2.mounth &&
        line1.year == line2.year) {
        swap_sets(line1, line2, path, pos, edit);
        swap = 1;
    }
    return swap;
}

void mode1_logic(char *path) {
    int count = 0;
    FILE *ptr;
    struct data line1;
    struct data line2;
    ptr = fopen(path, "rb+");
    fread(&line1, sizeof(struct data), 1, ptr);
    line2 = line1;
    while ((fread(&line1, sizeof(struct data), 1, ptr))) {
        if (compare_sets(line2, line1, path, count, ptr) == 0)
            line2 = line1;
        count++;
    }
    fclose(ptr);
}

void mode1(char *path) {
    int count = count_sets(path);
    for (int i = 0; i < count; i++) {
        mode1_logic(path);
    }
    mode0(path);
}

void mode2(char *path) {
    struct data line;
    if (scanf("%d %d %d %d %d %d %d %d", &line.year, &line.mounth, &line.day,
        &line.hour, &line.minute, &line.second, &line.status, &line.code) == 8) {
        FILE *f = fopen(path, "rb+");
        fseek(f, 0, SEEK_END);
        fwrite(&line, sizeof(struct data), 1, f);
        fclose(f);
        mode1(path);
    } else {
        printf("n/a");
    }
}
