/* pqueue.c */
#include <stdlib.h>
#include <assert.h>
#include "pqueue.h"
struct pqueue {
    /* FILL IN THIS PART */
	int *priority;
	void **dataList;
	int used;
	
};

struct pqueue *makeQueue(){
    /* Write this */
    struct pqueue *newQueue = (struct pqueue *)malloc(sizeof(struct pqueue));
    assert(newQueue);
    newQueue->dataList = NULL;
    newQueue->priority = NULL;
    newQueue->used = 0;
    
    return newQueue;
}

void enqueue(struct pqueue *queue, int priority, void *data){
    /* Write this */
    queue->priority = realloc(queue->priority, sizeof(int) * (queue->used + 1));
    assert(queue->priority);
    queue->priority[queue->used] = priority;
    
    queue->dataList = realloc(queue->dataList, sizeof(void *) * (queue->used + 1));
    assert(queue->dataList);
    queue->dataList[queue->used] = data;
    (queue->used)++;
}

void *dequeue(struct pqueue *queue){
    /* Write this */
    int i;
    int highestPriority, highestPriorityIndex;
    void *returnValue;
    
    if (queue->used == 0) {
    	return NULL;
	}
	
	highestPriority = queue->priority[0];
    highestPriorityIndex = 0;
    for ( i = 1; i < queue->used; i++) {
    	if (queue->priority[i] > queue->priority[highestPriorityIndex]) {
    		highestPriorityIndex = i;
		}
	}
	returnValue = (queue->dataList)[highestPriorityIndex];
	queue->priority[highestPriorityIndex] = queue->priority[queue->used - 1];
	queue->dataList[highestPriorityIndex] = queue->dataList[queue->used - 1];
	queue->priority = realloc(queue->priority, sizeof(int) * (queue->used - 1));
	queue->dataList = realloc(queue->dataList, sizeof(void *) * (queue->used - 1));
	(queue->used)--;
	if (queue->used > 0) {
		assert(queue->dataList);
		assert(queue->priority);
	}
    return returnValue;
}

void update(struct pqueue *queue, int index){
    /* Do whatever is appropriate. */
    return;
}

int empty(struct pqueue *queue){
    /* Write this. */
    return queue->used == 0;
}

void freeQueue(struct pqueue *queue){
    if (!queue) {
    	return;
	}
	if (queue->dataList) {
		free(queue->dataList);
	}
	if (queue->priority) {
		free(queue->priority);
	}
	free(queue);
}

