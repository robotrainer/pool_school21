#include <stdio.h>
#include <string.h>
#include <ncurses.h>

#define NMAX 1000

typedef struct SFile {
    int year, month, day, hour, min, sec, stat, code;
    char nul[8];
} TFile;

int main(void) {
    char file[NMAX];
    TFile buf;
    TFile buf2;
    TFile src;
    int count = 0;
    scanf("%199s", file);
    if (scanf("%d.%d.%d", &buf.day, &buf.month, &buf.year) == 3 &&
    scanf("%d.%d.%d", &buf2.day, &buf2.month, &buf2.year) == 3) {
        FILE *f;
        f = fopen(file, "w+");
        if (!f) {
        printf("n/a");
        } else {
            while (!feof(f)) {
                fread (&src, 1, sizeof(src), f);
                if ((src.day <= buf.day || src.day >= buf2.day) &&
                src.day >= buf.month && src.month <= buf2.month  &&
                src.year >= buf.year && src.year <= buf2.year) {
                    fprintf(f, "%s", src.nul);
                    count++;
                }
                if (fread (&src, 1, sizeof(buf), f) > 0) {
                    printf("%d %d %d %d %d %d %d %d\n",
                    buf.year, buf.month, buf.day, buf.hour, buf.min, buf.sec, buf.stat, buf.code);
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
