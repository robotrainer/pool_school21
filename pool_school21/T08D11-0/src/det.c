#include <stdio.h>
#include <stdlib.h>

double det(double **matrix, int n, int m);
void input(double **matrix, int *n, int *m);
void output(double det);

void main()
{

}

double det(double **matrix, int n, int m) {

}

void input(double **matrix, int *n, int *m) {

}

void output(double det) {

}

int input(int **buffer, int length_n, int length_m) {
    int rtn = 0;
    for (int i = 0; i < length_n; i++) {
        for (int j = 0; j < length_m; j++) {
            if (scanf("%d", &buffer[i][j]) != 1) {
                rtn = 0;
                break;
            } else {
                rtn = 1;
            }
        }
    }
    return rtn;
}

void output(int **buffer, int length_n, int length_m) {
    for (int i = 0; i < length_n; i++) {
        for (int j = 0; j < length_m; j++) {
            printf("%d", buffer[i][j]);
            if (j != length_m - 1)
                printf(" ");
            if (j == length_m - 1)
                printf("\n");
        }
    }
}