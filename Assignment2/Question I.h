//
// Created by tokoyama on 04/02/21.
//

#ifndef DSALAB_QUESTION_I_H
#define DSALAB_QUESTION_I_H

#endif //DSALAB_QUESTION_I_H



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
        ch[s[0]-'a']++;
    }
    for (int i = 0; i < 26; ++i) {
        printf("%d ",ch[i]);
    }
}