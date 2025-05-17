#include <stdio.h>
#include <stdlib.h>

// Edge structure
typedef struct {
    int u, v;
    int weight;
} Edge;

// Find function for Union-Find
int find(int parent[], int u) {
    while (parent[u] != u) {
        parent[u] = parent[parent[u]];
        u = parent[u];
    }
    return u;
}

// Union function for Union-Find
int union_sets(int parent[], int u, int v) {
    int root_u = find(parent, u);
    int root_v = find(parent, v);
    if (root_u != root_v) {
        parent[root_v] = root_u;
        return 1;
    }
    return 0;
}

// Compare function for qsort
int compare(const void* a, const void* b) {
    Edge* ea = (Edge*)a;
    Edge* eb = (Edge*)b;
    return ea->weight - eb->weight;
}

// Bottleneck Spanning Tree function
int bottleneckSpanningTree(int n, Edge edges[], int edge_count, Edge result[]) {
    int i, count = 0;

    // Sort edges by weight
    qsort(edges, edge_count, sizeof(Edge), compare);

    // Initialize Union-Find
    int* parent = malloc(n * sizeof(int));
    for (i = 0; i < n; i++) {
        parent[i] = i;
    }

    for (i = 0; i < edge_count && count < n - 1; i++) {
        if (union_sets(parent, edges[i].u, edges[i].v)) {
            result[count++] = edges[i];
        }
    }

    free(parent);

    // If the graph is disconnected
    if (count != n - 1) {
        return 0;
    }

    return count;
}


int main() {

    int n = 4; // number of nodes
    Edge edges[] = {
        {0, 1, 4},
        {0, 2, 3},
        {1, 2, 2},
        {1, 3, 5},
        {2, 3, 7}
    };

    int edge_count = sizeof(edges) / sizeof(edges[0]);
    Edge result[10]; // To store the result BST edges

    int bst_size = bottleneckSpanningTree(n, edges, edge_count, result);

    if (bst_size == 0) {
        printf("Graph is disconnected.\n");
    } else {
        printf("Bottleneck Spanning Tree edges:\n");
        for (int i = 0; i < bst_size; i++) {
            printf("%d - %d (weight %d)\n", result[i].u, result[i].v, result[i].weight);
        }
    }




    
    // Compute Bottleneck Spanning Tree
    // Problem 5: Implement a function that takes a graph and computes the bottleneck spanning tree (BST) of the graph.
    // The graph is represented as an adjacency list, and the function should return the edges of the BST.
    // The function should also handle the case where the graph is not connected.
    // The function should also handle the case where the graph is a complete graph.
    // The function should also handle the case where the graph is a tree.
    // TODO: Implement this problem's solution
    return 0;
}
