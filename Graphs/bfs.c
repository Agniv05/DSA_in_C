/*#  In Breadth-First Search, we start with a node (not necessarily the smallest or the largest)
#  and start exploring its connected nodes. The same process is repeated with all the connecting 
#  nodes until all the nodes are visited. We should first learn the concept of the BFS spanning 
#  tree in order to understand the Breadth-First Search in a very intuitive way.*/

include <stdio.h>
include <stdlib.h>
include <string.h>

define MAX_NODES 100

// Queue structure to manage nodes to visit
typedef struct {
    int items[MAX_NODES];
    int front;
    int rear;
} Queue;

// Initialize the queue
void initQueue(Queue* q) {
    q->front = -1;
    q->rear = -1;
}

// Check if the queue is empty
int isEmpty(Queue* q) {
    return q->front == -1;
}

// Enqueue an element
void enqueue(Queue* q, int value) {
    if (q->rear == MAX_NODES - 1) {
        printf("Queue Overflow\n");
        return;
    }
    if (q->front == -1) q->front = 0;
    q->rear++;
    q->items[q->rear] = value;
}

// Dequeue an element
int dequeue(Queue* q) {
    if (isEmpty(q)) {
        printf("Queue Underflow\n");
        return -1;
    }
    int value = q->items[q->front];
    if (q->front == q->rear) {
        q->front = q->rear = -1;
    } else {
        q->front++;
    }
    return value;
}

// Breadth-First Search (Iterative)
void bfs(int graph[MAX_NODES][MAX_NODES], int startNode, int numNodes) {
    // Array to track visited nodes
    int visited[MAX_NODES] = {0};

    // Queue for BFS
    Queue q;
    initQueue(&q);

    // Start BFS from the startNode
    enqueue(&q, startNode);
    visited[startNode] = 1;

    printf("BFS Traversal Order: ");

    while (!isEmpty(&q)) {
        // Dequeue a node from the queue
        int currentNode = dequeue(&q);
        printf("%d ", currentNode);

        // Visit all the neighbors of the current node
        for (int i = 0; i < numNodes; i++) {
            if (graph[currentNode][i] == 1 && !visited[i]) {
                visited[i] = 1;
                enqueue(&q, i);
            }
        }
    }
    printf("\n");
}

// Recursive BFS
void recursiveBFS(int graph[MAX_NODES][MAX_NODES], Queue* q, int visited[MAX_NODES], int numNodes) {
    // Base case: If the queue is empty, end recursion
    if (isEmpty(q)) {
        return;
    }

    // Dequeue a node from the queue
    int currentNode = dequeue(q);
    printf("%d ", currentNode);

    // Visit all the neighbors of the current node
    for (int i = 0; i < numNodes; i++) {
        if (graph[currentNode][i] == 1 && !visited[i]) {
            visited[i] = 1;
            enqueue(q, i);
        }
    }

    // Recursive call with updated queue
    recursiveBFS(graph, q, visited, numNodes);
}

// Wrapper function for recursive BFS
void bfsRecursive(int graph[MAX_NODES][MAX_NODES], int startNode, int numNodes) {
    // Array to track visited nodes
    int visited[MAX_NODES] = {0};

    // Queue for BFS
    Queue q;
    initQueue(&q);

    // Start BFS from the startNode
    enqueue(&q, startNode);
    visited[startNode] = 1;

    printf("Recursive BFS Traversal Order: ");
    recursiveBFS(graph, &q, visited, numNodes);
    printf("\n");
}

int main() {
    // Adjacency matrix representation of the graph
    // Example graph:
    // A: 0, B: 1, C: 2, D: 3, E: 4, F: 5
    int graph[MAX_NODES][MAX_NODES] = {
        {0, 1, 1, 0, 0, 0},
        {1, 0, 0, 1, 1, 0},
        {1, 0, 0, 0, 0, 1},
        {0, 1, 0, 0, 0, 0},
        {0, 1, 0, 0, 0, 1},
        {0, 0, 1, 0, 1, 0}
    };

    int numNodes = 6; // Number of nodes in the graph
    int startNode = 0; // Start BFS from node A (0)

    bfs(graph, startNode, numNodes);
    bfsRecursive(graph, startNode, numNodes);

    return 0;
}
