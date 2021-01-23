//
// Created by tokoyama on 21/01/21.
//
#include <stdio.h>
#include <stdlib.h>
#ifndef DSALAB_QUESTION_D_H
#define DSALAB_QUESTION_D_H

#endif //DSALAB_QUESTION_D_H
int compare(const void * a, const void * b)
{
    return ( *(int*)a > *(int*)b );
}

int shopping()
{
    int n,m;
    scanf("%d",&m);
    scanf("%d",&n);
    int a[n];
    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);
    qsort(a, n, sizeof(int), compare);
//    for(int i=0;i<n;i++)
//        printf("%d",a[i]);
    int count=0,cost=0;
    for (int i = 0; i < n; ++i) {
        if(cost+a[i]>m)
            break;
        cost+=a[i];
        count++;
    }
    printf("answer: %d",count);

}