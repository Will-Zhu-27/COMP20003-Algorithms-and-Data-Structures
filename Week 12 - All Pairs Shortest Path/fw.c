/* fw.c */
#include <stdio.h>
#include "adjmatrix.h"

void fw(int **adjMatrix, int ***pathMatrix, int size){
    /* FILL IN */
    int i, s, t;
    /* initialize *pathMatrix */
    *pathMatrix = newMatrix(size);
    for (i = 0; i < size; i++) {
        (*pathMatrix)[i][i] = i;
    }
   
    for (i = 0; i < size; i++) {
        for (s = 0; s < size; s++) {
            if (adjMatrix[i][s] != NOPATH) {
                (*pathMatrix)[i][s] = s;
            }
        }
    }

    for (i = 0; i < size; i++) {
        for (s = 0; s < size; s++) {
            for (t = 0; t < size; t++) {
                if (adjMatrix[s][i] + adjMatrix[i][t] < adjMatrix[s][t]) {
                    adjMatrix[s][t] = adjMatrix[s][i] + adjMatrix[i][t];
                    (*pathMatrix)[s][t] = i;
                }
            }
        }
    }
}

void printPath(int **pathMatrix, int src, int dest){
    /* FILL IN */
    int start;
    if (src == dest) {
        printf("%d\n\n", src);
        return;
    }
    if (pathMatrix[src][dest] == NOPATH) {
        printf("NO PATH\n\n");
        return;
    }
    start = src;

    printf("%d", start);
    while (start != dest) {
        printf("-->%d", pathMatrix[start][dest]);
        start = pathMatrix[start][dest];
    }
    printf("\n\n");
}

void freePathMatrix(int **pathMatrix, int size){
    /* Fill in */
    freeMatrix(pathMatrix, size);
}