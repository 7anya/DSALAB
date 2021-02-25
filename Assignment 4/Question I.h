//
// Created by tokoyama on 25/02/21.
//

#include <stdio.h>

#ifndef DSALAB_QUESTION_I_H
#define DSALAB_QUESTION_I_H

#endif //DSALAB_QUESTION_I_H
int MOD=7+1000000000;
int fa(int x)
{
    int ans = 1;
    for(int i=1;i<=x;i++)
    {
        ans *= i;
        ans %= MOD;
    }
    return ans;
}

void solve ()
{


    int n,m,pos,i,j;
    scanf("%d",&n);
    scanf("%d",&m);
    scanf("%d",&pos);
    int x = n - m;
    int y = m - 1;

    int l = 0, r = n;
    int ans = 1;
    int fl = 0;

    while(l < r)
    {
        int mm = (l + r) / 2;
        if(mm < pos)
        {
            ans *= y;
            ans %= MOD;
            y--;
            if(y < 0)
            {
                printf("0") ;
                return ;
            }
            l = mm + 1;
        }
        else if(mm > pos)
        {
            ans *= x;
            ans %= MOD;
            x--;
            if(x < 0)
            {
                printf("0") ;
                return ;
            }
            r = mm;
        }
        else
        {
            l = mm + 1;
        }
    }
    // cout << ans << endl;

    // cout << x << " " << y << endl;
    ans *= fa(y+x);
    ans %= MOD;
    printf("%d",ans) ;


    return ;
}