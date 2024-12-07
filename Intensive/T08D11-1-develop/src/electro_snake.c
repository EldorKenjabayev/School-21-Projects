#include <stdio.h>
#include <stdlib.h>

void sort_vertical(int **matrix, int n, int m, int ***result_matrix);
void sort_horizontal(int **matrix, int n, int m, int ***result_matrix);
void input(int ***matrix, int *n, int *m);
void output(int **matrix, int n, int m);

int main() {
    int **matrix, **result;
    int n = 0, m = 0;

    input(&matrix, &n, &m);
    if (n <= 0 || m <= 0) {
        printf("n/a");
        return 1;
    }

    sort_vertical(matrix, n, m, &result);
    output(result, n, m);
    printf("\n");

    sort_horizontal(matrix, n, m, &result);
    output(result, n, m);

    for (int i = 0; i < n; i++) {
        free(matrix[i]);
        free(result[i]);
    }
    free(matrix);
    free(result);

    return 0;
}

void input(int ***matrix, int *n, int *m) {
    scanf("%d %d", n, m);
    if (*n <= 0 || *m <= 0) {
        return;
    }

    *matrix = (int **)malloc(*n * sizeof(int *));
    if (*matrix == NULL) {
        printf("n/a");
        exit(1);
    }

    for (int i = 0; i < *n; i++) {
        (*matrix)[i] = (int *)malloc(*m * sizeof(int));
        if ((*matrix)[i] == NULL) {
            printf("n/a");
            exit(1);
        }
        for (int j = 0; j < *m; j++) {
            scanf("%d", &((*matrix)[i][j]));
        }
    }
}

void output(int **matrix, int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%d", matrix[i][j]);
            if (j != m - 1) {
                printf(" ");
            }
        }
        printf("\n");
    }
}

void sort_vertical(int **matrix, int n, int m, int ***result_matrix) {
    *result_matrix = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++) {
        (*result_matrix)[i] = (int *)malloc(m * sizeof(int));
    }

    int row = 0, col = 0;
    for (int j = 0; j < m; j++) {
        if (j % 2 == 0) {
            for (int i = 0; i < n; i++) {
                (*result_matrix)[i][col] = matrix[row++][j];
            }
        } else {
            for (int i = n - 1; i >= 0; i--) {
                (*result_matrix)[i][col] = matrix[row++][j];
            }
        }
        col++;
        row = 0;
    }
}

void sort_horizontal(int **matrix, int n, int m, int ***result_matrix) {
    *result_matrix = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++) {
        (*result_matrix)[i] = (int *)malloc(m * sizeof(int));
    }
    int row = 0;
    for (int i = 0; i < n; i++) {
        int col = 0;
        if (i % 2 == 0) {
            for (int j = 0; j < m; j++) {
                (*result_matrix)[row][j] = matrix[i][col++];
            }
        } else {
            for (int j = m - 1; j >= 0; j--) {
                (*result_matrix)[row][j] = matrix[i][col++];
            }
        }
        row++;
    }
}
