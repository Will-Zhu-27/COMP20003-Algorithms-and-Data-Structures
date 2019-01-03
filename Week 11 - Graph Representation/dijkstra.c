/* dijkstra.c */
#include "digraph.h"
#include "dijkstra.h"
#include <stdlib.h>
#include <stdio.h>
#include "pqueue.h"
/* NOTE: If you didn't write pqueue.h & pqueue.c last week, consider doing
    so before this exercise. */
struct dijkQsturct;

struct dijkQstruct {
	int id;
	int *shortestDist;
	int positionInHeap;
};

int updatedijkQstruct(void *dataOrig) {
	struct dijkQstruct *data = (struct dijkQstruct *) dataOrig;
	return *(data->shortestDist);
}
struct dijkstraRes *dijkstra(struct digraph *graph, int source){
    /* FILL IN HERE */  
    struct pqueue *pq = makeQueue();
	
	int *shortestDists = NULL;
	int *ids = NULL;
	int *visited = NULL;
	int *inQueue = NULL;
	int *preds = NULL;
	
	int i;
	int nodes = 0;   
	struct dijkstraRes *res;
	struct dijkQstruct *queueItems;
	struct dijkQstruct *current;
	struct weightedEdge *edgeList;
	struct weightedEdge *nextEdge;
	
	res = (struct dijkstraRes *)malloc(sizeof(struct dijkstraRes));
	assert(res);
	
	ids = getNodes(graph, &nodes);
	
	visited = (int *)malloc(sizeof(int) * nodes);
	assert(visited);
	shortestDists = (int *)malloc(sizeof(int) * nodes);
	assert(shortestDists);
	preds = (int *) malloc(sizeof(int) * nodes);
	assert(preds);
	queueItems = (struct dijkQstruct *) malloc(sizeof(struct dijkQstruct) * nodes);
	assert(queueItems);
	inQueue = (int *) malloc(sizeof(int) * nodes);
	assert(inQueue);
}

void printDijkstra(struct dijkstraRes *res){
    int i;
    printf("Shortest paths from %d\n", res->indices[res->sourceNode]);
    for(i = 0; i < res->nodeCount; i++){
        if ((res->shortestPaths[i]) == NOPATH){
            printf("to %d: NO PATH;\n", res->indices[i]);
        } else {
            printf("to %d: %d;\n", res->indices[i], res->shortestPaths[i]);
        }
    }
}

void freeDijkstraRes(struct dijkstraRes *res){
    if(! res){
        return;
    }
    if(res->shortestPaths){
        free(res->shortestPaths);
    }
    if(res->indices){
        free(res->indices);
    }
    free(res);
}

