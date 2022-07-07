#include <stdio.h>
#include <string.h>
#include <ncurses.h>
#include "state_sort.h"

#define NMAX 1000

typedef struct SFile {
    int year, month, day, hour, min, sec, stat, code;
} TFile;


int main(void) {
    int n;
    char file[NMAX];
    scanf("%199s", file);
    if (scanf("%d", &n) == 1) {
        if (n == 0) {
            output(file);
        } else if (n == 1) {
            sort(file);
        } else if (n == 2) {
            puting(file);
        } else {
            printf("n/a");
        }
    } else {
        printf("n/a");
    }
}

void output(const char *file) {
    FILE *f;
    f = fopen(file, "r");
    TFile buf;
    while (!feof(f)) {
        if (fread (&buf, 1, sizeof(buf), f) > 0) {
            printf("%d %d %d %d %d %d %d %d\n",
                buf.year, buf.month, buf.day, buf.hour, buf.min, buf.sec, buf.stat, buf.code);
        }
    }
    fclose(f);
}

void sort(const char *file) {
    // 1
}

void puting(const char *file) {
    FILE *f;
    TFile i;
    scanf("%d %d %d %d %d %d %d %d",
        &(i.year), &(i.month), &(i.day), &(i.hour), &(i.min), &(i.sec), &(i.stat), &(i.code));
    f = fopen(file, "a");
    fwrite(&i, 1, sizeof(i), f);
    fclose(f);
    f = fopen(file, "r");
    TFile buf;
    while (!feof(f)) {
        if (fread (&buf, 1, sizeof(buf), f) > 0) {
            printf("%d %d %d %d %d %d %d %d\n",
                buf.year, buf.month, buf.day, buf.hour, buf.min, buf.sec, buf.stat, buf.code);
        }
    }
    fclose(f);
}
