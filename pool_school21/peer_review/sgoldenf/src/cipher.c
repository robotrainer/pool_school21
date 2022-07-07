#include <stdio.h>
#include <stdlib.h>

void read(FILE *file, char *path);
void add(char *path, FILE *file, char *str);

int main() {
    int n;
    char path[20], str[1000];
    FILE *file = 0;
    while (scanf("%d", &n) && n != -1) {
        if (n == 1) {
            scanf("%19s", path);
            read(file, path);
            printf("\n");
        } else if (n == 2) {
            add(path, file, str);
        }
    }
    return 0;
}

void read(FILE *file, char *path) {
    if ((file = fopen(path, "r"))) {
        char ch = getc(file);
        int x = ch;
        if (x != EOF) {
            while (x != EOF) {
                putchar(ch);
                ch = getc(file);
                x = ch;
            }
        } else {
            printf("n/a");
        }
        fclose(file);
    } else {
        printf("n/a");
    }
}

void add(char *path, FILE *file, char *str) {
    getchar();
    scanf("%999[^\n]s", str);
    if ((file = fopen(path, "r")) && (file = fopen(path, "a"))) {
        fputs(str, file);
        fclose(file);
        file = fopen(path, "r");
        read(file, path);
    } else {
        printf("n/a");
    }
    printf("\n");
}
