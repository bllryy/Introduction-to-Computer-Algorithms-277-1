#include <stdio.h>
#include <stdlib.h>

struct node {
    int vertex;
    struct node *next;
};

struct graph {
    int numVertices;
    struct node **adjLists;
    int *visited;
};

// proto
struct node* createNode(int v);
struct graph* createGraph(int vertices);
void addEdge(struct graph *graph, int src, int dest);
void printGraph(struct graph *graph);
int isEmpty(struct node *queue);
void enqueue(struct node **queue, int value);
int dequeue(struct node **queue);
void printQueue(struct node *queue);
void bfs(struct graph *graph, int startVertex);

struct node* createNode(int v) {
    struct node *newNode = malloc(sizeof(struct node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

struct graph* createGraph(int vertices) {
    struct graph *graph = malloc(sizeof(struct graph));
    graph->numVertices = vertices;
    graph->adjLists = malloc(vertices * sizeof(struct node*));
    graph->visited = malloc(vertices * sizeof(int));

    for (int i = 0; i < vertices; i++) {
        graph->adjLists[i] = NULL;
        graph->visited[i] = 0;
    }
    return graph;
}

// Adds an undirected edge
void addEdge(struct graph *graph, int src, int dest) {
    struct node *newNode = createNode(dest);
    newNode->next = graph->adjLists[src];
    graph->adjLists[src] = newNode;

    newNode = createNode(src);
    newNode->next = graph->adjLists[dest];
    graph->adjLists[dest] = newNode;
}

void printGraph(struct graph *graph) {
    for (int v = 0; v < graph->numVertices; v++) {
        struct node *temp = graph->adjLists[v];
        printf("Adj list of vertex %d: ", v);
        while (temp) {
            printf("%d -> ", temp->vertex);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}

int isEmpty(struct node *queue) {
    return queue == NULL;
}

void enqueue(struct node **queue, int value) {
    struct node *newNode = createNode(value);
    if (isEmpty(*queue)) {
        *queue = newNode;
    } else {
        struct node *temp = *queue;
        while (temp->next) {        // go to the last node
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

int dequeue(struct node **queue) {
    if (isEmpty(*queue)) {
        printf("Queue underflow\n");
        return -1;
    }
    struct node *temp = *queue;
    int value = temp->vertex;
    *queue = (*queue)->next;
    free(temp);
    return value;
}

void printQueue(struct node *queue) {
    printf("Queue: ");
    while (queue) {
        printf("%d ", queue->vertex);
        queue = queue->next;
    }
    printf("\n");
}

void bfs(struct graph *graph, int startVertex) {
    struct node *queue = NULL;

    graph->visited[startVertex] = 1;
    enqueue(&queue, startVertex);

    while (!isEmpty(queue)) {
        printQueue(queue);
        int currentVertex = dequeue(&queue);
        printf("Visited %d\n", currentVertex);

        struct node *temp = graph->adjLists[currentVertex];
        while (temp) {
            int adjVertex = temp->vertex;
            if (graph->visited[adjVertex] == 0) {   // only one check needed
                graph->visited[adjVertex] = 1;
                enqueue(&queue, adjVertex);
            }
            temp = temp->next;
        }
    }
}

int main() {
    int vertices = 4;
    int startVertex = 0;                // added missing semicolon

    struct graph *graph = createGraph(vertices);

    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 2);
    addEdge(graph, 2, 3);

    printGraph(graph);
    printf("\nBFS starting from vertex %d:\n", startVertex);
    bfs(graph, startVertex);

    return 0;
}