#include <stdio.h>
#include <stdlib.h>

int main() {
    int m, n;

    printf("Введіть кількість рядків (M): ");
    scanf("%d", &m);

    printf("Введіть кількість стовпців (N): ");
    scanf("%d", &n);

    int **x = (int **)malloc(m * sizeof(int *));
    if (x == NULL) {
        printf("Помилка виділення пам'яті для рядків матриці.\n");
        return 1;
    }
    for (int i = 0; i < m; i++) {
        x[i] = (int *)malloc(n * sizeof(int));
        if (x[i] == NULL) {
            printf("Помилка виділення пам'яті для елементів рядка %d.\n", i);
            for (int j = 0; j < i; j++) {
                free(x[j]);
            }
            free(x);
            return 1;
        }
    }

    printf("Введіть елементи матриці X[%d x %d]:\n", m, n);
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            printf("X[%d][%d] = ", i, j);
            scanf("%d", &x[i][j]);
        }
    }

    int *y = (int *)malloc(m * sizeof(int));
    if (y == NULL) {
        printf("Помилка виділення пам'яті для масиву Y.\n");
        for (int i = 0; i < m; i++) {
            free(x[i]);
        }
        free(x);
        return 1;
    }

    for (int i = 0; i < m; i++) {
        y[i] = 0;
        for (int j = 0; j < n; j++) {
            if (j > i) {
                y[i] += x[i][j];
            }
        }
    }

    printf("\nМасив Y (суми елементів нижче головної діагоналі для кожного рядка):\n");
    for (int i = 0; i < m; i++) {
        printf("Y[%d] = %d\n", i, y[i]);
    }

    for (int i = 0; i < m; i++) {
        free(x[i]);
    }
    free(x);
    free(y);

    return 0;
}
