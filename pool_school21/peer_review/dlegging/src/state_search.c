#include <stdio.h>
#include <string.h>

#include "struct.h"

void search_state(char* filename, int *mass);

int main() {
    char buf[100] = "../";
    char filename[100];
    scanf("%50s", filename);
    strncat(buf, filename, 90);

    int data[3];
    if (scanf("%d.%d.%d", &data[0], &data[1], &data[2]) == 3) {
        search_state(buf, data);
    } else {
        printf("n/a");
    }
}

void search_state(char* filename, int *mass) {
    FILE *f = fopen(filename, "rb");
    if (f != NULL) {
        int size_file = size(filename);
        for (int i = 0; i < size_file; i++) {
            Data data = get_by_id(f, i);
            if (data.year == mass[2] && data.month == mass[1] && data.day == mass[0]) {
                FILE *f2 = fopen("../src/code.txt", "w");
                fprintf(f2, "%d", data.code);
                fclose(f2);
                printf("%d", data.code);
            }
        }
        fclose(f);
    }
}


