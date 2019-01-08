/* test directed graph */
#include <stdio.h>
#include <stdlib.h>

#ifndef _DIGRAPH_H_
#define _DIGRAPH_H_
#include "digraph.h"
#endif

int main(int argc, char **argv) {
	struct digraph *graph = NULL;
	graph = newDigraph();
	addEdge(graph, 1, 2, 100);
	return 0;
}

