#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

int main() {
    int n;

    printf("Введіть розмір квадратної матриці (N <= %d): ", MAX_SIZE);
    scanf("%d", &n);

    if (n <= 0 || n > MAX_SIZE) {
        printf("Некоректний розмір матриці.\n");
        return 1;
    }

    double a[MAX_SIZE][MAX_SIZE];

    printf("Введіть елементи матриці:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("A[%d][%d] = ", i, j);
            scanf("%lf", &a[i][j]);
        }
    }

    for (int j = 0; j < n; j++) {
        double sum_even = 0;
        for (int i = 0; i < n; i++) {
            if (((int)a[i][j]) % 2 == 0) { 
                sum_even += a[i][j];
            }
        }
        printf("Сума парних елементів у стовпці %d: %.2lf\n", j + 1, sum_even);
    }

    return 0;
}