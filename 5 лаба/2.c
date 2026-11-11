#include <stdio.h>
int main() {
    int x[20] = {
        3, 3, 3, 3, 7, 7, 9, 9, 9, 9,
        9, 9, 2, 4, 4, 4, 8, 8, 8, 8
    };
    int i, j, count, max = 0, maxValue = 0;
    int values[20], lengths[20];
    int n = 0;
    i = 0;

    while (i < 20) {
        count = 1;
        j = i + 1;

        while (j < 20 && x[i] == x[j]) {
            count++;
            j++;
        }
        values[n] = x[i];
        lengths[n] = count;
        n++;
        if (count > 2) {
            printf("Value %d, length %d\n", x[i], count);
        }
        if (count > max) {
            max = count;
            maxValue = x[i];
        }

        i = j;
    }
     printf("Самая длинная серия: \nValue: %d, length %d\n",
           maxValue, max);
    printf("Коэффициент сжатия: %.2f\n", 20.0 / n);

    printf("Восстановленнный массив:\n");

    int k = 0;

    for (i = 0; i < n; i++) {
        for (j = 0; j < lengths[i]; j++) {
            printf("%d ", values[i]);
        }
    }
    return 0;
}

