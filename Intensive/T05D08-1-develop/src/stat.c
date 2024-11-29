#include <stdio.h>
#define NMAX 10

int input(int *a, int *n);
int find_max(int *a, int n);
int find_min(int *a, int n);
void output(int *a, int n);
double mean(int *a, int n);
double variance(int *a, int n);
void output_result(int max_v, int min_v, double mean_v, double variance_v);

int main() {
    int n, data[NMAX];
    input(data, &n);
    int max_val = find_max(data, n);
    int min_val = find_min(data, n);
    double mean_val = mean(data, n);
    double variance_val = variance(data, n);

    output(data, n);
    output_result(max_val, min_val, mean_val, variance_val);

    return 0;
}

int input(int *a, int *n) {
    if (scanf("%d", n) != 1) {
        return 0;
    }
    for (int i = 0; i < *n; i++) {
        if (scanf("%d", &a[i]) != 1) {
            return 0;
        }
    }
    return 1;
}

int find_max(int *a, int n) {
    int max_value = a[0];
    for (int i = 1; i < n; i++) {
        if (a[i] > max_value) {
            max_value = a[i];
        }
    }
    return max_value;
}
int find_min(int *a, int n) {
    int min_value = a[0];
    for (int i = 1; i < n; i++) {
        if (a[i] < min_value) {
            min_value = a[i];
        }
    }
    return min_value;
}

void output(int *a, int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}

double mean(int *a, int n) {
    double sum = 0;
    for (int i = 0; i < n; i++) {
        sum += a[i];
    }
    return sum / n;
}

double variance(int *a, int n) {
    double mean_val = mean(a, n);
    double var = 0;
    for (int i = 0; i < n; i++) {
        var += (a[i] - mean_val) * (a[i] - mean_val);
    }
    return var / n;
}

void output_result(int max_v, int min_v, double mean_v, double variance_v) {
    printf("%d ", max_v);
    printf("%d ", min_v);
    printf("%f ", mean_v);
    printf("%f\n ", variance_v);
}
