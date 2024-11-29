#include <stdio.h>
#define ARR_SIZE 10

int input_arr(int *array, int size);
int sort(int *array, int size);
int output(int *array, int size);
int main() {
    int array[ARR_SIZE];
    input_arr(array, ARR_SIZE);
    sort(array, ARR_SIZE);
    output(array, ARR_SIZE);
    return 0;
}

int input_arr(int *arry, int size) {
    for (int i = 0; i < size; i++) {
        if (scanf("%d", &arry[i]) != 1) {
            printf("n/a \n");
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
}

int output(int *array, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
}