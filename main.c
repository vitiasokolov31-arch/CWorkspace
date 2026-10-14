#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 10

short get_rand_short() {
    int magnitude = rand() % 32768;
    int sign = rand() % 2 * 2 - 1;
    return (short)(magnitude * sign);
}

int main() {
    long long energy = 0;
    int ind = 0;
    srand(time(NULL));
    short I[N];
    short Q[N];
    for (int i = 0; i < N; i ++) {
        I[i] = get_rand_short();
        Q[i] = get_rand_short();
    }
    for (int i = 0; i < N; i++) {
        printf("s[%d] = %d + j*(%d)\n", i, I[i], Q[i]); 
    }
    for (int k = 0; k < N; k++) {
        long long i_val = I[k];
        long long q_val = Q[k];
        energy += i_val * i_val + q_val * q_val;
    }
    printf("Энергия сигнала равна: %lld\n", energy);
    short mx = I[0];
    for (int i = 1; i < N; i++) {
        if (I[i] > mx){
            mx = I[i];
            ind = i;
        }
    }
    printf("Максимальный элемент равен: %d\n", mx);
    printf("Индекс этого элемента: %d\n", ind);
    printf("Hello world");
    return 0;
}