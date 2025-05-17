#include <stdio.h>
#include "helperFunc.h"

// this would need to be adjusted to fit however the graphs edges are stuctured
// this problem is based off of problem 1

int isEdgeInMST(int u, int v, Graph* g) {
    if (u >= g->numVertices || v >= g->numVertices || u < 0 || v < 0){
        printf("\nEdge (%d,%d) not found\n",u,v);
        return 0;
    }
    Edge * current = g->head[u];
    while (current != NULL) {
        if (current->to == v) {
            printf("\nEdge (%d,%d) found\n",u,v);
            return 1; // Edge (u, v) found in MST
        }
        current = current->next;
    }
    printf("\nEdge (%d,%d) not found\n",u,v);
    return 0; // Edge not found
}

int main() {

    Graph mst;
    initGraph(&mst, 5);

    addUndirectedEdge(&mst, 0, 1, 10);
    addUndirectedEdge(&mst, 1, 2, 5);
    addUndirectedEdge(&mst, 2, 3, 7);
    addEdge(&mst, 4,2,2);

    printf("MST:\n");
    printGraph(&mst);

    isEdgeInMST(0,3,&mst);
    isEdgeInMST(4,2,&mst);

    // Check if a given edge is in the MST
    // TODO: Implement this problem's solution
    return 0;
}
