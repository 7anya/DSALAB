
#include <stdio.h>
#include <stdlib.h>
#define SIZE 100

struct queue {
    int items[SIZE];
    int front;
    int rear;
};

struct queue* createQueue();
void enqueue(struct queue* q, int);
int dequeue(struct queue* q);
void display(struct queue* q);
int isEmpty(struct queue* q);
void printQueue(struct queue* q);

struct node {
    int vertex;
    struct node* next;
};

struct node* createNode(int);

struct Graph {
    int numVertices;
    struct node** adjLists;
    int* visited;
};

// BFS algorithm
void bfs(struct Graph* graph, int startVertex,int endVertex) {
    struct queue* q = createQueue();

    graph->visited[startVertex] = 1;
    enqueue(q, startVertex);
    int distance[1000];
    distance[startVertex]=0;
    while (!isEmpty(q)) {
//        printQueue(q);
        int currentVertex = dequeue(q);
//        printf("Visited %d\n", currentVertex);

        struct node* temp = graph->adjLists[currentVertex];

        while (temp) {
            int adjVertex = temp->vertex;

            if (graph->visited[adjVertex] == 0) {
                distance[adjVertex]=distance[currentVertex]+1;
                graph->visited[adjVertex] = 1;
                enqueue(q, adjVertex);

            }
            temp = temp->next;
        }
    }
    printf("%d",distance[endVertex]*100);
}

// Creating a node
struct node* createNode(int v) {
    struct node* newNode = malloc(sizeof(struct node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

// Creating a graph
struct Graph* createGraph(int vertices) {
    struct Graph* graph = malloc(sizeof(struct Graph));
    graph->numVertices = vertices;

    graph->adjLists = malloc(vertices * sizeof(struct node*));
    graph->visited = malloc(vertices * sizeof(int));

    int i;
    for (i = 0; i < vertices; i++) {
        graph->adjLists[i] = NULL;
        graph->visited[i] = 0;
    }

    return graph;
}

// Add edge
void addEdge(struct Graph* graph, int src, int dest) {
    // Add edge from src to dest
    struct node* newNode = createNode(dest);
    newNode->next = graph->adjLists[src];
    graph->adjLists[src] = newNode;

    // Add edge from dest to src
    newNode = createNode(src);
    newNode->next = graph->adjLists[dest];
    graph->adjLists[dest] = newNode;
}

// Create a queue
struct queue* createQueue() {
    struct queue* q = malloc(sizeof(struct queue));
    q->front = -1;
    q->rear = -1;
    return q;
}

// Check if the queue is empty
int isEmpty(struct queue* q) {
    if (q->rear == -1)
        return 1;
    else
        return 0;
}

// Adding elements into queue
void enqueue(struct queue* q, int value) {
    if (q->rear == SIZE - 1)
//        printf("\nQueue is Full!!");
    ;
    else {
        if (q->front == -1)
            q->front = 0;
        q->rear++;
        q->items[q->rear] = value;
    }
}

// Removing elements from queue
int dequeue(struct queue* q) {
    int item;
    if (isEmpty(q)) {
//        printf("Queue is empty");
        item = -1;
    } else {
        item = q->items[q->front];
        q->front++;
        if (q->front > q->rear) {
//            printf("Resetting queue ");
            q->front = q->rear = -1;
        }
    }
    return item;
}

//// Print the queue
//void printQueue(struct queue* q) {
//    int i = q->front;
//
//    if (isEmpty(q)) {
////        printf("Queue is empty");
//    } else {
////        printf("\nQueue contains \n");
//        for (i = q->front; i < q->rear + 1; i++) {
//            printf("%d ", q->items[i]);
//        }
//    }
//}

void solveJ() {
    int n,m,t,s;
    scanf("%d",&n);
    scanf("%d",&m);
    scanf("%d",&t);
    scanf("%d",&s);
    struct Graph* graph = createGraph(n);
    for (int i = 0; i < m; ++i) {
        int x,y;
        scanf("%d",&x);
        scanf("%d",&y);
        addEdge(graph, x, y);
    }


    bfs(graph, t,s);


}