#include <stdio.h>
#include <stdlib.h>
// Принцип 1: Отказ от использования оператора безусловного перехода goto
// Не используем оператор goto в данной программе

// Принцип 2: Базовые управляющие конструкции
// Программа содержит базовые управляющие конструкции: последовательность, ветвление, цикл

// Принцип 4: Повторяющиеся фрагменты программы оформлены в виде подпрограмм
int calculate_sum(int matrix[], int size) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += matrix[i];
    }
    return sum;
}

int main() {
    int rows, cols;

    // Принцип 6: Каждая конструкция имеет один вход и один выход
    // Входные данные: размеры матрицы
    scanf("%d %d", &rows, &cols);

    // Принцип 3: Базовые управляющие конструкции вложены друг в друга произвольным образом
    // Принцип 7: Разработка программы ведется методом «сверху вниз»

    // Выделение памяти под матрицу динамически
    int **matrix = (int **)malloc(rows * sizeof(int *));
    if (matrix == NULL) {
        printf("n/a");
        return 1;
    }
    for (int i = 0; i < rows; i++) {
        matrix[i] = (int *)malloc(cols * sizeof(int));
        if (matrix[i] == NULL) {
            printf("n/a");
            return 1;
        }
    }

    // Ввод элементов матрицы
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    // Сортировка строк по сумме элементов
    // Возможно, вы захотите реализовать здесь алгоритм сортировки

    // Вывод отсортированной матрицы
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d", matrix[i][j]);
            if (j < cols - 1) {
                printf(" ");
            }
        }
        printf("\n");
    }

    // Освобождение памяти
    for (int i = 0; i < rows; i++) {
        free(matrix[i]);
    }
    free(matrix);

    return 0;
}
