//
// Created by tokoyama on 04/02/21.
//

#include <stdio.h>
#include <string.h>
#ifndef DSALAB_QUESTION_E_H
#define DSALAB_QUESTION_E_H

#endif //DSALAB_QUESTION_E_H


#define N 100005

int n, k, flg = 0;
char ans[N], s[N];

void recur(int idx)
{
    if(idx == k)
    {
        if(flg) printf("\n");
        flg = 1;
        printf("%s", ans);
        return;
    }
    for(int i = 0; i < n; i++)
    {
        ans[idx] = s[i];
        recur(idx + 1);
    }
}

void solveE()
{
    scanf("%d %d\n", &n, &k);
    scanf("%s", s);
    ans[k] = '\0';
    recur(0);

}