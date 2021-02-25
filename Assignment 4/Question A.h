//
// Created by tokoyama on 24/02/21.
//

#include <stdio.h>
#include <stdbool.h>
#ifndef DSALAB_QUESTION_A_H
#define DSALAB_QUESTION_A_H

#endif //DSALAB_QUESTION_A_H
int ordering[26],ind=0;

int DFSforTopoSort(int i, int at, bool V[],char **adj, int n) {
    V[at] = true;
    for (int x=0;x<n;x++) {
        if (!V[x])
            i = DFSforTopoSort(i, adj[at][x] , V, adj, n);
    }
    ordering[i] = at;
    return i - 1;
}

void topologicalSort(char  **adj, int n) {

    bool V[n];
    for (int i = 0; i < n; ++i) {
        V[i] = false;
        ordering[i] = 0;
    }

    int i = n - 1;
    for (int at = 0; at < n; ++at) {
        if (!V[at])
            i = DFSforTopoSort(i, at, V, adj, n);
    }
    for (int i=0;i<n;i++)
        printf("%c", ordering[i]);
//    cout << ordering[i]<< " ";

}

void solve()
{
    int n;
    char a[n][n];
    int k=0;
    scanf("%d",&n);
    for (int i = 0; i < n; ++i) {
        char x,y;

    }
}