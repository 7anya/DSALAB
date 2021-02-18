//
// Created by tokoyama on 11/02/21.
//

#ifndef DSALAB_QUESTION_F_H
#define DSALAB_QUESTION_F_H

#endif //DSALAB_QUESTION_F_H

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
int compare(const void * a, const void * b)
{
    return ( *(int*)a < *(int*)b );
}

int findMax(int **a, int n) {

    int max = 0;
    int b[1000];
    for (int v =0; v <n; v++) {
        count = 0;
        if (visited[v] == 0) {
            DFS(a, v, n);
//            printf("%d=%d \n", v, count);
            b[max++]=count;
        }

    }
    qsort(b, max, sizeof(int), compare);
    float s=0;
    for (int i = 0; i < max; ++i) {
        s+=(float )b[i];
    }
    s=s*0.8;
    int x=0,c=0;
    for (int i = 0; i < max; ++i) {
        if(x>=s)
            break;
        x+=b[i];
        c++;
    }


    return c;
}


void solveF() {


    int n, m;
//    printf("Enter the number of vertices \n");
    scanf("%d", &n);
    scanf("%d", &m);
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
//        printf("%d **",i);
        adj[y][x] = 1;
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