/* my dijkstra function for single source directed graph 
    directed graph must be single source.
*/
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include "dijkstra.h"

#ifndef _PRIORITYQUEUE_H_
#define _PRIORITYQUEUE_H_
#include "priorityQueue.h"
#endif

#ifndef _DIGRAPH_H_
#define _DIGRAPH_H_
#include "digraph.h"
#endif

/* prototype */
struct dijkstraQueue;
struct dijkstraQueue *initialize(struct digraph *graph, int sourceIndex);
void dijkstra(struct digraph *graph, int sourceVertex);
void printShortestPathInfo(struct dijkstraQueue *dq, int sourceIndex, int capacity);
int retDijkstraQueueIndex(struct dijkstraQueue *dq, int vertex, int capacity);
void run(struct dijkstraQueue *dq, int capacity);


struct dijkstraQueue {
    int vertex;
    struct weightedEdge *edge;
    int dist;
    struct dijkstraQueue *pred;
};


struct dijkstraQueue *initialize(struct digraph *graph, int sourceIndex) {
    int i;
    struct dijkstraQueue *dq = (struct dijkstraQueue *)malloc(sizeof(struct dijkstraQueue) * graph->capacity);
    for (i = 0; i < graph->capacity; i++) {
        dq[i].vertex = graph->vertex[i];
        dq[i].dist = INT_MAX;
        dq[i].edge = graph->adjacencyList[i];
        dq[i].pred = NULL;
    }
    dq[sourceIndex].dist = 0;
    return dq;
}

void dijkstra(struct digraph *graph, int sourceVertex) {
    struct dijkstraQueue *dq = NULL;
    int sourceIndex;

    if (!hasVertex(graph, sourceVertex)) {
        printf("Vertex %d is not in the graph\n", sourceVertex);
        exit(EXIT_FAILURE);
    }

    sourceIndex = retIndex(graph, sourceVertex);
    dq = initialize(graph, sourceIndex);
    run(dq, graph->capacity);
    printShortestPathInfo(dq, sourceIndex, graph->capacity);
    free(dq);
}

void printShortestPathInfo(struct dijkstraQueue *dq, int sourceIndex, int capacity) {
    int i;
    struct dijkstraQueue *predDijkstra;
    for (i = 0; i < capacity; i++) {
        if (i == sourceIndex) {
            continue;
        }
        if (!dq[i].pred) {
            printf("From vertex %d to %d, no path.\n", dq[sourceIndex].vertex, dq[i].vertex);
            continue;
        }
        printf("From vertex %d to %d, the shorest distance is %d.\n", dq[sourceIndex].vertex, dq[i].vertex, dq[i].dist);
        printf("Path: %d", dq[i].vertex);
        predDijkstra = dq[i].pred;
        while (predDijkstra) {
            printf("<--%d", predDijkstra->vertex);
            predDijkstra = predDijkstra->pred;
        }
        printf("\n\n");
    }
}

int retDijkstraQueueIndex(struct dijkstraQueue *dq, int vertex, int capacity) {
    int i;
    for (i = 0; i < capacity; i++) {
        if (vertex == dq[i].vertex) {
            break;
        }
    }
    return i;
}

void run(struct dijkstraQueue *dq, int capacity) {
    struct priorityQueue *pq = makePriorityQueue();
    struct dijkstraQueue *dSourceVertex = NULL;
    struct dijkstraQueue *dDestVertex = NULL;
    struct weightedEdge *edge = NULL;
    int i;

    for (i = 0; i < capacity; i++) {
        //priorityQueue.c 
        enqueue(pq, &(dq[i]), -dq[i].dist); 
    }
    
    while(!empty(pq)) {
        dSourceVertex = (struct dijkstraQueue *)dequeue(pq);
        edge = dSourceVertex->edge;
        while (edge) {
            dDestVertex = &(dq[retDijkstraQueueIndex(dq, edge->destVertex, capacity)]);
            if (dSourceVertex->dist + edge->weight < dDestVertex->dist) {
                dDestVertex->dist = dSourceVertex->dist + edge->weight;
                dDestVertex->pred = dSourceVertex;
                changePriority(pq, dDestVertex, -dDestVertex->dist);
            }
            edge = edge->next;
        }
    }
    freeQueue(pq);
}