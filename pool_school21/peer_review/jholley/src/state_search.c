#include <stdio.h>
#include <string.h>
#include <ncurses.h>

#define NMAX 1000

typedef struct SFile {
    int year, month, day, hour, min, sec, stat, code;
} TFile;

int main(void) {
    char file[NMAX];
    TFile buf;
    TFile src;
    int count = 0;
    scanf("%199s", file);
    if (scanf("%d.%d.%d", &buf.day, &buf.month, &buf.year) == 3) {
        FILE *f;
        f = fopen(file, "r");
        if (!f) {
        printf("n/a");
        } else {
            while (!feof(f)) {
                fread (&src, 1, sizeof(buf), f);
                if (src.day == buf.day && src.month == buf.month &&
                src.year == buf.year) {
                    printf("%d", src.code);
                    count++;
                }
            }
            if (count < 1) {
                printf("n/a");
            }
        }
        fclose(f);
    } else {
        printf("n/a");
    }
}
