#include <stdio.h>
int fibonacci(int n) {
    if (n <= 1)
        return n;
    return fibonacci(n - 1) + fibonacci(n - 2);
}

int main() {
    int input;
    printf("Введите число из последовательности Фибоначчи: ");
    if (scanf("%d", &input) != 1) {
        // Обработка ошибок при вводе
        printf("n/a\n");
        return 1;
    }
    // Проверка на отрицательное число
    if (input < 0) {
        printf("n/a\n");
        return 1;
    }
    // Вычисление и вывод числа Фибоначчи
    printf("%d\n", fibonacci(input));
    return 0;
}
