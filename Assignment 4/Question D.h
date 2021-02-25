//
// Created by tokoyama on 22/02/21.
//

#ifndef DSALAB_QUESTION_D_H
#define DSALAB_QUESTION_D_H

#endif //DSALAB_QUESTION_D_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int visited[500], queue[100], qsize = 0, qlast = 0;
float count = 0;;

void DFS(float a[120][120][2], int start, int n) {

//    printf("%d ", start);

    visited[start] = 1;

    for (int i = 0; i < n; i++) {
        if (a[start][i][0] == 1 && (visited[i]) == 0) {
//            DFS(a, i, n);
            count+=a[start][i][1];
        }
    }
}

void findMax(float a[120][120][2], int n) {

    for (int v = 0; v < n; v++)
        visited[v] = 0;

    for (int v = 0; v < n; v++) {

            DFS(a, v, n);
        for (int v = 0; v < n; v++)
            visited[v] = 0;
        printf("%d: %f\n ",v,count);
        count=0;

    }
//    printf("%f",)
//    return count;
}



void solveD() {


    int n, m;
//    printf("Enter the number of vertices \n");
    scanf("%d", &n);
    scanf("%d", &m);
//    printf("Enter the adjacency matrix\n");
   float adj[120][120][2];

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            adj[i][j][0] = 0;
            adj[i][j][0] = 0;

        }

    }
    int x, y;
    float weight;
    for (int i = 0; i < m; ++i) {
        scanf("%d", &x);
        scanf("%d", &y);
        scanf("%f", &weight);
        adj[x][y][0] = 1;
        adj[x][y][1] = weight;

    }


    for (int i = 0; i < n; ++i) {
        visited[i] = 0;

    }
    printf("The depth first traversal is:\n");
//    DFS(adj, 0, n);
    for (int i = 0; i < n; ++i) {
        visited[i] = 0;

    }
    findMax(adj, n);
//    printf("\n %d", findMax(adj, n));


}