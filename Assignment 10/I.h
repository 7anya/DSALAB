//
// Created by tokoyama on 13/04/21.
//

#include <stdio.h>
#include <memory.h>
#include <zconf.h>

#ifndef DSALAB_I_H
#define DSALAB_I_H

#endif //DSALAB_I_H

int min(int a, int b)
{
    return (a < b) ? a : b;
}
void solve() {
    int n, s;
    scanf("%d %d", &n, &s);
    int a[10001];
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
    }
    int dp[10000];
    dp[0]=0;
    for (int i = 1; i <= s; ++i) {
        dp[i] = INT_MAX;
    }
    for (int i = 0; i <= s; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i - a[j] >= 0 && dp[i - a[j]] != INT_MAX)
                    dp[i] =min(dp[i],dp[i - a[j]] + 1) ;
        }
//        printf("%d ", dp[i]);
    }
    if (dp[s] == INT_MAX)
        printf("-1");
    else
        printf("%d", dp[s]);

}