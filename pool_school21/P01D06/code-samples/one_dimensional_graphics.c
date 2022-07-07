#include <stdio.h>

void cross_and_toe_display(int cross_pos, int toe_pos);

int main() {
    int cross_position, toe_position;
    printf("Enter the \"X\" and \"O\" position:");

    if (scanf("%d%d", &cross_position, &toe_position) != 2 || cross_position < 0 || toe_position < 0) {
        printf("Invalid position");
        return -1;
    }

    cross_and_toe_display(cross_position, toe_position);
}

void cross_and_toe_display(int cross_pos, int toe_pos) {
    char cross = 'X';
    char toe = '0';
    char space = ' ';
    int max_pos = (cross_pos > toe_pos) ? cross_pos : toe_pos;
    for (int i = 0; i <= max_pos; i++) {
        if (i == cross_pos) {
            printf("%c", cross);
        } else if (i == toe_pos) {
            printf("%c", toe);
        } else {
            printf("%c", space);
        }
    }
}
