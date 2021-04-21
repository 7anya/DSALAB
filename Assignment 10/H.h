//
// Created by tokoyama on 13/04/21.
//

#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#ifndef DSALAB_H_H
#define DSALAB_H_H

#endif //DSALAB_H_H

int min(int a, int b) {
    return (a < b) ? a : b;
}


void solve() {
    int n;
    int a[(int) 10e5];
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
    }
    int dp[1000001];
    dp[0] = 0;
    dp[1] = abs(a[1] - a[0]);
    for (int i = 2; i < n; ++i) {
        dp[i] = min(dp[i - 1] + abs(a[i] - a[i - 1]), dp[i - 2] + abs(a[i] - a[i - 2]));
        printf("%d ", dp[i]);
    }
    printf("%d", dp[n - 1]);
}