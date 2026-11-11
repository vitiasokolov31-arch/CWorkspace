
#include <stdio.h>
#include <string.h>

void search(char log[], char word[]) {
    int count = 0;
    int n = strlen(log);
    int m = strlen(word);

    for (int i = 0; i <= n - m; i++) {
        int j;
        for (j = 0; j < m; j++) {
            if (log[i + j] != word[j])
                break;
        }

        if (j == m) {
            printf("Позиция: %d\n", i);
            count++;
        }
    }

    printf("Количество: %d\n", count);
}

int main() {
    char log[] = "error: disk error, then error again";
    char word[] = "error";

    search(log, word);

    return 0;
}
