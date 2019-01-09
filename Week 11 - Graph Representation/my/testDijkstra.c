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
    /*
    addEdge(graph, 'A', 'B', 5);
    addEdge(graph, 'A', 'C', 4);
    addEdge(graph, 'A', 'D', 8);
    addEdge(graph, 'B', 'F', 6);
    addEdge(graph, 'C', 'B', 5);
    addEdge(graph, 'C', 'E', 3);
    addEdge(graph, 'D', 'G', 7);
    addEdge(graph, 'E', 'G', 5);
    addEdge(graph, 'F', 'E', 2);
    addEdge(graph, 'F', 'H', 6);
    addEdge(graph, 'G', 'F', 4);
    addEdge(graph, 'G', 'H', 5);
    */
    addEdge(graph, 'A', 'B', 10);
    addEdge(graph, 'A', 'D', 5);
    addEdge(graph, 'B', 'C', 40);
    addEdge(graph, 'C', 'F', 20);
    addEdge(graph, 'D', 'E', 5);
    addEdge(graph, 'E', 'C', 10);
    //addEdge(graph, 'G', 'H', 6);
    for (i = 0; i < graph->capacity; i++) {
        printEdge(graph, graph->vertex[i]);
    }

    dijkstra(graph, graph->vertex[0]);
    /*for (i = 0; i < graph->capacity; i++) {
        printEdge(graph, graph->vertex[i]);
    }*/
    freeDigraph(graph);
    return 0;
}