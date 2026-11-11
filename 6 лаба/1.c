
#include <stdio.h>

double det(double a[3][3], int n) {
    if (n == 2)
        return a[0][0]*a[1][1] - a[0][1]*a[1][0];

    return a[0][0]*(a[1][1]*a[2][2]-a[1][2]*a[2][1])
         - a[0][1]*(a[1][0]*a[2][2]-a[1][2]*a[2][0])
         + a[0][2]*(a[1][0]*a[2][1]-a[1][1]*a[2][0]);
}

int main() {
    int N;
    double matrix[3][3], answers[3], t[3][3];

    printf("Введите N: ");
    scanf("%d", &N);
    
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++) {
            printf("matrix[%d][%d]: ", i, j);
            scanf("%lf", &matrix[i][j]);
        }

    for (int i = 0; i < N; i++) {
        printf("Свободный член [%d]: ", i);
        scanf("%lf", &answers[i]);
    }

    double d = det(matrix, N);

    if (d == 0) {
        printf("Определитель равен нулю");
        return 0;
    }

    for (int k = 0; k < N; k++) {
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                t[i][j] = (j == k) ? answers[i] : matrix[i][j];

        printf("x%d = %.2lf\n", k + 1, det(t, N) / d);
    }

    return 0;
}
