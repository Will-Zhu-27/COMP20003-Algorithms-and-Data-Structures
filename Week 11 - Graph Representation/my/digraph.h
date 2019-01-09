/* digraph.h */
struct weightedEdge {
	int destVertex;
	int weight;
	struct weightedEdge *next;
};
struct digraph {
	int *vertex;
	struct weightedEdge **adjacencyList;
	int capacity;
};

struct digraph *newDigraph();

int retIndex(struct digraph *graph, int vertex);

void addVertex(struct digraph *graph, int vertex);

void addEdge(struct digraph *graph, int source, int destination, int weight);

void freeDigraph(struct digraph *graph);

void printEdge(struct digraph *graph, int vertex);
