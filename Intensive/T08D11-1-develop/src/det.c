#include <stdio.h>
#include <stdlib.h>

double det(double **matrix, int n);
void input_matrix(double ***matrix, int *n);
void free_matrix(double **matrix, int n);

int main() {
    double **matrix;
    int n;

    input_matrix(&matrix, &n);
    if (matrix == NULL) {
        printf("n/a\n");
        return 1;
    }

    double determinant = det(matrix, n);

    if (determinant == -1) {
        printf("n/a\n");
    } else {
        printf("%.6lf\n", determinant);
    }

    free_matrix(matrix, n);

    return 0;
}

void input_matrix(double ***matrix, int *n) {
    if (scanf("%d", n) != 1 || *n <= 0) {
        *matrix = NULL;
        return;
    }

    *matrix = (double **)malloc(*n * sizeof(double *));
    if (*matrix == NULL) {
        *n = 0;
        return;
    }

    for (int i = 0; i < *n; i++) {
        (*matrix)[i] = (double *)malloc(*n * sizeof(double));
        if ((*matrix)[i] == NULL) {
            for (int j = 0; j < i; j++) {
                free((*matrix)[j]);
            }
            free(*matrix);
            *matrix = NULL;
            *n = 0;
            return;
        }
    }

    for (int i = 0; i < *n; i++) {
        for (int j = 0; j < *n; j++) {
            if (scanf("%lf", &((*matrix)[i][j])) != 1) {
                free_matrix(*matrix, *n);
                *matrix = NULL;
                *n = 0;
                return;
            }
        }
    }
}

double det(double **matrix, int n) {
    double det = 1;

    for (int i = 0; i < n; i++) {
        if (matrix[i][i] == 0) {
            return -1;
        }
        for (int j = i + 1; j < n; j++) {
            double factor = matrix[j][i] / matrix[i][i];
            for (int k = i; k < n; k++) {
                matrix[j][k] -= factor * matrix[i][k];
            }
        }
        det *= matrix[i][i];
    }

    return det;
}

void free_matrix(double **matrix, int n) {
    if (matrix != NULL) {
        for (int i = 0; i < n; i++) {
            free(matrix[i]);
        }
        free(matrix);
    }
}
