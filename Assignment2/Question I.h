//
// Created by tokoyama on 04/02/21.
//

#include <stdio.h>

#ifndef DSALAB_QUESTION_I_H
#define DSALAB_QUESTION_I_H

#endif //DSALAB_QUESTION_I_H

int fact(int n)
{

    return n*(n-1);
}

void solveI()
{
    int n,c,ch[26];
    for (int i = 0; i < 26; ++i) {
        ch[i]=0;
    }
    scanf("%d",&n);
    scanf("%d",&c);
    char s[100];
    for (int i = 0; i < n; ++i) {
        scanf("%s",s);
        ch[s[0]-'A']++;
    }
//    for (int i = 0; i < 26; ++i) {
//        printf("%d ",ch[i]);
//    }
    int sum=0,ans[1000],x=0;
    for (int i = 0; i < 26; ++i) {
        if(ch[i]>1)
        sum+=( ch[i]%c*fact(ch[i]/c+1)+(c-ch[i]%c)*fact(ch[i]/c))/2;
//        printf("\n%d",sum);
    }

    printf("%d",sum);

}