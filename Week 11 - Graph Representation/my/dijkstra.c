/*  my dijkstra function for finding shortest path from one vertex
    in directed graph, no matter single source or multi cource.
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
void dijkstra(struct digraph *graph, char sourceVertex);
void printShortestPathInfo(struct dijkstraQueue *dq, int sourceIndex, int capacity);
int retDijkstraQueueIndex(struct dijkstraQueue *dq, char vertex, int capacity);
void run(struct dijkstraQueue *dq, int capacity);

struct dijkstraQueue {
    char vertex;
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

void dijkstra(struct digraph *graph, char sourceVertex) {
    struct dijkstraQueue *dq = NULL;
    int sourceIndex;

    if (!hasVertex(graph, sourceVertex)) {
        printf("Vertex %c is not in the graph\n", sourceVertex);
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
        if (!dq[i].pred || dq[i].dist == INT_MAX) {
            printf("From vertex %c to %c, no path.\n", dq[sourceIndex].vertex, dq[i].vertex);
            continue;
        }
        printf("From vertex %c to %c, the shorest distance is %d.\n", dq[sourceIndex].vertex, dq[i].vertex, dq[i].dist);
        printf("Path: %c", dq[i].vertex);
        predDijkstra = dq[i].pred;
        while (predDijkstra) {
            printf("<--%c", predDijkstra->vertex);
            predDijkstra = predDijkstra->pred;
        }
        printf("\n\n");
    }
}

int retDijkstraQueueIndex(struct dijkstraQueue *dq, char vertex, int capacity) {
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
            if (dSourceVertex->dist != INT_MAX && dSourceVertex->dist + edge->weight < dDestVertex->dist) {
                dDestVertex->dist = dSourceVertex->dist + edge->weight;
                dDestVertex->pred = dSourceVertex;
                if(!changePriority(pq, dDestVertex, -dDestVertex->dist)) {
                    printf("from %c to %c, update priority failure\n\n\n", dSourceVertex->vertex, dDestVertex->vertex);
                }
            }
            edge = edge->next;
        }
    }
    freeQueue(pq);
}