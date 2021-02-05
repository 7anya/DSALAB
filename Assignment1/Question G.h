//
// Created by tokoyama on 23/01/21.
//

#ifndef DSALAB_QUESTION_G_H
#define DSALAB_QUESTION_G_H

#endif //DSALAB_QUESTION_G_H

#include <stdio.h>

int visited[500], queue[100], qsize = 0, qlast = 0;

void DFS(int a[120][120], int start, int n) {

//    printf("%d ", start);

    visited[start] = 1;

    for (int i = 0; i < n; i++) {
        if (a[start][i] == 1 && (visited[i]) == 0) {
            DFS(a, i, n);
        }
    }
}

int findMax(int **a, int n) {

    int count = 0;
    for (int v = 0; v < n; v++)
        visited[v] = 0;

    for (int v = 0; v < n; v++) {
        if (visited[v] == 0) {
            DFS(a, v, n);
            count += 1;
        }
    }

    return count;
}

//void BFS(int a[120][120], int start) {
//
//    queue[qlast++] = start;
//    qsize++;
//
//    visited[start] = 1;
//
//    int vis, first = 0;
//    while (qsize != 0) {
//        vis = queue[first];
//
//        printf("%d ", vis);
//
//        first++;
//        qsize--;
//
//        for (int i = 0; i < 12; i++) {
//            if (a[vis][i] == 1 && visited[i] == 0) {
//
//
//                queue[qlast++] = i;
//                qsize++;
//
//                visited[i] = 1;
//            }
//        }
//    }
//}

void solveG() {


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
    for (int i = 0; i < m; ++i) {
        scanf("%d", &x);
        scanf("%d", &y);
        adj[x][y] = 1;
        adj[y][x] = 1;
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            printf("%d ", adj[i][j]);

        }
        printf("\n");

    }

    for (int i = 0; i < n; ++i) {
        visited[i] = 0;

    }
    printf("The depth first traversal is:\n");
    DFS(adj, 0, n);
    printf("\n %d", findMax(adj, n));


}
