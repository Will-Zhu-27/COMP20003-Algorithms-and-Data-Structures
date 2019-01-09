#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#ifndef _PRIORITYQUEUE_H_
#define _PRIORITYQUEUE_H_
#include "priorityQueue.h"
#endif

int main(int argc, char **argv) {
    struct priorityQueue *pq = makePriorityQueue();
    int data[5] = {3, 5, 1, 2, 4};
    int priority[5] = {3, 5, 1, 2, 4};
    int i;
    for (i = 0; i < 5; i++) {
        enqueue(pq, &(data[i]), priority[i]);
    }
    
    printf("pop all data\n");
    while(!empty(pq)) {
        printf("%d\n", *(int *)dequeue(pq));
    }
    printf("finish pop\n");

    printf("\n now push them into priority queue again\n");
    for (i = 0; i < 5; i++) {
        enqueue(pq, &(data[i]), priority[i]);
    }
    printf("change 1's priority to max\n");
    changePriority(pq, &(data[2]), INT_MAX);
    printf("now pop them again\n");
    while(!empty(pq)) {
        printf("%d\n", *(int *)dequeue(pq));
    }
    freeQueue(pq);
    return 0;
}