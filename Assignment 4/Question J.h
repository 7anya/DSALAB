//
// Created by tokoyama on 25/02/21.
//

#include <stdbool.h>
#include <memory.h>

#ifndef DSALAB_QUESTION_J_H
#define DSALAB_QUESTION_J_H

#endif //DSALAB_QUESTION_J_H







void solve()
{
    int n,t;
    scanf("%d",&n);
    scanf("%d",&t);
    bool visited[100000];
    memset(visited,false,sizeof(visited));
    int a[n];
    for (int i = 0; i < n; ++i) {
        scanf("%d",&a[i]);
        visited[a[i]]=true;
    }
    for (int i = 0; i < t; ++i)
    {
        int c;
        scanf("%d",&c);
        if(visited[c]==true)
            printf("YES\n");
        else
            printf("NO\n");
    }

}