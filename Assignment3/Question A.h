//
// Created by tokoyama on 11/02/21.
//

#include <stdio.h>

#ifndef DSALAB_QUESTION_A_H
#define DSALAB_QUESTION_A_H

#endif //DSALAB_QUESTION_A_H

void solveA()
{
    int n,m,k;
    scanf("%d",&n);
    scanf("%d",&m);
    scanf("%d",&k);

    int a[n], b[m];
    for (int i = 0; i < n; ++i) {
        scanf("%d",&a[i]);
    }
    for (int i = 0; i < m; ++i) {
        scanf("%d",&b[i]);
    }

    int c=0;
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if(b[i]-k<=a[j] && b[i]+k>=a[j])
            {
                c++;
//                printf("hello\n");
                break;
            }

        }
    }
    printf("%d",c);
}