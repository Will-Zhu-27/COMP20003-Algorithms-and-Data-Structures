/* dijkstra.c */
#ifndef _DIGRAPH_H_
#define _DIGRAPH_H_
#include "digraph.h"
#endif
#include "dijkstra.h"
#include <stdlib.h>
#include <stdio.h>
#include "pqueue.h"
#include <assert.h>

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
	
	for (i = 0; i < nodes; i++) {
		visited[i] = 0;
		shortestDists[i] = NOPATH;
		(queueItems[i]).id = i;
		(queueItems[i]).shortestDist = &(shortestDists[i]);
		inQueue[i] = 0;
		preds[i] = NOPRED;
	}
	
	shortestDists[convertIndex(ids, source)] = 0;
	enqueue(pq, 0, &(queueItems[convertIndex(ids, source)]));
	
	while(!empty(pq)) {
		current = dequeue(pq);
		if (visited[current->id ]) {
			continue;
		}
		visited[current->id] = 1;
		
		edgeList = getAdjacent(graph, ids, current->id);
		
		while(edgeList) {
			if (edgeList->weight + shortestDists[current->id] < shortestDists[edgeList->destIndex]) {
				shortestDists[edgeList->destIndex] = edgeList->weight + shortestDists[current->id];
				preds[edgeList->destIndex] = current->id;
				if (inQueue[edgeList->destIndex]) {
					update(pq, 0, updatedijkQstruct);
				} else {
					enqueue(pq, shortestDists[edgeList->destIndex], &(queueItems[edgeList->destIndex]));
				}
			}
			nextEdge = edgeList->next;
			free(edgeList);
			edgeList = nextEdge;
		}
	}
	free(visited);
	free(queueItems);
	freeQueue(pq);
	free(inQueue);
	
	res->sourceNode = convertIndex(ids, source);
	res->shortestPaths = shortestDists;
	res->indices = ids;
	res->preds = preds;
	res->nodeCount = nodes;
	
	return res;
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

