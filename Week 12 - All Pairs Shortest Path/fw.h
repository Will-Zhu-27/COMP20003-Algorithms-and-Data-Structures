/* fw.h */
/* Finds shortest paths between all nodes and all other nodes.
    Allocates space for path matrix and stores this in the space pointed
    to by pathMatrix. 
    size is the dimension of the matrix. */
void fw(int **adjMatrix, int ***pathMatrix, int size);

/* Prints the path from the source node given to the destination node
    given using the given path matrix. The path printed is new line 
    terminated. */
void printPath(int **pathMatrix, int src, int dest);

/* Frees a path matrix and all the values within it. */
void freePathMatrix(int **pathMatrix, int size);