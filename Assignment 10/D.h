//
// Created by tokoyama on 12/04/21.
//

#include <stdio.h>

#ifndef DSALAB_D_H
#define DSALAB_D_H

#endif //DSALAB_D_H

int max(int a, int b)
{
    return (a > b) ? a : b;
}

int knapSack(int W,int w[],int c[],int n )
{
    int dp[n+1][W+1];

    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=W;j++)
        {
            if(i==0|| j==0)
                dp[i][j]=0;
            else if (j-w[i-1]>=0)
                   dp[i][j]=max(dp[i-1][j],dp[i-1][j-w[i-1]]+c[i-1]);
            else
                dp[i][j]=dp[i-1][j];
//            printf("%d  ",dp[i][j]);
        }
//        printf("\n");
    }
    printf("%d++++++++++",dp[n][W]);
    return dp[n][W];
}

void solve()
{
    int n,W;

    scanf("%d %d",&n,&W);
    int w[n+1],c[n+1];
    for (int i = 0; i < n; ++i) {
        scanf("%d",&w[i]);
    }
    for (int i = 0; i < n; ++i) {
        scanf("%d",&c[i]);
    }
//    for (int i = 0; i < n; ++i) {
//        printf("%d*",c[i]);
//    }
    printf("%d",knapSack(W,w,c,n));
}