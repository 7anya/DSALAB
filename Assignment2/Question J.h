
#include <stdio.h>
#include <stdlib.h>

int visited[500], queue[100], qsize = 0, qlast = 0;


struct node {
    int vertex;
    struct node *next;
};

struct node *createNode(int);

struct Graph {
    int numVertices;
    struct node **adjLists;
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

        struct node *temp = graph->adjLists[currentVertex];

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

// Creating a node
struct node *createNode(int v) {
    struct node *newNode = malloc(sizeof(struct node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

// Creating a graph
struct Graph *createGraph(int vertices) {
    struct Graph *graph = malloc(sizeof(struct Graph));
    graph->numVertices = vertices;
    graph->adjLists = malloc(vertices * sizeof(struct node *));
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
    struct node *newNode = createNode(dest);
    newNode->next = graph->adjLists[src];
    graph->adjLists[src] = newNode;
    newNode = createNode(src);
    newNode->next = graph->adjLists[dest];
    graph->adjLists[dest] = newNode;
}


void solveJ() {
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