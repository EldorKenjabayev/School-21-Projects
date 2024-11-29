#include <stdio.h>

#define LEN 100

void sum(int *buff1, int len1, int *buff2, int len2, int *result, int *result_length);
void sub(int *buff1, int len1, int *buff2, int len2, int *result, int *result_length);

void sum(int *buff1, int len1, int *buff2, int len2, int *result, int *result_length) {
    if (len1 <= 0 || len2 <= 0 || len1 > LEN || len2 > LEN) {
        printf("n/a");
        return;
    }

    int i, carry = 0;

    int res[LEN + 1] = {0};

    for (i = 0; i < LEN; i++) {
        int digit1 = (i < len1) ? buff1[len1 - 1 - i] : 0;
        int digit2 = (i < len2) ? buff2[len2 - 1 - i] : 0;
        int sum = digit1 + digit2 + carry;
        res[LEN - 1 - i] = sum % 10;
        carry = sum / 10;
    }

    *result_length = LEN;
    while (*result_length > 0 && res[LEN - *result_length] == 0) {
        (*result_length)--;
    }

    for (i = 0; i < *result_length; i++) {
        result[i] = res[LEN - *result_length + i];
    }
}

void sub(int *buff1, int len1, int *buff2, int len2, int *result, int *result_length) {
    if (len1 <= 0 || len2 <= 0 || len1 > LEN || len2 > LEN) {
        printf("n/a");
        return;
    }

    int i;
    for (i = 0; i < len1; i++) {
        if (buff1[i] > buff2[i] || (i == len1 - 1 && len1 == len2)) {
            break;
        } else if (buff1[i] < buff2[i]) {
            printf("n/a");
            return;
        }
    }

    int res[LEN] = {0};

    int borrow = 0;
    for (i = 0; i < len1; i++) {
        int digit1 = buff1[len1 - 1 - i];
        int digit2 = (i < len2) ? buff2[len2 - 1 - i] : 0;

        if (digit1 < digit2 + borrow) {
            res[len1 - 1 - i] = 10 + digit1 - digit2 - borrow;
            borrow = 1;
        } else {
            res[len1 - 1 - i] = digit1 - digit2 - borrow;
            borrow = 0;
        }
    }

    *result_length = len1;
    while (*result_length > 0 && res[LEN - *result_length] == 0) {
        (*result_length)--;
    }

    for (i = 0; i < *result_length; i++) {
        result[i] = res[LEN - *result_length + i];
    }
}

int main() {
    int num1[] = {1, 9, 4, 4, 6, 7, 4, 4, 0, 7, 3, 7, 0, 9, 5, 5, 1, 6, 1};
    int len1 = sizeof(num1) / sizeof(num1[0]);

    int num2[] = {2, 9};
    int len2 = sizeof(num2) / sizeof(num2[0]);

    int result[LEN];
    int result_length;

    sum(num1, len1, num2, len2, result, &result_length);

    printf("Sum: ");
    for (int i = 0; i < result_length; i++) {
        printf("%d ", result[i]);
    }
    printf("\n");

    sub(num1, len1, num2, len2, result, &result_length);

    printf("Difference: ");
    for (int i = 0; i < result_length; i++) {
        printf("%d ", result[i]);
    }
    printf("\n");

    return 0;
}