//
// Created by tokoyama on 25/02/21.
//

#include <stdio.h>
#include <stdbool.h>
#include <memory.h>
#include <string.h>
#include <zconf.h>

#ifndef DSALAB_QUESTION_H_H
#define DSALAB_QUESTION_H_H

#endif //DSALAB_QUESTION_H_H


int check(char ans[],int start,int end,char s[],int n)
{
    int visited[200];
    memset(visited,0, sizeof(visited));
    for (int i = start; i < end; ++i) {
        visited[ans[i]] = 1;
    }
    for (int i = 0; i < n; ++i) {
        if(visited[s[i]]==0) {
//            printf("false");
            return 0;
        }

    }
//    printf("true");
    return 1;
}
void solve()
{
    int n,m=INT_MAX;
    char s[100000];
    scanf("%d",&n);
    scanf("%s",s);
    char ans[100000];
    int i=0,end=0,start=0;
    check(ans,start,end,s,n);
    while(i<n)
    {
        ans[end++]=s[i++];

        if(ans[start]==ans[end-1] &&end-start>1)
            start++;
//        while(ans[start])
//        for (int j = start; j< end; ++j) {
//            printf("%c",ans[j]);
//        }
//        printf("\n");
       if(check(ans,start,end,s,n)==1) {
           char x=ans[start];
           for (int j = start ; j <end ; ++j) {
               if(ans[j]!=x)
               {
                   start=j-1;
                   break;
               }
           }

           if (end - start < m)
               m = end - start;
       }
    }
    printf("%d",m);
}