//
// Created by tokoyama on 26/01/21.
//

#ifndef DSALAB_QUESTION_A_H
#define DSALAB_QUESTION_A_H

#endif //DSALAB_QUESTION_A_H
#include <stdio.h>

const int N = 1005;

char a[N], b[N], ans[N];

void solve()
{
    scanf("%s\n%s", a, b);
    int A = 0, B = 0;
    while(a[A] != '\0')
        A++;
    while(b[B] != '\0')
        B++;
    A--, B--;
    int Lans = (A > B ? A : B), carry = 0;
    ans[Lans + 1] = '\0';
    while(A >= 0 || B >= 0)
    {
        int val = carry;
        if(A >= 0) val += a[A] - '0';
        if(B >= 0) val += b[B] - '0';
        if(val >= 10) val -= 10, carry = 1;
        else carry = 0;
        ans[Lans] = val + '0';
        A--, B--, Lans--;
    }

    if(carry != 0)
        printf("%d", carry);
    printf("%s\n", ans);

}