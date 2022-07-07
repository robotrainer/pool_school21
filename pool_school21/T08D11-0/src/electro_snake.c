#include <stdio.h>
#include <stdlib.h>

/*
    1 6 7
    2 5 8
    3 4 9
*/
void sort_vertical(int **matrix, int n, int m, int **result_matrix); //int **result_matrix

/*
    1 2 3
    6 5 4
    7 8 9
*/
// void sort_horizontal(int **matrix, int n, int m, int **result_matrix);

/*
    7 8 9
    6 1 2
    5 4 3
*/
// void sort_spiral(int **matrix, int n, int m, int **result_matrix);

void input(int **matrix, int n, int m);
void output(int **matrix, int n, int m);


int main() {
    int **matrix = NULL;
    int **result = NULL;
    int n,m;
    if (scanf("%d%d", &n, &m) == 2 && n > 0 && m > 0) {
        matrix = (int**) calloc(n, sizeof(int*));
        for (int i = 0; i < n; i++ ) {
            matrix[i] = (int*) calloc(m, sizeof(int));
        }
        input(matrix, n, m);
    }

    if (matrix != NULL) {
        result = (int**) calloc(n, sizeof(int*));
        for (int i = 0; i < n; i++ ) {
            result[i] = (int*) calloc(m, sizeof(int));
        }

        sort_vertical(matrix, n, m, result);
        output(result, n, m);
        free(matrix);
        free(result);
        
        // sort_horizontal(matrix, n, m, result);
        // output(result, n, m);
        
        // sort_spiral(matrix, n, m, result);
        // output(result, n, m);
    } else {
        printf("n/a");
    }
    return 0;
}

void sort_vertical(int **matrix, int n, int m, int **result_matrix) {
    int min;
    int k = 0;
    int l = 0;
    while (l < m) {
        k = 0;
        while (k < n) {
            for (int i = 0; i < n; i++) {
                min = matrix[0][0];
                for (int j = 0; j < m; j++) {
                    if (min >= matrix[i][j]) {
                        min = matrix[i][j];
                        matrix[i][j] = ~(1 << (8 * sizeof(int)-1));
                    }
                }
            }
            result_matrix[k][l] = min;
            k++;
        }
        l++;
    }
}

void input(int **matrix, int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (scanf("%d", &matrix[i][j]) != 1) {
                matrix = NULL;
                break;
            }
        }
    }
}

void output(int **matrix, int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%d", matrix[i][j]);
            if (j != m - 1)
                printf(" ");
            if (j == m - 1)
                printf("\n");
        }
    }
}

// int input(int **matrix, int n, int m) {
//     int rtn = 0;
//     for (int i = 0; i < n; i++) {
//         for (int j = 0; j < m; j++) {
//             if (scanf("%d", &matrix[i][j]) != 1) {
//                 rtn = 0;
//                 break;
//             } else {
//                 rtn = 1;
//             }
//         }
//     }
//     return rtn;
// }
