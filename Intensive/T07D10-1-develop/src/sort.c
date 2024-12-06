#include <stdio.h>
#include <stdlib.h>

int input_arr(int *array, int size);
int sort(int *array, int size);
int output(int *array, int size);

int main() {
    int *array;
    int size;

    if (scanf("%d", &size) != 1 || size <= 0) {
        fprintf(stderr, "n/a");
        return 1;
    }

    array = (int *)malloc(size * sizeof(int));
    if (array == NULL) {
        fprintf(stderr, "n/a");
        return 1;
    }

    if (input_arr(array, size) != 0) {
        free(array);
        return 1;
    }

    sort(array, size);
    output(array, size);
    free(array);

    return 0;
}

int input_arr(int *array, int size) {
    for (int i = 0; i < size; i++) {
        if (scanf("%d", &array[i]) != 1) {
            fprintf(stderr, "n/a");
            return 1;
        }
    }
    return 0;
}

int sort(int *array, int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (array[j] > array[j + 1]) {
                int temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
    return 0;
}

int output(int *array, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    return 0;
}
