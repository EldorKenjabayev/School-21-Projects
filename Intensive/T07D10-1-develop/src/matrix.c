#include <stdio.h>
#include <stdlib.h>

void input_static_matrix(int ***matrix, int rows, int cols);
void input_dynamic_matrix(int ***matrix, int rows, int cols);
void output_matrix(int **matrix, int rows, int cols);
void cleanup_matrix(int **matrix, int rows);

int main() {
    int choice;
    int rows, cols;
    int **matrix = NULL;
    scanf("%d", &choice);

    scanf("%d %d", &rows, &cols);

    switch (choice) {
        case 1:
            input_static_matrix(&matrix, rows, cols);
            break;
        case 2:
            input_dynamic_matrix(&matrix, rows, cols);
            break;
        case 3:
            input_dynamic_matrix(&matrix, rows, cols);
            break;
        case 4:
            input_dynamic_matrix(&matrix, rows, cols);
            break;
        default:
            printf("n/a");
            return 1;
    }

    output_matrix(matrix, rows, cols);

    cleanup_matrix(matrix, rows);

    return 0;
}

void input_static_matrix(int ***matrix, int rows, int cols) {
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
