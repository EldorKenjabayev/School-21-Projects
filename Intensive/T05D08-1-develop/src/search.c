#include <stdio.h>
#include <math.h>

#define MAX_SIZE 30

int isEven(int num) {
    return num % 2 == 0;
}

double calculateMean(int arr[], int size) {
    double sum = 0;
    for (int i = 0; i < size; i++) {
        sum += arr[i];
    }
    return sum / size;
}

double calculateStdDev(int arr[], int size) {
    double mean = calculateMean(arr, size);
    double variance = 0;
    for (int i = 0; i < size; i++) {
        variance += pow(arr[i] - mean, 2);
    }
    variance /= size;
    return sqrt(variance);
}

int findNumber(int arr[], int size, int expected) {
    double mean = calculateMean(arr, size);
    double stdDev = calculateStdDev(arr, size);

    for (int i = 0; i < size; i++) {
        if (isEven(arr[i]) && arr[i] >= expected && arr[i] != 0) {
            if (fabs(arr[i] - mean) <= 3 * stdDev) {
                return arr[i];
            }
        }
    }
    return 0;
}


int main() {
    int n, arr[MAX_SIZE];
    if (scanf("%d", &n) != 1 || n <= 0 || n > MAX_SIZE) {
        printf("n/a\n");
        return 1; 
    }
    for (int i = 1; i < n; i++) {
        if (scanf("%d", &arr[i]) != 1) {
            printf("n/a\n");
            return 1;
        }
    }

    int expected;
    if (scanf("%d", &expected) != 1) {
        printf("n/a\n");
        return 1; 
    }
    int result = findNumber(arr, n, expected);
    printf("%d\n", result);

    return 0;
}
