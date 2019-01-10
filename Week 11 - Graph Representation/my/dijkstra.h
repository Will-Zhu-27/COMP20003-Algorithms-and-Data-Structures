/* dijkstra.h */
#ifndef _DIGRAPH_H_
#define _DIGRAPH_H_
#include "digraph.h"
#endif


struct dijkstraQueue {
    char vertex;
    struct weightedEdge *edge;
    int dist;
    struct dijkstraQueue *pred;
};

void dijkstra(struct digraph *graph, char sourceVertex);