//
// Created by tokoyama on 21/04/21.
//

#ifndef DSALAB_GRAPH_H
#define DSALAB_GRAPH_H

#endif //DSALAB_GRAPH_H
#include <stdio.h>
#include <malloc.h>

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

void BFS(int a[120][120], int start) {

    queue[qlast++] = start;
    qsize++;

    visited[start] = 1;

    int vis, first = 0;
    while (qsize != 0) {
        vis = queue[first];

        printf("%d ", vis);

        first++;
        qsize--;

        for (int i = 0; i < 12; i++) {
            if (a[vis][i] == 1 && visited[i] == 0) {


                queue[qlast++] = i;
                qsize++;

                visited[i] = 1;
            }
        }
    }
}
void use() {


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

struct Node {
    int vertex;
    struct Node *next;
};

struct Node *createNode(int);

struct Graph {
    int numVertices;
    struct Node **adjLists;
    int *visited;
};

// BFS algorithm
void bfs(struct Graph *graph, int startVertex, int endVertex) {

    graph->visited[startVertex] = 1;
    queue[qlast++] = startVertex;
    qsize++;
    int distance[1000], first = 0;
    distance[startVertex] = 0;
    while (qsize != 0) {
        int currentVertex = queue[first];
        first++;
        qsize--;

        struct Node *temp = graph->adjLists[currentVertex];

        while (temp) {
            int adjVertex = temp->vertex;

            if (graph->visited[adjVertex] == 0) {
                distance[adjVertex] = distance[currentVertex] + 1;
                graph->visited[adjVertex] = 1;
                queue[qlast++] = adjVertex;
                qsize++;

            }
            temp = temp->next;
        }
    }
    printf("%d", distance[endVertex] * 100);
}

// Creating a Node
struct Node *createNode(int v) {
    struct Node *newNode = malloc(sizeof(struct Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

// Creating a graph
struct Graph *createGraph(int vertices) {
    struct Graph *graph = malloc(sizeof(struct Graph));
    graph->numVertices = vertices;
    graph->adjLists = malloc(vertices * sizeof(struct Node *));
    graph->visited = malloc(vertices * sizeof(int));
    int i;
    for (i = 0; i < vertices; i++) {
        graph->adjLists[i] = NULL;
        graph->visited[i] = 0;
    }

    return graph;
}

// Add edge
void addEdge(struct Graph *graph, int src, int dest) {
    struct Node *newNode = createNode(dest);
    newNode->next = graph->adjLists[src];
    graph->adjLists[src] = newNode;
    newNode = createNode(src);
    newNode->next = graph->adjLists[dest];
    graph->adjLists[dest] = newNode;
}


void usingAdjacentcylists() {
    int n, m, t, s;
    scanf("%d", &n);
    scanf("%d", &m);
    scanf("%d", &t);
    scanf("%d", &s);
    struct Graph *graph = createGraph(n);
    for (int i = 0; i < m; ++i) {
        int x, y;
        scanf("%d", &x);
        scanf("%d", &y);
        addEdge(graph, x, y);
    }


    bfs(graph, t, s);


}