#include <stdio.h>
#include <stdlib.h>

#define MAX_ROWS 100
#define MAX_COLS 100

void input_static_matrix(int ***matrix, int rows, int cols);
void input_dynamic_matrix(int ***matrix, int rows, int cols);
void output_matrix(int **matrix, int rows, int cols);
void cleanup_matrix(int **matrix, int rows);
void calculate_max_row(int **matrix, int rows, int cols, int *max_row);
void calculate_min_column(int **matrix, int rows, int cols, int *min_column);

int main() {
    int choice;
    int rows, cols;
    int **matrix = NULL;

    if (scanf("%d", &choice) != 1) {
        printf("n/a");
        return 1;
    }

    if (scanf("%d %d", &rows, &cols) != 2) {
        printf("n/a");
        return 1;
    }

    switch (choice) {
        case 1:
            input_static_matrix(&matrix, rows, cols);
            break;
        case 2:
        case 3:
        case 4:
            input_dynamic_matrix(&matrix, rows, cols);
            break;
        default:
            printf("n/a");
            return 1;
    }

    output_matrix(matrix, rows, cols);

    int max_row[rows];
    int min_column[cols];
    calculate_max_row(matrix, rows, cols, max_row);
    calculate_min_column(matrix, rows, cols, min_column);
    printf("\n");

    for (int i = 0; i < rows; i++) {
        printf("%d ", max_row[i]);
    }
    printf("\n");

    for (int i = 0; i < cols; i++) {
        printf("%d ", min_column[i]);
    }
    printf("\n");

    cleanup_matrix(matrix, rows);

    return 0;
}

void input_static_matrix(int ***matrix, int rows, int cols) {
    if (rows > MAX_ROWS || cols > MAX_COLS) {
        printf("n/a");
        exit(1);
    }

    *matrix = (int **)malloc(MAX_ROWS * sizeof(int *));
    if (*matrix == NULL) {
        printf("n/a");
        exit(1);
    }
    for (int i = 0; i < MAX_ROWS; i++) {
        (*matrix)[i] = (int *)malloc(MAX_COLS * sizeof(int));
        if ((*matrix)[i] == NULL) {
            printf("n/a");
            exit(1);
        }
    }

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (scanf("%d", &(*matrix)[i][j]) != 1) {
                printf("n/a");
                exit(1);
            }
        }
    }
}

void input_dynamic_matrix(int ***matrix, int rows, int cols) {
    *matrix = (int **)malloc(rows * sizeof(int *));
    if (*matrix == NULL) {
        printf("n/a");
        exit(1);
    }
    for (int i = 0; i < rows; i++) {
        (*matrix)[i] = (int *)malloc(cols * sizeof(int));
        if ((*matrix)[i] == NULL) {
            printf("n/a");
            exit(1);
        }
    }

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (scanf("%d", &(*matrix)[i][j]) != 1) {
                printf("n/a");
                exit(1);
            }
        }
    }
}

void output_matrix(int **matrix, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d", matrix[i][j]);
            if (j < cols - 1) {
                printf(" ");
            }
        }
        if (i < rows - 1) {
            printf("\n");
        }
    }
}

void cleanup_matrix(int **matrix, int rows) {
    if (matrix != NULL) {
        for (int i = 0; i < rows; i++) {
            free(matrix[i]);
        }
        free(matrix);
    }
}

void calculate_max_row(int **matrix, int rows, int cols, int *max_row) {
    for (int i = 0; i < rows; i++) {
        int max = matrix[i][0];
        for (int j = 1; j < cols; j++) {
            if (matrix[i][j] > max) {
                max = matrix[i][j];
            }
        }
        max_row[i] = max;
    }
}

void calculate_min_column(int **matrix, int rows, int cols, int *min_column) {
    for (int j = 0; j < cols; j++) {
        int min = matrix[0][j];
        for (int i = 1; i < rows; i++) {
            if (matrix[i][j] < min) {
                min = matrix[i][j];
            }
        }
        min_column[j] = min;
    }
}
