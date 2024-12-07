#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

void input(double ***matrix, int *n, int *m) {
    if (scanf("%d %d", n, m) != 2) {
        printf("n/a");
        exit(1);
    }

    *matrix = (double **)malloc((*n) * sizeof(double *));
    for (int i = 0; i < *n; i++) {
        (*matrix)[i] = (double *)malloc((*m) * sizeof(double));
    }
    for (int i = 0; i < *n; i++) {
        for (int j = 0; j < *m; j++) {
            if (scanf("%lf", &((*matrix)[i][j])) != 1) {
                printf("n/a");
                exit(1);  // Exit the program if input is incorrect
            }
        }
    }
}

void output_roots(double *roots, int n) {
    for (int i = 0; i < n; i++) {
        printf("%.6lf", roots[i]);
        if (i != n - 1) {
            printf(" ");
        }
    }
}

bool gauss_elimination(double **matrix, int n, int m, double *roots) {
    for (int i = 0; i < n - 1; i++) {
        if (matrix[i][i] == 0) {
            int k = i + 1;
            while (k < n && matrix[k][i] == 0) {
                k++;
            }
            if (k == n) {
                return false;
            }
            for (int j = 0; j < m; j++) {
                double temp = matrix[i][j];
                matrix[i][j] = matrix[k][j];
                matrix[k][j] = temp;
            }
        }
        for (int k = i + 1; k < n; k++) {
            double factor = matrix[k][i] / matrix[i][i];
            for (int j = i; j < m; j++) {
                matrix[k][j] -= factor * matrix[i][j];
            }
        }
    }
    for (int i = n - 1; i >= 0; i--) {
        double sum = 0;
        for (int j = i + 1; j < n; j++) {
            sum += matrix[i][j] * roots[j];
        }
        roots[i] = (matrix[i][m - 1] - sum) / matrix[i][i];
    }
    return true;
}

int main() {
    double **matrix;
    int n, m;

    input(&matrix, &n, &m);

    double *roots = (double *)malloc(n * sizeof(double));

    if (gauss_elimination(matrix, n, m, roots)) {
        output_roots(roots, n);
    } else {
        printf("n/a\n");
    }
    for (int i = 0; i < n; i++) {
        free(matrix[i]);
    }
    free(matrix);
    free(roots);

    return 0;
}
