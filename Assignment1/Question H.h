//
// Created by tokoyama on 21/01/21.
//
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#ifndef DSALAB_QUESTION_H_H
#define DSALAB_QUESTION_H_H

#endif //DSALAB_QUESTION_H_H
void rotateArray(int a[],int n)
{
    int temp=a[0];
    for(int i=0;i<n-1;i++)
        a[i]=a[i+1];
    a[n-1]=temp;


}
int cost(int a[],int n)
{
    int c1=0,c2=0;
    for (int i = 0; i < n; ++i) {
        if(i&1)
            c1+= a[i]*a[i]*a[i];
        else
            c2+=a[i]*a[i];

    }
    return c2-c1;
}

void costDifference()
{
    int n;
    scanf("%d",&n);
    int a[n];
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);

    }
    int max=INT_MIN,min=INT_MAX;
    for(int i=1;i<n;i++)
    {
        int c;
        c = cost(a, n);
        if(c>max)
            max=c;
        else if(c<min)
            min=c;
        rotateArray(a,n);

    }
    printf("%d",max-min);
}