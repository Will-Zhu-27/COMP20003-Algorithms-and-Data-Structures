/* test directed graph */
#include <stdio.h>
#include <stdlib.h>

#ifndef _DIGRAPH_H_
#define _DIGRAPH_H_
#include "digraph.h"
#endif

int main(int argc, char **argv) {
	struct digraph *graph = NULL;
	int i;
	graph = newDigraph();
	addEdge(graph, 1, 2, 200);

	addEdge(graph, 1, 3, 300);
	
	addEdge(graph, 2, 3, 500);

	for (i = 0; i < graph->capacity; i++) {
		printEdge(graph, graph->vertex[i]);
	}
	freeDigraph(graph);
	return 0;
}

