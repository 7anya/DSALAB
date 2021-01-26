//
// Created by tokoyama on 21/01/21.
//
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

#ifndef DSALAB_QUESTION_F_H
#define DSALAB_QUESTION_F_H

#endif //DSALAB_QUESTION_F_H

int isPrime(int n) {
    for (int i = 2; i * i <= n; ++i)
        if (n % i == 0)
            return 0;
    return 1;
}

void Primes() {
    int a, b;
    scanf("%d", &a);
    scanf("%d", &b);
    int arr[b - a + 1], ind = 0;
    for (int i = a; i <= b; ++i) {
        if (isPrime(i))
            arr[ind++] = i;

    }
    int f[10];
    memset(f, 0, sizeof(f));
    for (int i = 0; i < ind; ++i) {
        while (arr[i] != 0) {
            f[arr[i] % 10]++;
            arr[i] /= 10;
        }
    }
    int ans = 0, max = 0;
    for (int j = 0; j < 10; ++j) {
        if (f[j] > max) {
            max = f[j];
            ans = j;
        }

    }
    printf("%d %d", ans, max);
}