//
// Created by tokoyama on 11/02/21.
//

#ifndef DSALAB_QUESTION_H_H
#define DSALAB_QUESTION_H_H

#endif //DSALAB_QUESTION_H_H
#include<stdio.h>
#include <memory.h>

void solveH() {
    int n, m;
//    printf("Enter the number of vertices \n");
    scanf("%d", &m);
    scanf("%d", &n);
//    printf("Enter the adjacency matrix\n");
    int adj[120][120];

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            adj[i][j] = 0;

        }

    }
    int x, y;
    int in[n];
    memset(in,0,sizeof(n));
    for (int i = 0; i < m; ++i) {
        scanf("%d", &x);
        scanf("%d", &y);
        adj[x][y] = 1;
        in[y]++;
//            printf("%d **",i);

    }
    for (int i = 0; i < n; ++i) {
        printf("%d ",in[i]);
    }

}