#include <stdio.h>
#include <stdlib.h>
#include "helperFunc.h"

#define INFINITY 1000000 

typedef struct {
    int parent[100];
    int rank[100];
} UnionFind;

void initUnionFind(UnionFind* uf, int vertices) {
    for (int i = 0; i < vertices; i++) {
        uf->parent[i] = i;
        uf->rank[i] = 0;
    }
}

int find(UnionFind* uf, int vertex) {
    if (uf->parent[vertex] != vertex) {
        uf->parent[vertex] = find(uf, uf->parent[vertex]);
    }
    return uf->parent[vertex];
}

void unionSets(UnionFind* uf, int u, int v) {
    int rootU = find(uf, u);
    int rootV = find(uf, v);

    if (rootU != rootV) {
        if (uf->rank[rootU] > uf->rank[rootV]) {
            uf->parent[rootV] = rootU;
        } else if (uf->rank[rootU] < uf->rank[rootV]) {
            uf->parent[rootU] = rootV;
        } else {
            uf->parent[rootV] = rootU;
            uf->rank[rootU]++;
        }
    }
}

void kruskalMST(Graph* g, Edge* mstEdges, int* mstEdgeCount) {
    UnionFind uf;
    initUnionFind(&uf, g->numVertices);

    Edge* edges[1000];
    int edgeCount = 0;

    // Gather all edges into an array
    for (int i = 0; i < g->numVertices; i++) {
        Edge* edge = g->head[i];
        while (edge != NULL) {
            if (edge->from < edge->to) {  // Avoid duplicating undirected edges
                edges[edgeCount++] = edge;
            }
            edge = edge->next;
        }
    }

    // Sort edges by weight bubble sort just easy for simple 
    for (int i = 0; i < edgeCount - 1; i++) {
        for (int j = i + 1; j < edgeCount; j++) {
            if (edges[i]->weight > edges[j]->weight) {
                Edge* temp = edges[i];
                edges[i] = edges[j];
                edges[j] = temp;
            }
        }
    }

    // Process edges in sorted order
    for (int i = 0; i < edgeCount; i++) {
        int u = edges[i]->from;
        int v = edges[i]->to;

        if (find(&uf, u) != find(&uf, v)) {
            unionSets(&uf, u, v);
            mstEdges[*mstEdgeCount] = *edges[i];  // Store the edge
            (*mstEdgeCount)++;
        }
    }
}

// Prim's Algorithm to find MST
void primMST(Graph* g, int startVertex, Edge* mstEdges, int* mstEdgeCount) {
    int visited[100] = { 0 };  // equivalent to 'false'
    int minWeight[100];
    int parent[100];
    for (int i = 0; i < g->numVertices; i++) {
        minWeight[i] = INFINITY;
        parent[i] = -1;
    }
    minWeight[startVertex] = 0;

    for (int i = 0; i < g->numVertices; i++) {
        int minVertex = -1;
        for (int j = 0; j < g->numVertices; j++) {
            if (visited[j] == 0 && (minVertex == -1 || minWeight[j] < minWeight[minVertex])) {
                minVertex = j;
            }
        }

        if (minWeight[minVertex] == INFINITY) break;  // No more reachable vertices

        visited[minVertex] = 1;  // equivalent to 'true'

        if (parent[minVertex] != -1) {
            // Record the edge between parent[minVertex] and minVertex
            mstEdges[*mstEdgeCount].from = parent[minVertex];
            mstEdges[*mstEdgeCount].to = minVertex;
            mstEdges[*mstEdgeCount].weight = minWeight[minVertex];
            (*mstEdgeCount)++;
        }

        Edge* edge = g->head[minVertex];
        while (edge != NULL) {
            if (visited[edge->to] == 0 && edge->weight < minWeight[edge->to]) {
                minWeight[edge->to] = edge->weight;
                parent[edge->to] = minVertex;
            }
            edge = edge->next;
        }
    }
}

// Function to compare the order of edges added to MST by Prim's and Kruskal's algorithm
void compareMSTEdgeOrders(Graph* g) {
    Edge primEdges[100], kruskalEdges[100];
    int primEdgeCount = 0, kruskalEdgeCount = 0;

    // Compare Prim's MST
    primMST(g, 0, primEdges, &primEdgeCount);
    printf("Prim's Algorithm Edge Order:\n");
    for (int i = 0; i < primEdgeCount; i++) {
        printf("Edge from %d to %d with weight %d\n", primEdges[i].from, primEdges[i].to, primEdges[i].weight);
    }

    // Compare Kruskal's MST
    kruskalMST(g, kruskalEdges, &kruskalEdgeCount);
    printf("Kruskal's Algorithm Edge Order:\n");
    for (int i = 0; i < primEdgeCount; i++) {
        printf("Edge from %d to %d with weight %d\n", kruskalEdges[i].from, kruskalEdges[i].to, kruskalEdges[i].weight);
    }
}

int main() {
   
    Graph g;
    initGraph(&g,5);
    g.numVertices = 5;

   
    addEdge(&g, 0, 1, 1);
    addEdge(&g, 0, 2, 2);
    addEdge(&g, 1, 2, 3);
    addEdge(&g, 1, 3, 4);
    addEdge(&g, 2, 3, 5);
    addEdge(&g, 2, 4, 6);
    addEdge(&g, 3, 4, 7);

    compareMSTEdgeOrders(&g);

    return 0;
}

