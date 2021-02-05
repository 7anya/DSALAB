//
// Created by tokoyama on 04/02/21.
//

#ifndef DSALAB_QUESTION_F_H
#define DSALAB_QUESTION_F_H

#endif //DSALAB_QUESTION_F_H
// C program to Count set
// bits in an integer
#include <stdio.h>

int log2(int n)
{
    int ret = 0;
    while (n>>=1)
    {
        ++ret;
    }
    return ret;
}

int power(int x,int y)
{
    int ret=1,i=0;
    while(i<y)
    {
        ret*=x;
        i++;
    }
    return ret;
}

int getcount(int m,int k)
{
    if(m==0)
        return 1;
    if(k<0)
        return 0;
    if(k==0)
        return 1;
    if(m>=power(2,k))
        return getcount(m-power(2,k),k)+getcount(m,k-1);
    else
        return getcount(m,k-1);

}

void solveF()
{
    int m=0;
    while(scanf("%d",&m))
    {
        int k=log2(m);
        printf("%d\n",getcount(m,k));

    }
//    return 0;
}