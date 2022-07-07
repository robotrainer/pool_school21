#include <stdio.h>
#include <stdlib.h>
#define NMAX 100

int input(int **buffer, int length_n, int length_m);
int input_type_size(int *type, int *length_n, int *length_m);
void output(int **buufer, int length_n, int length_m);
void free_matrix(int type, int **buffer, int length_n);

int main() {
    int type, n, m;
    int **array = NULL;
    int *a;

    if (input_type_size(&type, &n, &m)) {
        if (type == 1) {
            int arr[NMAX][NMAX];
            int *a[NMAX];
            for (int i = 0; i < n; i++) {
                a[i] = &arr[i][0];
            }
            array = a;
        }

        if (type == 2) {
            array = (int**) calloc(n, sizeof(int*));
            for (int i = 0; i < n; i++) {
                array[i] = (int*) calloc(m, sizeof(int));
            }
        }

        if (type == 3) {
            array = (int**) calloc(n, sizeof(int*));
            a = (int*) calloc(n*m, sizeof(int));
            for (int i = 0; i < n; i++) {
                array[i] = &a[i*m];
            }
        }
        if (type == 4) {
            array = (int**) malloc(n * sizeof(int*) + n * m * sizeof(int));
            for (int i = 0; i < n; i++) {
                array[i] = (int*) (array + n + i * m);
            }
        }

        if (array != NULL) {
            if (input(array, n, m)) {
                output(array, n, m);
                if (type != 3 && type != 1) {
                    free_matrix(type, array, n);
                } else if (type == 3) {
                    free(a);
                    free(array);
                    a = 0;
                    array = 0;
                }
            } else {
                printf("n/a");
            }
        }

    } else {
        printf("n/a");
    }

    return 0;
}

int input_type_size(int *type, int *length_n, int *length_m) {
    int rtn = 0;
    char ch;
    if (scanf("%d%d%d%c", type, length_n, length_m, &ch) == 4 && ch == '\n')
        rtn = 1;
    if (*type <= 0 || *type > 4)
        rtn = 0;
    return rtn;
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

void free_matrix(int type, int **buffer, int length_n) {
    if (type == 2) {
        for (int i = 0; i < length_n; i++) {
            free(buffer[i]);
            buffer[i] = 0;
        }
        free(buffer);
        buffer = 0;
    }
    if (type == 4) {
        free(buffer);
        buffer = 0;
    }
}
