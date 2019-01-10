/* main.c */
#include <stdio.h>
#include <stdlib.h>

#ifndef _DIGRAPH_H_
#define _DIGRAPH_H_
#include "digraph.h"
#endif

#ifndef _DIJKSTRA_H_
#define _DIJKSTRA_H_
#include "dijkstra.h"
#endif

#define EDGES 27
#define RESIDENTIAL 3
#define WORKPLACES 10

/* function prototype */
/* if the capacity from source to workplaces is more than road capacity, return 1, otherwise return 0 */
int testRoadCapacity(struct dijkstraQueue *dq, int district, int workers[RESIDENTIAL][WORKPLACES], int residential, int workplaces);
/* minus the load and return the new capacity */
int minusLoad (struct dijkstraQueue *source, int destVertex, int load);

int main(int argc, char **argv){
    struct dijkstraQueue *dq = NULL;
    int flag = 0;
    /* 
        For this problem, nodes with index 1 - 10 are workplaces 1 - 10 and
        nodes with index 11 - 13 are the residential districts 1 - 3
    */
    int src[EDGES];
    int dest[EDGES];
    int weight[EDGES];
    int capacity[EDGES];
    /* 
        The number of workers from each residential district that work
        at each workplace.
    */
    int workers[RESIDENTIAL][WORKPLACES];
    struct digraph *graph = newDigraph();
    int i = 0;
    /* 
        As edges are symmetric, only the first occurrence of each edge
        is included. 
    */
    src[i] = 1 ; dest[i] = 5 ; weight[i] = 95 ; capacity[i] = 600; i++;
    src[i] = 1 ; dest[i] = 10; weight[i] = 81 ; capacity[i] = 200; i++;
    src[i] = 1 ; dest[i] = 11; weight[i] = 100; capacity[i] = 900; i++;
    src[i] = 1 ; dest[i] = 21; weight[i] = 50 ; capacity[i] = 500; i++;
    src[i] = 2 ; dest[i] = 12; weight[i] = 100; capacity[i] = 500; i++;
    
    src[i] = 2 ; dest[i] = 14; weight[i] = 50 ; capacity[i] = 500; i++;
    src[i] = 3 ; dest[i] = 12; weight[i] = 100; capacity[i] = 800; i++;
    src[i] = 3 ; dest[i] = 15; weight[i] = 60 ; capacity[i] = 400; i++;
    src[i] = 3 ; dest[i] = 17; weight[i] = 20 ; capacity[i] = 700; i++;
    src[i] = 4 ; dest[i] = 6 ; weight[i] = 109; capacity[i] = 800; i++;
    
    src[i] = 4 ; dest[i] = 12; weight[i] = 32 ; capacity[i] = 500; i++;
    src[i] = 4 ; dest[i] = 13; weight[i] = 16 ; capacity[i] = 600; i++;
    src[i] = 5 ; dest[i] = 1 ; weight[i] = 95 ; capacity[i] = 600; i++;
    src[i] = 5 ; dest[i] = 6 ; weight[i] = 37 ; capacity[i] = 900; i++;
    src[i] = 7 ; dest[i] = 18; weight[i] = 42 ; capacity[i] = 800; i++;
    
    src[i] = 7 ; dest[i] = 20; weight[i] = 50 ; capacity[i] = 900; i++;
    src[i] = 8 ; dest[i] = 14; weight[i] = 50 ; capacity[i] = 500; i++;
    src[i] = 8 ; dest[i] = 15; weight[i] = 40 ; capacity[i] = 400; i++;
    src[i] = 9 ; dest[i] = 22; weight[i] = 47 ; capacity[i] = 300; i++;
    src[i] = 10; dest[i] = 22; weight[i] = 55 ; capacity[i] = 400; i++;
    
    src[i] = 11; dest[i] = 20; weight[i] = 50 ; capacity[i] = 900; i++;
    src[i] = 12; dest[i] = 16; weight[i] = 135; capacity[i] = 900; i++;
    src[i] = 12; dest[i] = 13; weight[i] = 204; capacity[i] = 230; i++;
    src[i] = 16; dest[i] = 17; weight[i] = 168; capacity[i] = 900; i++;
    src[i] = 17; dest[i] = 19; weight[i] = 15 ; capacity[i] = 700; i++;
    
    src[i] = 18; dest[i] = 19; weight[i] = 61 ; capacity[i] = 800; i++;
    src[i] = 21; dest[i] = 22; weight[i] = 50 ; capacity[i] = 500;
    
    for(i = 0; i < EDGES; i++){
        addEdge(graph, src[i], dest[i], weight[i], capacity[i]);
        addEdge(graph, dest[i], src[i], weight[i], capacity[i]);
    }
    
    /* Workers from residential district 1. */
    workers[0][0] = 300; workers[0][1] = 200; workers[0][2] = 50 ;
    workers[0][3] = 40 ; workers[0][4] = 60 ; workers[0][5] = 80 ;
    workers[0][6] = 90 ; workers[0][7] = 70 ; workers[0][8] = 90 ;
    workers[0][9] = 20 ;
    
    /* Workers from residential district 2. */
    workers[1][0] = 80 ; workers[1][1] = 300; workers[1][2] = 200;
    workers[1][3] = 30 ; workers[1][4] = 35 ; workers[1][5] = 80 ;
    workers[1][6] = 100; workers[1][7] = 150; workers[1][8] = 10 ;
    workers[1][9] = 15 ;
    
    /* Workers from residential district 3. */
    workers[2][0] = 20 ; workers[2][1] = 10 ; workers[2][2] = 50 ;
    workers[2][3] = 500; workers[2][4] = 100; workers[2][5] = 200;
    workers[2][6] = 30 ; workers[2][7] = 5  ; workers[2][8] = 75 ;
    workers[2][9] = 10 ;
    
    /* 
        Work out whether the sum of traffic over all workers 
        and workplaces is greater than the capacity of any road
        which is taken to get to any workplaces from any of the
        residential districts.
    */
    /*for (i = 0; i < graph->capacity; i++) {
        printEdge(graph, i);
    }*/
    for (i = 11; i <= 13; i++) {
        dq = dijkstra(graph, i);
        if (testRoadCapacity(dq, i - WORKPLACES, workers, RESIDENTIAL, WORKPLACES) == 1) {
            printf("Road capacity is not enough\n");
            flag = 1;
            free(dq);
            break;   
        }
        free(dq);
    }
    
    if (!flag) {
        printf("Road capacity is enough\n");
    }

    
    freeDigraph(graph);
    
    return 0;
}

/* if the capacity from source to workplaces is more than road capacity, return 1, otherwise return 0 */
int testRoadCapacity(struct dijkstraQueue *dq, int district, int workers[RESIDENTIAL][WORKPLACES], int residential, int workplaces) {
    int i;
    int load;
    struct dijkstraQueue *pred = NULL, *dest = NULL;
    for (i = 0; i < workplaces; i++) {
        load = workers[district - 1][i];
        dest = &(dq[i + 1]);
        pred = dest->pred;
        while (pred) {
            if (minusLoad(pred, dest->vertex, load) < 0) {
                 return 1;
            }
            dest = pred;
            pred = dest->pred;  
        }
        
    }
    return 0;
}

int minusLoad (struct dijkstraQueue *source, int destVertex, int load) {
    struct weightedEdge *edge = NULL;
    edge = source->edge;
    while (edge->destVertex != destVertex) {
        edge = edge->next;
    }
    edge->capacity -= load;
    return edge->capacity;
}
