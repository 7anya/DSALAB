//
// Created by tokoyama on 11/02/21.
//

#ifndef DSALAB_QUESTION_C_H
#define DSALAB_QUESTION_C_H

#endif //DSALAB_QUESTION_C_H
#include<stdio.h>
#define N 100005

int a[N], n, m;

void merge(int a[], int l, int m, int r)
{
    int temp[r - l];
    int X = l, Y = m;
    for(int i = 0; i < r - l; i++)
    {
        if(Y == r || (X < m && a[X] < a[Y]))
            temp[i] = a[X++];
        else
            temp[i] = a[Y++];
    }
    for(int i = l; i < r; i++)
        a[i] = temp[i - l];
}

void sort(int a[], int l, int r)
{
    if(r - l == 1)
        return;
    int m = (l + r) / 2;
    sort(a, l, m), sort(a, m, r);
    merge(a, l, m, r);
}

int check(int x)
{
    int cnt = 0, prv = - 1e9 - 5;
    for(int i = 1; i <= m; i++)
        if(a[i] - prv >= x)
            cnt++, prv = a[i];
    return cnt >= n;
}

int main()
{
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= m; i++)
        scanf("%d", &a[i]);
    sort(a, 1, m + 1);
    int lo = 0, hi = 1e9+1;
    while(hi - lo > 1)
    {
        int mid = (lo + hi) / 2;
        if(check(mid))
            lo = mid;
        else
            hi = mid;
    }
    printf("%d", lo);
    return 0;
}