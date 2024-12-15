/* #  Depth-First Search (DFS) is an algorithm for traversing or searching through a graph or tree data structure. 
#  Unlike Breadth-First Search (BFS), which explores nodes level by level, DFS dives deep into one branch before 
#  backtracking to explore other branches. DFS can be implemented recursively or iteratively using a stack.

#  Recursive DFS Implementation in Python: */

include <stdio.h>
include <stdlib.h>
include <string.h>
include <stdbool.h>

define MAX_NODES 100

// Graph representation using adjacency list
typedef struct Node {
    int vertex;
    struct Node* next;
} Node;

typedef struct {
    Node* head[MAX_NODES];
    bool visited[MAX_NODES];
} Graph;

// Initialize the graph
void initGraph(Graph* graph, int numNodes) {
    for (int i = 0; i < numNodes; i++) {
        graph->head[i] = NULL;
        graph->visited[i] = false;
    }
}

// Add an edge to the graph
void addEdge(Graph* graph, int src, int dest) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->vertex = dest;
    newNode->next = graph->head[src];
    graph->head[src] = newNode;
}

// Recursive DFS
void dfsRecursive(Graph* graph, int node) {
    graph->visited[node] = true;
    printf("%d ", node);

    Node* temp = graph->head[node];
    while (temp) {
        if (!graph->visited[temp->vertex]) {
            dfsRecursive(graph, temp->vertex);
        }
        temp = temp->next;
    }
}

// Iterative DFS
void dfsIterative(Graph* graph, int startNode, int numNodes) {
    int stack[MAX_NODES];
    int top = -1;
    bool visited[MAX_NODES] = {false};

    stack[++top] = startNode;
    visited[startNode] = true;

    printf("DFS Iterative Traversal Order: ");
    while (top != -1) {
        int node = stack[top--];
        printf("%d ", node);

        Node* temp = graph->head[node];
        while (temp) {
            if (!visited[temp->vertex]) {
                stack[++top] = temp->vertex;
                visited[temp->vertex] = true;
            }
            temp = temp->next;
        }
    }
    printf("\n");
}

// Topological Sort
void topologicalSortUtil(Graph* graph, int node, bool visited[], int* stack, int* stackIndex) {
    visited[node] = true;

    Node* temp = graph->head[node];
    while (temp) {
        if (!visited[temp->vertex]) {
            topologicalSortUtil(graph, temp->vertex, visited, stack, stackIndex);
        }
        temp = temp->next;
    }
    stack[(*stackIndex)++] = node;
}

void topologicalSort(Graph* graph, int numNodes) {
    bool visited[MAX_NODES] = {false};
    int stack[MAX_NODES];
    int stackIndex = 0;

    for (int i = 0; i < numNodes; i++) {
        if (!visited[i]) {
            topologicalSortUtil(graph, i, visited, stack, &stackIndex);
        }
    }

    printf("Topological Sort (DFS): ");
    for (int i = stackIndex - 1; i >= 0; i--) {
        printf("%d ", stack[i]);
    }
    printf("\n");
}

int main() {
    // Example for DFS
    Graph graph;
    int numNodes = 6; // Nodes: A (0), B (1), C (2), D (3), E (4), F (5)
    initGraph(&graph, numNodes);

    addEdge(&graph, 0, 1); // A -> B
    addEdge(&graph, 0, 2); // A -> C
    addEdge(&graph, 1, 3); // B -> D
    addEdge(&graph, 1, 4); // B -> E
    addEdge(&graph, 2, 5); // C -> F
    addEdge(&graph, 4, 5); // E -> F

    printf("DFS Recursive Traversal Order: ");
    dfsRecursive(&graph, 0);
    printf("\n");

    dfsIterative(&graph, 0, numNodes);

    // Example for Topological Sort
    Graph dag;
    int numDAGNodes = 8; // Nodes: A (0), B (1), ..., H (7)
    initGraph(&dag, numDAGNodes);

    addEdge(&dag, 0, 2); // A -> C
    addEdge(&dag, 1, 2); // B -> C
    addEdge(&dag, 1, 3); // B -> D
    addEdge(&dag, 2, 4); // C -> E
    addEdge(&dag, 3, 5); // D -> F
    addEdge(&dag, 4, 7); // E -> H
    addEdge(&dag, 4, 5); // E -> F
    addEdge(&dag, 5, 6); // F -> G

    topologicalSort(&dag, numDAGNodes);

    return 0;
}
