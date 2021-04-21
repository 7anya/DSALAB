//
// Created by tokoyama on 16/03/21.
//

#include <stdio.h>

#ifndef DSALAB_A_H
#define DSALAB_A_H

#endif //DSALAB_A_H

struct task
{
    int priority;
    int time;
    int index;
};

void merge(struct task a[], int l, int m, int r)
{
    struct task temp[r - l];
    int X = l, Y = m;
    for(int i = 0; i < r - l; i++)
    {
        if(Y == r || (X < m &&( a[X].priority < a[Y].priority||(a[X].priority == a[Y].priority && a[X].time < a[Y].time ) )))
            temp[i] = a[X++];
        else
            temp[i] = a[Y++];
    }
    for(int i = l; i < r; i++)
        a[i] = temp[i - l];
}

void sort(struct task a[], int l, int r)
{
    if(r - l == 1)
        return;
    int m = (l + r) / 2;
    sort(a, l, m), sort(a, m, r);
    merge(a, l, m, r);
}


void solve()
{
    int n,k;
    scanf("%d",&n);
    scanf("%d",&k);
    struct task tasks[n];
    for(int i=0;i<n;i++)
    {
        scanf("%d",&tasks[i].time);
        scanf("%d",&tasks[i].priority);
        tasks[i].index=i;
    }
    sort(tasks,0,n);
//    for (int i = 0; i < n; ++i) {
//        printf("%d\n",tasks[i].index);
//    }
    for (int i = 0; i < k; ++i) {
        printf("%d ",tasks[i].index);
    }
}