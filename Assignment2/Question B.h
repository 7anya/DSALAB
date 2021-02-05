//
// Created by tokoyama on 04/02/21.
//

#ifndef DSALAB_QUESTION_B_H
#define DSALAB_QUESTION_B_H

#endif //DSALAB_QUESTION_B_H

#include <stdio.h>

int visited[500], queue[100], qsize = 0, qlast = 0, count = 0;

void DFS(int a[120][120], int start, int n) {

//    printf("%d ", start);
    count++;
    visited[start] = 1;

    for (int i = 0; i < n; i++) {
        if (a[start][i] == 1 && (visited[i]) == 0) {
            DFS(a, i, n);

        }
    }
}

int findMax(int **a, int n) {

    int max = 0;
    for (int v = n - 1; v >= 0; v--) {
        count = 0;

        for (int i = 0; i < n; ++i) {
            visited[i] = 0;

        }
        DFS(a, v, n);
        if (count > max)
            max = count;
//        printf("%d=%d \n", v, count);


    }

    return max;
}


void solveB() {


    int n, m;
//    printf("Enter the number of vertices \n");
    scanf("%d", &m);
    scanf("%d", &n);
//    printf("Enter the adjacency matrix\n");
    int adj[120][120];
    n++;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            adj[i][j] = 0;

        }

    }
    int x, y;
    for (int i = 0; i < m; ++i) {
        scanf("%d", &x);
        scanf("%d", &y);
        adj[x][y] = 1;
//        printf("%d **",i);
//        adj[y][x] = 1;
    }
//    for (int i = 0; i < n; ++i) {
//        for (int j = 0; j < n; ++j) {
//            printf("%d ", adj[i][j]);
//
//        }
//        printf("\n");
//
//    }

    for (int i = 0; i < n; ++i) {
        visited[i] = 0;

    }
//    printf("The depth first traversal is:\n");
//    DFS(adj, 5, n);
    printf("%d", findMax(adj, n));


}
