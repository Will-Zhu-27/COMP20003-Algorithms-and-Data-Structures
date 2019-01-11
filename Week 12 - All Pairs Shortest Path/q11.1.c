/* main.c */
#include <stdio.h>
#include <stdlib.h>
#include "adjmatrix.h"
#include "fw.h"

#define SIZE 10

int main(int argc, char **argv){
    
    int **graph = newMatrix(SIZE);
    int **pathMatrix = NULL;
    int i, j;
    
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
    
    printf("Running Floyd-Warshall\n");
    fw(graph, &pathMatrix, SIZE);
    
    printf("Shortest path distances:\n");
    for(i = 0; i < SIZE; i++){
        for(j = 0; j < SIZE; j++){
            if(graph[i][j] == NOPATH){
                printf("N/A ");
            } else {
                printf("%3d ",graph[i][j]);
            }
        }
        printf("\n");
    }
    for(i = 0; i < SIZE; i++){
        printf("Shortest path from %d:\n",i);
        for(j = 0; j < SIZE; j++){
            printf("to %d: ",j);
            printPath(pathMatrix, i, j);
        }
        printf("--------------------------------------------------\n\n");
    }
    
    freeMatrix(graph, SIZE);
    freePathMatrix(pathMatrix, SIZE);
    
    return 0;
}
