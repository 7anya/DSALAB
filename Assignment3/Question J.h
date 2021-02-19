//
// Created by tokoyama on 18/02/21.
//

#ifndef DSALAB_QUESTION_J_H
#define DSALAB_QUESTION_J_H

#endif //DSALAB_QUESTION_J_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct Edge {
    int src, dest, weight;
};


struct Graph {

    int V, E;
    struct Edge *edge;
};


struct Graph *createGraph(int V, int E) {
    struct Graph *graph = (struct Graph *) malloc(V * sizeof(struct Graph));

    graph->V = V;
    graph->E = E;

    graph->edge =(struct Edge *) malloc(E * sizeof(struct Edge));


    return graph;
}


struct subset {
    int parent;
    int rank;
};

int find(struct subset subsets[], int i) {

    if (subsets[i].parent != i)
        subsets[i].parent = find(subsets, subsets[i].parent);

    return subsets[i].parent;
}


void Union(struct subset subsets[], int x, int y) {
    int xroot = find(subsets, x);
    int yroot = find(subsets, y);


    if (subsets[xroot].rank < subsets[yroot].rank)
        subsets[xroot].parent = yroot;
    else if (subsets[xroot].rank > subsets[yroot].rank)
        subsets[yroot].parent = xroot;

    else {
        subsets[yroot].parent = xroot;
        subsets[xroot].rank++;
    }
}

int myComp(const void *a, const void *b) {
    struct Edge *a1 = (struct Edge *) a;
    struct Edge *b1 = (struct Edge *) b;
    return a1->weight > b1->weight;
}


void KruskalMST(struct Graph *graph) {
    int V = graph->V;
    struct Edge
            result[V];
    int e = 0;
    int i = 0;


    qsort(graph->edge, graph->E, sizeof(graph->edge[0]),
          myComp);

    // Allocate memory for creating V ssubsets
    struct subset *subsets = (struct subset *) malloc(V * sizeof(struct subset));

    for (int v = 0; v < V; ++v) {
        subsets[v].parent = v;
        subsets[v].rank = 0;
    }

    while (e < V - 1 && i < graph->E) {

        struct Edge next_edge = graph->edge[i++];

        int x = find(subsets, next_edge.src);
        int y = find(subsets, next_edge.dest);

        if (x != y) {
            result[e++] = next_edge;
            Union(subsets, x, y);
        }

    }


    int minimumCost = 0;
    for (i = 0; i < e; ++i) {

        minimumCost += result[i].weight;
    }
    printf("%d", minimumCost);

}




int main() {

    int V ;
    int E;
    scanf("%d",&V);
    scanf("%d",&E);
    struct Graph *graph = createGraph(V, E);
    for (int i = 0; i < E; ++i) {
        int src,dest,weight;
        scanf("%d",&src);
        scanf("%d",&dest);
        scanf("%d",&weight);
        graph->edge[i].src = src;
        graph->edge[i].dest = dest;
        graph->edge[i].weight =weight;


    }


    KruskalMST(graph);

    return 0;
}
