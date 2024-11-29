#include <stdio.h>

void inputArray(int *arr, int n);
void cycleShift(int *arr, int n, int c);
void printArray(int *arr, int n);
int main() {
    int n, c;
    if (scanf("%d", &n) != 1 || n <= 0 || n > 10) {
        printf("n/a\n");
        return 1;
    }

    int arr[10];
    inputArray(arr, n);
    if (scanf("%d", &c) != 1) {
        printf("n/a\n");
        return 1;
    }

    cycleShift(arr, n, c);
    printArray(arr, n);

    return 0;
}
void inputArray(int *arr, int n) {
    printf("Введите %d целых чисел:\n", n);
    for (int i = 0; i < n; i++) {
        if (scanf("%d", &arr[i]) != 1) {
            printf("n/a\n");
            return;
        }
    }
}

void cycleShift(int *arr, int n, int c) {
    if (n <= 0 || n > 10) {
        printf("n/a\n");
        return;
    }
    c %= n;
    if (c < 0) c += n;

    int temp[c];
    for (int i = 0; i < c; i++) {
        temp[i] = arr[i];
    }
    for (int i = 0; i < n - c; i++) {
        arr[i] = arr[i + c];
    }
    for (int i = 0; i < c; i++) {
        arr[n - c + i] = temp[i];
    }
}

void printArray(int *arr, int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}