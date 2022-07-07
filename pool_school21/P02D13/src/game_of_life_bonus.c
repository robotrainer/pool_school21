#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ncurses.h>
#include <unistd.h>

#define WIDTH 80
#define HEIGHT 25
#define CELL 'o'
#define DEAD_CELL ' '
#define SPEED 1000000

char** calloc_matrix(int width, int height);
void init_world(char** field);
void update_world(char** field);
void draw_world(char** field);
int get_count_of_neighbors(char** field, int x0, int y0);

int main() {
    char** field = calloc_matrix(WIDTH + 1, HEIGHT);
    char button = ' ';
    int speed = SPEED;
    initscr();
    curs_set(0);
    start_color();
    init_pair(1, COLOR_BLACK, COLOR_YELLOW);
    init_pair(2, COLOR_BLUE, COLOR_BLACK);
    init_world(field);
    draw_world(field);
    nodelay(stdscr, TRUE);
    while (button != '\04') {
        button = getch();
        if (button == ERR) update_world(field);
        if (button == 'w' && speed > 10000) speed /= 2;
        if (button == 's' && speed < SPEED) speed *= 2;
        draw_world(field);
        refresh();
        usleep(speed);
    }
    endwin();
    free(field);

    return 0;
}

void clear_matrix(char** field, int width, int height) {
    for (int row = 0; row < height; row++) {
        for (int col = 0; col < width; col++) {
            field[row][col] = DEAD_CELL;
        }
    }
}

void clear_field(char** field) {
    clear_matrix(field, WIDTH, HEIGHT);
    for (int row = 0; row < HEIGHT; row++) {
        field[row][WIDTH] = '\0';
    }
}

char** get_five();
char** get_house();
char** get_glider();
char** get_frog();
char** get_spaceshipL();
void add_figure(char** field, char** figure, int x0, int y0);

void init_world(char** field) {
    clear_field(field);

    char** figure;

    figure = get_glider();
    add_figure(field, figure, 14, 13);
    free(figure);

    figure = get_house();
    add_figure(field, figure, WIDTH / 2, HEIGHT / 2);
    free(figure);

    figure = get_five();
    add_figure(field, figure, WIDTH, HEIGHT);
    free(figure);
}

int correctX(int x) {
    if (x < 0) return x += WIDTH;
    if (x >= WIDTH) return x -= WIDTH;
    return x;
}

int correctY(int y) {
    if (y < 0) return y += HEIGHT;
    if (y >= HEIGHT) return y -= HEIGHT;
    return y;
}

int get_count_of_neighbors(char** field, int x0, int y0) {
    int count = 0;
    int x, y;
    for (int phi = 0; phi < 360; phi += 45) {
        x = round(cos(phi * 3.14159265 / 180));
        y = round(sin(phi * 3.14159265 / 180));

        if (field[correctY(y0 + y)][correctX(x0 + x)] == CELL) {
            count += 1;
        }
    }
    return count;
}

void dead_or_life(char** field, int x, int y, int neighbors) {
    if (neighbors < 2) field[y][x] = DEAD_CELL;
    else if (neighbors > 3) field[y][x] = DEAD_CELL;
}

void copy_matrix(char** source, char** destination) {
    for (int row = 0; row < HEIGHT; row++) {
        for (int col = 0; col < WIDTH; col++) {
            destination[row][col] = source[row][col];
        }
    }
}

void update_world(char** field) {
    char** field2;
    field2 = calloc_matrix(WIDTH + 1, HEIGHT);
    copy_matrix(field, field2);

    int neighbors;
    for (int row = 0; row < HEIGHT; row++) {
        for (int col = 0; col < WIDTH; col++) {
            neighbors = get_count_of_neighbors(field2, col, row);
            if (field2[row][col] == CELL)
                dead_or_life(field, col, row, neighbors);
            if (neighbors == 3)
                field[row][col] = CELL;
        }
    }

    free(field2);
}

void draw_world(char** field) {
    clear();
    for (int row = 0; row < HEIGHT; row++) {
        for (int col = 0; col < WIDTH; col++) {
            if (field[row][col] == CELL) {
                color_set(1, NULL);
            } else {
                color_set(2, NULL);
            }
            mvaddstr(row, col, &field[row][col]);
        }
    }
}

char** calloc_matrix(int width, int height) {
    char** matrix = (char**) calloc(height + width * height, sizeof(char*));
    char* arrays = (char*) (matrix + height);
    for (int row = 0; row < height; row++) {
        matrix[row] = &arrays[row * width];
    }
    return matrix;
}

#define FIGURES_SIZE 5

void add_figure(char** field, char** figure, int x0, int y0) {
    int x, y;
    for (int i = 0; i < FIGURES_SIZE; i++) {
        for (int j = 0; j < FIGURES_SIZE; j++) {
            x = correctX(x0 + j);
            y = correctY(y0 + i);
            field[y][x] = figure[i][j];
        }
    }
}

// !!! Выделяется память !!! Не забыть очистить после исползования функций !!!
char** get_glider() {
    char** glider = calloc_matrix(FIGURES_SIZE, FIGURES_SIZE);
    clear_matrix(glider, FIGURES_SIZE, FIGURES_SIZE);
    glider[0][1] = CELL;
    glider[1][2] = CELL;
    glider[2][0] = CELL;
    glider[2][1] = CELL;
    glider[2][2] = CELL;
    return glider;
}

char** get_house() {
    char** house = calloc_matrix(FIGURES_SIZE, FIGURES_SIZE);
    clear_matrix(house, FIGURES_SIZE, FIGURES_SIZE);

    house[0][1] = CELL;
    house[1][0] = CELL;
    house[1][1] = CELL;
    house[1][2] = CELL;

    return house;
}

char** get_five() {
    char** five = calloc_matrix(FIGURES_SIZE, FIGURES_SIZE);
    clear_matrix(five, FIGURES_SIZE, FIGURES_SIZE);

    five[0][1] = CELL;
    five[0][2] = CELL;
    five[1][0] = CELL;
    five[1][1] = CELL;
    five[2][1] = CELL;

    return five;
}

char** get_frog() {
    char** frog = calloc_matrix(FIGURES_SIZE, FIGURES_SIZE);
    clear_matrix(frog, FIGURES_SIZE, FIGURES_SIZE);

    frog[0][1] = CELL;
    frog[0][2] = CELL;
    frog[0][3] = CELL;
    frog[1][0] = CELL;
    frog[1][1] = CELL;
    frog[1][2] = CELL;

    return frog;
}

char** get_spaceshipL() {
    char** spaceshipL = calloc_matrix(FIGURES_SIZE, FIGURES_SIZE);
    clear_matrix(spaceshipL, FIGURES_SIZE, FIGURES_SIZE);

    spaceshipL[0][3] = CELL;
    spaceshipL[1][4] = CELL;
    spaceshipL[2][0] = CELL;
    spaceshipL[2][4] = CELL;
    spaceshipL[3][1] = CELL;
    spaceshipL[3][2] = CELL;
    spaceshipL[3][3] = CELL;
    spaceshipL[3][4] = CELL;

    return spaceshipL;
}
