#include <stdio.h>
#include <stdlib.h>

#ifndef _DIGRAPH_H_
#define _DIGRAPH_H_
#include "digraph.h"
#endif

#include "dijkstra.h"

int main(int argc, char **argv) {
    struct digraph *graph = newDigraph();
    int i;

    addEdge(graph, 1, 2, 200);
    addEdge(graph, 1, 3, 100);
    addEdge(graph, 1, 4, 500);
    addEdge(graph, 2, 3, 150);
    addEdge(graph, 2, 4, 300);
    addEdge(graph, 4, 5, 100);

    for (i = 0; i < graph->capacity; i++) {
        printEdge(graph, graph->vertex[i]);
    }

    dijkstra(graph, graph->vertex[0]);
    return 0;
}