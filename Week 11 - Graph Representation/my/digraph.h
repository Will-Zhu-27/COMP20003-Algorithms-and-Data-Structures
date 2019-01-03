struct digraph;

struct weightedEdge {
	int destIndex;
	int weight;
	struct weightedEdge *next;
};
