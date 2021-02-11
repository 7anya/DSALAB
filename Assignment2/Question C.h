//
// Created by tokoyama on 04/02/21.
//

#include <stdio.h>
#include <memory.h>

#ifndef DSALAB_QUESTION_C_H
#define DSALAB_QUESTION_C_H

#endif //DSALAB_QUESTION_C_H

void solveC()
{
    int n;
    scanf("%d",&n);
    int  x,y,w[n+1],l[n+1];
    memset(w,0,sizeof(w));
    memset(l,0,sizeof(l));
    for (int i=0;i<n*(n-1)/2-1;i++)
    {
        scanf("%d",&x);
        scanf("%d",&y);
        w[x]++;
        l[y]++;
    }
    int ans[2],k=0;
    for (int i = 1; i <=n ; ++i) {
        if(w[i]+l[i]==n-2)
            ans[k++]=i;
//        printf("%d %d \n",w[i],l[i]);

    }
    if(w[ans[0]]>w[ans[1]])
    {
        printf("%d %d",ans[0],ans[1]);

    }
    else
    {
        printf("%d %d",ans[1],ans[0]);
    }

}