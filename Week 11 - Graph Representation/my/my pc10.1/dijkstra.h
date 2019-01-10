/* dijkstra.h */
#ifndef _DIGRAPH_H_
#define _DIGRAPH_H_
#include "digraph.h"
#endif

struct dijkstraQueue {
    int vertex;
    struct weightedEdge *edge;
    int dist;
    struct dijkstraQueue *pred;
};

struct dijkstraQueue *dijkstra(struct digraph *graph, int sourceVertex);