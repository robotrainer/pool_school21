#include <stdio.h>

int fPScore = 0;
int sPScore = 0;

void cross_and_toe_display(int flag);
int f_board_key(char key, int fRStart, int fREnd, int min_pos_y, int max_pos_y);
int second_board_key(char key, int sRStart, int sREnd, int min_pos_y, int max_pos_y);

int main(void) {
    while (1) {
        int flag = 1;
        cross_and_toe_display(flag);
    }
}


void cross_and_toe_display(int flag) {
    // racket start positions
    int fRStart = 5;
    int fREnd = 7;
    int firstRacketX = 3;
    int sRStart = 17;
    int sREnd = 19;
    int secondRacketX = 76;

    char vertical = '|';
	char horizontal = '-';
    char space = ' ';
	char point = '*';

	int pointX = 39;
	int pointY = 12;
	int pointSpeedX = 1;
	int pointSpeedY = 1;

	int max_pos_y = 25;
	int max_pos_x = 80;
    int min_pos_y = 1;
	int pole[max_pos_y][max_pos_x];
    printf("\033[0d\033[2J");
    while (flag) {
	printf("\033[0d\033[2J");
	for (int i = 0; i < max_pos_y; i++) {
		for (int j = 0; j < max_pos_x; j++) {
			if (j == 0 || j == max_pos_x - 1) {
				pole[i][j] = vertical;
			} else if (i == 0 || i == max_pos_y - 1) {
				pole[i][j] = horizontal;
			} else if (i == pointY && j == pointX) {
				pole[i][j] = point;
			} else if ( (i >= fRStart && i <= fREnd && j == firstRacketX) ||
                       (i >= sRStart && i <= sREnd && j == secondRacketX)) {
				pole[i][j] = vertical;
			} else if ((i != 0 && i != max_pos_y) || (j != 0 && j != max_pos_x)) {
				pole[i][j] = space;
			}
		}
	}
        if (pointY == 23)
            pointSpeedY = -1;
        if (pointY == 1)
            pointSpeedY = 1;
        if (pointX == 79) {
            if (fPScore != 20) {
                fPScore++;
            } else {
                printf("Win First player!");
                break;}
            flag = 0;
        }
        if (pointX == 0) {
            if (sPScore != 20) {
                sPScore++;
            } else {
                printf("Win Second player!");
                break;}
            flag = 0;
        }

        if ((sRStart <= pointY && pointY <= sREnd && pointX == secondRacketX - 1))
            pointSpeedX = -1;
        if (fRStart <= pointY && pointY <= fREnd && pointX == firstRacketX + 1)
            pointSpeedX = 1;

	for (int i = 0; i < max_pos_y; i++) {
		for (int j = 0; j < max_pos_x; j++) {
			printf("%c", pole[i][j]);
		}
		printf("%c", '\n');
	}
        printf("Points First's player: %d\n", fPScore);
        printf("Points Second's player: %d\n", sPScore);

        char key = getchar();

        if (f_board_key(key, fRStart, fREnd, min_pos_y, max_pos_y) == 1) {
            fRStart++;
            fREnd++;
        } else if (f_board_key(key, fRStart, fREnd, min_pos_y, max_pos_y) == 1) {
            fRStart--;
            fREnd--;
        }

        if (second_board_key(key, sRStart, sREnd, min_pos_y, max_pos_y) == 1) {
            sRStart++;
            sREnd++;
        } else if (second_board_key(key, sRStart, sREnd, min_pos_y, max_pos_y) == -1) {
            sRStart--;
            sREnd--;
        }

        if (key == '\n') {
            pointX += pointSpeedX;
            pointY += pointSpeedY;
        }
    }
}

int f_board_key(char key, int fRStart, int fREnd, int min_pos_y, int max_pos_y) {
    if (key == 'a' && fRStart != min_pos_y)
        return -1;
    if (key == 'z' && fREnd != max_pos_y - 2)
        return 1;
    return 0;
}

int second_board_key(char key, int sRStart, int sREnd, int min_pos_y, int max_pos_y) {
    if (key == 'k' && sRStart != min_pos_y)
        return -1;
    if (key == 'm' && sREnd != max_pos_y - 2)
        return 1;
    return 0;
}
