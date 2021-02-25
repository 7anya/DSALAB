//
// Created by tokoyama on 25/02/21.
//

#include <stdlib.h>
#include <stdio.h>

#ifndef DSALAB_QUESTION_E_H
#define DSALAB_QUESTION_E_H

#endif //DSALAB_QUESTION_E_H
 struct point
{
    int x;
    int y;

};
void print(struct point a[],int n)
{
    for (int i = 0; i < n; ++i) {
        printf("%d %d \n",a[i].x,a[i].y);
    }
    printf("********\n");
}
int manhattanDistance(int x1,int y1,int x2,int y2)
{
    return abs(x1-x2)+abs(y1-y2);
}
void bubble(struct point a[],int n)
{
    struct point temp;
    for (int i = 0; i < n-1; ++i) {
        for (int j = 0; j < n-i-1; ++j) {
            if(a[j].x>a[j+1].x) {
                temp = a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
            }

        }
    }
}
void bubble2(struct point a[],int n)
{
    struct point temp;
    for (int i = 0; i < n-1; ++i) {
        for (int j = 0; j < n-i-1; ++j) {
            if(a[j].x<a[j+1].x) {
                temp = a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
            }

        }
    }
}
void solve()
{
    int n;
    scanf("%d",&n);
    struct point a[n],b[n],c[n],ans[n+1],d[n];
    int na=0,nb=0,nc=0,nd=0;
    for (int i = 0; i < n; ++i) {
        int x,y;
        scanf("%d",&x);
        scanf("%d",&y);
        if(x>0 &&y>0)
        {
            a[na].x=x;
            a[na++].y=y;

        }
        else if(x<0 &&y>0)
        {
            b[nb].x=x;
            b[nb++].y=y;

        }
        else if(x<0 &&y<0)
        {
            c[nc].x=x;
            c[nc++].y=y;

        }
        else
        {
            d[nd].x=x;
            d[nd++].y=y;
        }
    }

    bubble2(a,na);
//    print(a,na);
    bubble2(b,nb);
//    print(b,nb);
    bubble(c,nc);
//    print(c,nc);
    bubble(d,nd);
//    print(d,nd);

    int ind=0;
    for (int i = 0; i < na; ++i) {
        ans[ind++]=a[i];
    }
    for (int i = 0; i < nb; ++i) {
        ans[ind++]=b[i];
    }
    for (int i = 0; i < nc; ++i) {
        ans[ind++]=c[i];
    }
    for (int i = 0; i < nd; ++i) {
        ans[ind++]=d[i];
    }
    ans[n]=ans[0];
//    print(ans,n+1);
    int dist=0;
    for (int i = 0; i < n; ++i) {
        dist+=manhattanDistance(ans[i].x,ans[i].y,ans[i+1].x,ans[i+1].y);
    }
    printf("%d",dist);
}