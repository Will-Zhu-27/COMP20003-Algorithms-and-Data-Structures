#include "digraph.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

struct digraph {
	int lowIndex;
	int highIndex;
	struct weightedEdge **adjacencyList;
	int allocated; //和used的区别？ 
	int used;
};

struct digraph *newDigraph() {
	struct digraph *retDigraph = (struct digraph *)malloc(sizeof(struct digraph));
	assert(retDigraph);
	
	retDigraph->adjacencyList = NULL;
	retDigraph->allocated = 0;
	retDigraph->used = 0;
	
	return retDigraph;
}

void addEdge(struct digraph *graph, int source, int destination, int weight) {
	int initialSize;
	int newLow;
	int newHigh;
	int i;
	struct weightedEdge *newEdge;
	if (! graph->allocated) {
		initialSize = source - destination;
		if (initialSize < 0) {
			initialSize = -initialSize;
		}
		
		initialSize = initialSize + 1;
		graph->adjacencyList = (struct weightedEdge **) malloc(sizeof(struct weightedEdge *) * initialSize);
		assert(graph->adjacencyList);
		graph->allocated = initialSize; //
		/* initialise edge list */
		for(i = 0; i < initialSize; i++) {
			(graph->adjacencyList)[i] = NULL;
		}
		/* initialise low and high indices */
		if (source < destination) {
			graph->lowIndex = source;
			graph->highIndex = destination;
		} else {
			graph->lowIndex = destination;
			graph->highIndex = source;
		}
		graph->used = initialSize;
	} else {
		/* ensure we have space for the new edge */
		if (graph->lowIndex > source || graph->lowIndex > destination) {
			if (source < destination) {
				newLow = source;
			} else {
				newLow = destination;
			}
		} else {
			newLow = graph->lowIndex;
		}
		if (graph->highIndex < source || graph->highIndex < destination) {
			if (source > destination) {
				newHigh = source;
			} else {
				newHigh = destination;
			}
		} else {
			newHigh = graph->highIndex;
		}
		/* when the highIndex or lowIndex changes, update allocated and adjacencyList */
		if (newHigh != graph->highIndex || newLow != graph->lowIndex) {
			graph->allocated = newHigh - newLow + 1;
			graph->adjacencyList = (struct weightedEdge **) realloc(graph->adjacencyList, sizeof(struct weightedEdge *) * graph->allocated);
			assert(graph->adjacencyList);
			
			for (i = graph->highIndex - graph->lowIndex; i >= 0; i--) {
				graph->adjacencyList[i - newLow + graph->lowIndex] = graph->adjacencyList[i];
			}
			for (i = 0; i < (graph->lowIndex - newLow); i++) {
				graph->adjacencyList[i] = NULL;
			}
			for(i = graph->highIndex - newLow + 1; i < (newHigh - newLow + 1); i++){
                graph->adjacencyList[i] = NULL;
            }
            
            graph->lowIndex = newLow;
            graph->highIndex = newHigh;
            graph->used = graph->allocated;
		}
	}
	/* add new edge to the corresponding adjacencyList */
	newEdge = (struct weightedEdge *) malloc(sizeof(struct weightedEdge));
	assert(newEdge);
	newEdge->destIndex = destination;
	newEdge->weight = weight;
	newEdge->next = graph->adjacencyList[source - graph->lowIndex];
	graph->adjacencyList[source - graph->lowIndex] = newEdge;
}
