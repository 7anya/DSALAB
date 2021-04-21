//
// Created by tokoyama on 12/04/21.
//

#include <stdio.h>

#ifndef DSALAB_C_H
#define DSALAB_C_H

#endif //DSALAB_C_H


void solve() {
    int n;
    scanf("%d", &n);
    char a[n+1][n+1];
    for (int i = 0; i < n; ++i) {
            scanf("%s", a[i]);
    }
    int dp[n + 1][n + 1];
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            dp[i][j] = 0;
        }
    }
    int flag = 0;
    for (int i = 0; i < n; ++i) {
        if (a[i][0] == '*')
            flag = 1;
        if (flag == 1)
            dp[i][0] = 0;
        else dp[i][0] = 1;


    }
    flag = 0;
    for (int i = 0; i < n; ++i) {
        if (a[0][i] == '*') {
            flag = 1;
//            printf("looooool");
        }
        if (flag == 1)
            dp[0][i] = 0;
        else dp[0][i] = 1;


    }
    for (int i = 1; i < n; ++i) {
        for (int j = 1; j < n; ++j) {
            if (a[i][j] == '.') {
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
//                printf(".");
            }
        }

    }
    printf("%d", dp[n - 1][n - 1]);
}