#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#ifndef _DIGRAPH_H_
#define _DIGRAPH_H_
#include "digraph.h"
#endif

/* judge whether there is this vertex */
int hasVertex(struct digraph *graph, int vertex);

struct weightedEdge {
	int destVertex;
	int weight;
	struct weightedEdge *next;
};

struct digraph *newDigraph() {
	struct digraph *retDigraph = (struct digraph *) malloc(sizeof(struct digraph));
	assert(retDigraph);
	
	retDigraph->vertex = NULL;
	retDigraph->adjacencyList = NULL;
	retDigraph->capacity = 0;
	
	return retDigraph;
}
/* judge whether there is this vertex */
int hasVertex(struct digraph *graph, int vertex) {
	int i, flag = 0;
	for (i = 0; i < graph->capacity; i++) {
		if((graph->vertex)[i] == vertex) {
			flag = 1;
			break;
		}
	}
	return flag;
}

int retIndex(struct digraph *graph, int vertex) {
	int index;
	for (index = 0; index < graph->capacity; index++) {
		if((graph->vertex)[index] == vertex) {
			break;
		}
	}
	return index;
}

void addVertex(struct digraph *graph, int vertex) {
	if (hasVertex(graph, vertex)) {
		return;
	}
	graph->vertex = realloc(graph->vertex, sizeof(int) * (graph->capacity + 1));
	(graph->vertex)[graph->capacity] = vertex;
	graph->adjacencyList = realloc(graph->adjacencyList, sizeof(void *) * (graph->capacity + 1));
	graph->capacity++;
}

void addEdge(struct digraph *graph, int source, int destination, int weight) {
	struct weightedEdge *newEdge = NULL;
	int index;
	
	if (!hasVertex(graph, source)) {
		addVertex(graph, source);
	}
	if (!hasVertex(graph, destination)) {
		addVertex(graph, destination);
	}
	
	index = retIndex(graph, source);
	newEdge = (struct weightedEdge *) malloc(sizeof(struct weightedEdge));
	assert(newEdge);
	newEdge->destVertex = destination;
	newEdge->weight = weight;
	newEdge->next = (graph->adjacencyList)[index];
	(graph->adjacencyList)[index] = newEdge;
}

void freeDigraph(struct digraph *graph) {
	int i;
	struct weightedEdge *temp = NULL;
	if (!graph) {
		return;
	}
	if (graph->vertex) {
		free(graph->vertex);
	}
	if (graph->capacity > 0) {
		for (i = 0; i < graph->capacity; i++) {
			while((graph->adjacencyList)[i]) {
				temp = (graph->adjacencyList)[i];
				(graph->adjacencyList)[i] = temp->next;
				free(temp);
			}
		}
		free (graph->adjacencyList);
	}
}
