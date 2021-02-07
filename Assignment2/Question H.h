//
// Created by tokoyama on 04/02/21.
//

#include <stdio.h>
#include <memory.h>

#ifndef DSALAB_QUESTION_H_H
#define DSALAB_QUESTION_H_H

#endif //DSALAB_QUESTION_H_H


int leftChild(int i)
{
    return 2*i+1;
}

int rightChild(int i)
{
    return 2*i+2;
}



void solveH()
{
    int n;
    scanf("%d",&n);
    int a[n];
    for (int i = 0; i < n; ++i) {
        scanf("%d",&a[i]);
    }
    int level[n];
    for (int i = 0; i < n; ++i) {
       level[i]=1;
    }
    for (int i = 0; i <n; ++i) {
        if(leftChild(i)<n )
        level[leftChild(i)]=1+level[i];
        if(rightChild(i)<n )
        level[rightChild(i)]=1+level[i];

    }
    for (int i = 0; i < n; ++i) {
        printf("%d ",level[i]);
    }
    int s=0;
    for (int i = 0; i < n; ++i) {
        s+=a[i]*level[i];
    }
    printf("\n%d",s);
}