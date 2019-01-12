/* main.c */
#include <stdio.h>
#include <stdlib.h>
#include "adjmatrix.h"
#include "fw.h"

#define SIZE 10

int main(int argc, char **argv){
    
    int **graph = newMatrix(SIZE);
    int **pathMatrix = NULL;
    int home        = 0;
    int firstPoint  = 1;
    int secondPoint = 6;
    int thirdPoint  = 9;
    int i, j, k;
    int maxDist = 0;

    addEdge(graph, 0, 4, 2);
    addEdge(graph, 1, 2, 2);
    addEdge(graph, 1, 3, 5);
    addEdge(graph, 1, 4, 10);
    addEdge(graph, 2, 3, 2);
    addEdge(graph, 3, 4, 2);
    addEdge(graph, 3, 5, 6);
    addEdge(graph, 4, 5, 2);
    addEdge(graph, 6, 7, 5);
    addEdge(graph, 6, 8, 9);
    addEdge(graph, 7, 8, 6);
    addEdge(graph, 8, 9, 3);
    
    /* Add reversed edges. */
    addEdge(graph, 4, 0, 2);
    addEdge(graph, 2, 1, 2);
    addEdge(graph, 3, 1, 5);
    addEdge(graph, 4, 1, 10);
    addEdge(graph, 3, 2, 2);
    addEdge(graph, 4, 3, 2);
    addEdge(graph, 5, 3, 6);
    addEdge(graph, 5, 4, 2);
    addEdge(graph, 7, 6, 5);
    addEdge(graph, 8, 6, 9);
    addEdge(graph, 8, 7, 6);
    addEdge(graph, 9, 8, 3);
    
    /* 
        Find the ordering of points that
        gives the maximum distance using the
        shortest paths between each sequential
        point.
    */
    printf("Begin\n");
    fw(graph, &pathMatrix, SIZE);
    printPath(pathMatrix, home, firstPoint);
    //printPath(pathMatrix, firstPoint, secondPoint);
    //printPath(pathMatrix, secondPoint, thirdPoint);
    //printPath(pathMatrix, thirdPoint, home);
    /*
    printf("finish fw function\n");
    maxDist += shortestDist(graph, pathMatrix, SIZE, home, firstPoint);
    maxDist += shortestDist(graph, pathMatrix, SIZE, firstPoint, secondPoint);
    maxDist += shortestDist(graph, pathMatrix, SIZE, secondPoint, thirdPoint);
    maxDist += shortestDist(graph, pathMatrix, SIZE, thirdPoint, home);
    printf("finish calculate maxDist\n");
    printf("The maximum ordering is %d (home) to #%d to #%d to #%d and back to %d\n",
        home, firstPoint, secondPoint, thirdPoint, home);
    
    printf("%d\n", maxDist);*/
    freeMatrix(graph,SIZE);
    freePathMatrix(pathMatrix, SIZE);
    
    return 0;
}