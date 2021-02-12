//
// Created by tokoyama on 11/02/21.
//

#include <stdio.h>

#ifndef DSALAB_QUESTION_D_H
#define DSALAB_QUESTION_D_H

#endif //DSALAB_QUESTION_D_H






void solveD()
{
    int n,k1,k2;
    scanf("%d",&n);
    scanf("%d",&k1);
    scanf("%d",&k2);
    int k=k2-k1;
    int a[n],b[n],c[n];
    for (int i = 0; i < n; ++i) {

        scanf("%d",&a[i]);

    }
    for (int i = 0; i < n; ++i) {

        scanf("%d",&b[i]);

    }
    for (int i = 0; i < n; ++i) {
        c[i]=a[i]-b[i];
    }
    int cnt=0;
    for (int i = 0; i < n; ++i) {
        for (int j = i+1; j < n; ++j) {
            if(c[i]+c[j]>k)
                cnt++;
        }
    }
    printf("%d",cnt);




}