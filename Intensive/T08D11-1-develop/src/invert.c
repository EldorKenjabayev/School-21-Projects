#include <stdio.h>
#include <stdlib.h>

void invert(double **matrix, int n);
void input(double ***matrix, int *n);
void output(double **matrix, int n);
void free_matrix(double **matrix, int n);

int main() {
    double **matrix;
    int n;

    input(&matrix, &n);
    if (n == 0) {
        printf("n/a");
        return 1;
    }

    invert(matrix, n);
    output(matrix, n);

    free_matrix(matrix, n);
    return 0;
}

void invert(double **matrix, int n) {
    double **identity = (double **)malloc(n * sizeof(double *));
    for (int i = 0; i < n; i++) {
        identity[i] = (double *)malloc(n * sizeof(double));
        for (int j = 0; j < n; j++) {
            identity[i][j] = (i == j) ? 1 : 0;
        }
    }

    for (int i = 0; i < n; i++) {
        if (matrix[i][i] == 0) {
            printf("n/a\n");
            return;
        }
        double factor = 1.0 / matrix[i][i];
        for (int j = 0; j < n; j++) {
            matrix[i][j] *= factor;
            identity[i][j] *= factor;
        }

        for (int k = 0; k < n; k++) {
            if (k != i) {
                double factor = matrix[k][i];
                for (int j = 0; j < n; j++) {
                    matrix[k][j] -= factor * matrix[i][j];
                    identity[k][j] -= factor * identity[i][j];
                }
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            matrix[i][j] = identity[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        free(identity[i]);
    }
    free(identity);
}

void input(double ***matrix, int *n) {
    int rows = 0, cols = 0;
    scanf("%d %d", &rows, &cols);

    if (rows != cols || rows <= 0) {
        *n = 0;
        return;
    }

    *n = rows;

    *matrix = (double **)malloc(*n * sizeof(double *));
    for (int i = 0; i < *n; i++) {
        (*matrix)[i] = (double *)malloc(*n * sizeof(double));
    }
    for (int i = 0; i < *n; i++) {
        for (int j = 0; j < *n; j++) {
            scanf("%lf", &((*matrix)[i][j]));
        }
    }
}

void output(double **matrix, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%.6lf", matrix[i][j]);
            if (j != n - 1) {
                printf(" ");
            }
        }
        if (i != n - 1) {
            printf("\n");
        }
    }
}

void free_matrix(double **matrix, int n) {
    for (int i = 0; i < n; i++) {
        free(matrix[i]);
    }
    free(matrix);
}
