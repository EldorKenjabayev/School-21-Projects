#include <stdio.h>
int input(int **matrix, int *n, int *m);
int main() { int rows, cols, **matrix; }
int input(int **matrix, int *n, int *m) {
    if (scanf("%d %d", &n, &m) > 10 || scanf("%d %d", &n, &m) <= 1) {
        printf("n/a");
    }
}