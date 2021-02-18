//
// Created by tokoyama on 11/02/21.
//

#include <stdio.h>

#ifndef DSALAB_QUESTION_B_H
#define DSALAB_QUESTION_B_H

#endif //DSALAB_QUESTION_B_H







void solveB()
{
    int n,m;
    scanf("%d",&n);
    scanf("%d",&m);

    int a[n], skill[m],gold[m];
    for (int i = 0; i < n; ++i) {
        scanf("%d",&a[i]);
    }
    for (int i = 0; i < m; ++i) {
        scanf("%d",&skill[i]);
        scanf("%d",&gold[i]);
    }
    int ans=0;
    for (int i = 0; i < n; ++i) {
        ans=0;
        for (int j = 0; j < m; ++j) {
            if(a[i]>=skill[j])
                ans+=gold[j];

        }
        printf("%d ",ans);
    }


}
