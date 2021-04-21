//
// Created by tokoyama on 12/04/21.
//

#include <stdio.h>

#ifndef DSALAB_B_H
#define DSALAB_B_H

#endif //DSALAB_B_H

int min(int a, int b)
{
    return (a < b) ? a : b;
}

void solve()
{
    int n;

    scanf("%d",&n);
    int dp[n+1];
    for (int i = 0; i <= n; ++i) {
        dp[i]=1e9;
    }
    dp[0]=0;
    for (int i = 0; i <=n; ++i) {
        int t=i;
        while(t!=0)
        {
            if(i-t%10>=0)
            dp[i]=min(dp[i],dp[i-t%10]+1);
            t/=10;
        }

    }
    printf("%d",dp[n]);
}