//
// Created by tokoyama on 23/01/21.
//

#ifndef DSALAB_QUESTION_J_H
#define DSALAB_QUESTION_J_H

#endif //DSALAB_QUESTION_J_H

#include <stdio.h>
#include <memory.h>

int visited[500], queue[100], qsize = 0, qlast = 0;



int  BFS(int a[120][120], int start,int n,int ans[]) {
    int control=1;
    queue[qlast++] = start;
    ans[start]=control;

    qsize++;
    visited[start] = 1;
    int vis, first = 0;
    while (qsize != 0) {
        vis = queue[first];
//        printf("%d ##", vis);
//        if(ans[i])
//        ans[vis]=control;
        if(control==1)
            control=0;
        else
            control=1;
        first++;
        qsize--;
        for (int i = 0; i < n; i++) {
            if (a[vis][i] == 1 && visited[i] == 0) {
                queue[qlast++] = i;
                qsize++;
                visited[i] = 1;
                if(ans[vis]==1)
                    ans[i]=0;
                else
                    ans[i]=1;
//                ans[i]=control;
//                printf("%d ",i);

            }
            if(a[vis][i] == 1 && visited[i] == 1)
            {
                if(ans[i]==ans[vis]) {
                    printf("NEED MORE COLOURS");
                return 0;
                }
            }

        }
//        printf("\n");
    }
    return 1;
}

void solveJ() {


    int n, m;
//    printf("Enter the number of vertices \n");
    scanf("%d", &m);
    scanf("%d", &n);
//    printf("Enter the adjacency matrix\n");
    int adj[120][120], ans[100];
    memset(ans,0,sizeof(ans));

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
//    for (int i = 0; i < n; ++i) {
//        for (int j = 0; j < n; ++j) {
//            printf("%d ", adj[i][j]);
//
//        }
//        printf("\n");
//
//    }
//    printf("\n");
    for (int i = 0; i < n; ++i) {
        visited[i] = 0;

    }
//    printf("The breadth first traversal is:\n");
    if(BFS(adj, 0, n,ans)==1) {

        for (int i = 0; i < n; i++)
            if(ans[i]==0)
                    printf("B");
            else
                printf("R");
    }



}
