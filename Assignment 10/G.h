//
// Created by tokoyama on 13/04/21.
//

#include <stdio.h>

#ifndef DSALAB_G_H
#define DSALAB_G_H

#endif //DSALAB_G_H

int max(int a, int b) {
    return (a > b) ? a : b;
}


void solve() {
    int n, m;
    scanf("%d %d", &n, &m);
    char a[1001], b[1001];
    scanf("%s %s", a, b);
    int dp[n + 1][m + 1];
    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j <= m; ++j) {
            dp[i][j] = 0;
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {

            if (a[i] == b[j])
                dp[i + 1][j + 1] = 1 + dp[i][j];
            else
                dp[i + 1][j + 1] = max(dp[i][j +1], dp[i+1][j]);
        }
    }
    printf("%d",dp[n][m]);
}