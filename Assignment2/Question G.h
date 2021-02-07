//
// Created by tokoyama on 04/02/21.
//

#include <stdio.h>
#include <stdlib.h>

#ifndef DSALAB_QUESTION_G_H
#define DSALAB_QUESTION_G_H

#endif //DSALAB_QUESTION_G_H





int compare(const void * a, const void * b)
{
    return ( *(int*)a > *(int*)b );
}

void solveG()
{
    int n;
    scanf("%d",&n);
    int a[n];
    for (int i = 0; i < n; ++i) {
        scanf("%d",&a[i]);
    }
    int b,k;
    scanf("%d",&b);
    qsort(a, n, sizeof(int), compare);
//    for (int i = 0; i < n; ++i) {
//        printf("%d ",a[i]);
//    }
    for (int i = n-1; i>=0 ; --i) {
        if(a[0]+a[i]<=b)
        {
             k = i;
            break;
        }
    }
    printf("%d",k);
    int ans= n-1-k + (k&1?k/2+1:k/2);
    printf("\n%d",ans);
}