#include <stdio.h>
#include <math.h>

double calculate_function(double x) {
    double result;
    if (x == 0) {
        return NAN;
    }
    result = 7e-3 * pow(x, 4) + ((22.8 * pow(x, 1.0/3) - 1e3) * x + 3) / (x * x / 2) - x * pow(10 + x, 2.0/x) - 1.01;

    return result;
}

int main() {
    double x, result;
    if (scanf("%lf", &x) != 1) {
        printf("n/a\n");
        return 1;
    }

    result = calculate_function(x);

    if (isnan(result)) {
        printf("n/a\n");
    } else {
        printf("%.1lf\n", result);
    }

    return 0;
}
