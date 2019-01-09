/* digraph.h */
struct weightedEdge {
	int destVertex;
	int weight;
	struct weightedEdge *next;
};
struct digraph {
	char *vertex;
	struct weightedEdge **adjacencyList;
	int capacity;
};

struct digraph *newDigraph();

int retIndex(struct digraph *graph, char vertex);

void addVertex(struct digraph *graph, char vertex);

void addEdge(struct digraph *graph, char source, char destination, int weight);

void freeDigraph(struct digraph *graph);

void printEdge(struct digraph *graph, char vertex);

/* judge whether there is this vertex */
int hasVertex(struct digraph *graph, char vertex);