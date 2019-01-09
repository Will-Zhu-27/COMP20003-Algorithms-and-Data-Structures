/* my dijkstra function */
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include "dijkstra.h"

#ifndef _DIGRAPH_H_
#define _DIGRAPH_H_
#include "digraph.h"
#endif

struct dijkstraQueue {
    int vertex;
    struct weightedEdge *edge;
    int dist;
    int *pred;
}


struct dijkstraQueue *initialize(struct digraph *graph, int sourceIndex) {
    int i;
    struct dijkstraQueue *dq = (struct dijkstraQueue *)malloc(sizeof(struct dijkstraQueue) * graph->capacity);
    for (i = 0; i < graph->capacity; i++) {
        dq[i].vertex = graph->vertex[i];
        dq[i].dist = MAX_INT;
        dq[i].edge = graph->adjacencyList[i];
        dq[i].pred = NULL;
    }
    dq[sourceIndex].dist = 0;
    return dq;
}

void dijkstra(struct digraph *graph, int sourceVertex) {
    struct dijkstraQueue *dq = NULL;
    int sourceIndex;
    int i;

    if (!hasVertex(graph, sourceVertex)) {
        printf("Vertex %d is not in the graph\n", sourceVertex);
        return;
    }

    sourceIndex = retIndex(graph, sourceVertex);
    dq = initialize(graph, sourceIndex);
    run(dq, graph->capacity);
}

void run(struct dijkstraQueue *dq, int capacity) {
    struct priorityQueue *pq = makePriorityQueue();
    struct dijkstraQueue *dSourceVertex = NULL;
    struct dijkstraQueue *dDestVertex = NULL;
    struct weightedEdge *edge = NULL;
    int i;

    for (i = 0; i < capacity; i++) {
        enqueue(pq, &(dq[i]), dq[i].dist);
    }
    
    while(!empty(pq)) {
        dSourceVertex = (struct dijkstraQueue *)dequeue(pq);
        edge = dSourceVertex->edge;
        dDestVertex = &(dq[retIndex(edge->destVertex)]);
        while (edge) {
            if (dSourceVertex->dist + edge->weight < dDestVertex->dist) {
                dDestVertex->dist = dSourceVertex->dist + edge->weight;
                *(dDestVertex->pred) = dSourceVertex->vertex;
                /*not finish*/
                update(pq);
            }
        }
    }
}