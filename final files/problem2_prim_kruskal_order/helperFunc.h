#include <stdio.h>
#include <stdlib.h>

typedef struct Edge {
    int from;
    int to;
    int weight;
    struct Edge* next;
} Edge;

typedef struct {
    Edge * head[100]; // array of edges formt he lead vertice
    int numVertices;
} Graph;

Edge * createEdge(int from, int to, int weight) {
    Edge * newEdge = (Edge *)malloc(sizeof(Edge));
    newEdge->from = from;
    newEdge->to = to;
    newEdge->weight = weight;
    newEdge->next = NULL;
    return newEdge;
}

void addEdge(Graph* g, int from, int to, int weight) {
    Edge * edge = createEdge(from, to, weight);
    edge->next = g->head[from];
    g->head[from] = edge;
}

void addUndirectedEdge(Graph* g, int u, int v, int weight) {
    addEdge(g, u, v, weight);
    addEdge(g, v, u, weight);

    // both ways need to be implimented because there is no definitve direction they can be found in
}

void initGraph(Graph* g, int vertices) {
    g->numVertices = vertices;
    for (int i = 0; i < 100; i++) { // 100 is the max number of vertices
        g->head[i] = NULL;
    }
}

void updateMST(Graph* mst, int newVertex, int incidentEdges[][2], int numEdges) {
    int minWeight = 1000000; // simulated infinity cause C is basic
    int minTo = -1;

    // Find the edge with the smallest weight connecting newVertex to the MST
    for (int i = 0; i < numEdges; i++) {
        int to = incidentEdges[i][0];
        int weight = incidentEdges[i][1];

        if (to < mst->numVertices && weight < minWeight) {
            minWeight = weight;
            minTo = to;
        }
    }

    if (minTo != -1) {
       
        addUndirectedEdge(mst, newVertex, minTo, minWeight);
        mst->numVertices += 1;
        printf("Added edge\n");
    } else {
        
        mst->numVertices += 1;
        printf("Vertex is isolated and cannot be added to the MST.\n");
    }
}

void printGraph(Graph* g) {
    for (int i = 0; i < g->numVertices; i++) {
        printf("%d: ", i);
        Edge * temp = g->head[i];
        while (temp) {
            printf("-> (%d, %d) ", temp->to, temp->weight);
            temp = temp->next;
        }
        printf("\n");
    }
}