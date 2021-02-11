//
// Created by tokoyama on 04/02/21.
//

#ifndef DSALAB_QUESTION_D_H
#define DSALAB_QUESTION_D_H

#endif //DSALAB_QUESTION_D_H



#include <stdio.h>
#define N 100005
#define mod 1000000007
#define int long long

int a[N], p[N], n, m;

int power(int a, int b, int m)
{
    int res = 1;
    a %= m;
    while (b > 0)
    {
        if(b & 1)
            res = res *a % m;
        a = a *a % m;
        b >>= 1;
    }

    return res;
}

int modinv(int k)
{
    return power(k, mod - 2, mod);
}

int right(int idx)
{
    if(idx >= m)
        return m;
    else
        return idx;
}

int left(int idx)
{
    if(idx <= n - m + 1)
        return 1;
    else
        return idx - (n - m);
}

void solveD()
{
    scanf("%d %d\n", &n, &m);
    a[0] = 1;
    p[0] = 1;
    for(int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    for(int i = 1; i <= m; i++)
        scanf("%d", &p[i]);
    for(int i = 1; i <= m; i++)
    {
        p[i] = (p[i] *p[i - 1]) % mod;
    }

    for(int i = 1; i <= n; i++)
    {
        a[i] = (((a[i] *p[right(i)]) % mod) *modinv(p[left(i) - 1])) % mod;
        if(i > 1)
            printf(" ");
        printf("%d", a[i]);
    }


}