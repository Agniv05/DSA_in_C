/* A graph is a collection of nodes (vertices) and edges (connections between nodes). Graphs can be represented in two common ways:

Adjacency Matrix
Adjacency List
Adjacency Matrix
An adjacency matrix is a 2D array where each element represents the presence or absence of an edge between two vertices. */
#define MAX_VERTICES 5
int adjMatrix[MAX_VERTICES][MAX_VERTICES] = {{0, 1, 0, 0, 1},
                                             {1, 0, 1, 1, 0},
                                             {0, 1, 0, 1, 0},
                                             {0, 1, 1, 0, 1},
                                             {1, 0, 0, 1, 0}};

/* In the adjacency list representation, each vertex has a list of adjacent vertices (those it is connected to). */

struct Node {
    int vertex;
    struct Node* next;
};

struct Graph {
    int numVertices;
    struct Node** adjList;
};

void addEdge(struct Graph* graph, int src, int dest) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->vertex = dest;
    newNode->next = graph->adjList[src];
    graph->adjList[src] = newNode;
}

