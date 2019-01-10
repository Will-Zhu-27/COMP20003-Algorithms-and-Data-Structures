/* priorityQueue.c */
/* use heap to store priority queue */

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#ifndef _PRIORITYQUEUE_H_
#define _PRIORITYQUEUE_H_
#include "priorityQueue.h"
#endif

void upHeap(struct priorityQueue *pq);
void downHeap(struct priorityQueue *pq, int startIndex);

struct priorityQueue *makePriorityQueue() {
	struct priorityQueue *ret = NULL;
	ret = (struct priorityQueue *) malloc(sizeof(struct priorityQueue));
	assert(ret);
	ret->capacity = 0;
	ret->dataList = NULL;
	ret->priority = NULL;
	return ret;
};

/* enqueue one item into an already-formed heap and put it in right location */
void enqueue(struct priorityQueue *pq, void *data, int priority) {
	directEnqueue (pq, data, priority);
	upHeap(pq);
}

/* just insert it into the tail of priority queue 
	after all items are inserted, use heapSort */
void directEnqueue (struct priorityQueue *pq, void *data, int priority) {
	pq->dataList = realloc(pq->dataList, sizeof(void *) * (pq->capacity + 1));
	assert(pq->dataList);
	pq->dataList[pq->capacity] = data;
	
	pq->priority = realloc(pq->priority, sizeof(int) * (pq->capacity + 1));
	assert(pq->priority);
	pq->priority[pq->capacity] = priority;
	
	pq->capacity++;
}

void *dequeue(struct priorityQueue *pq) {
	void *retValue = NULL;
	
	if(pq->capacity == 0) {
		printf("The priority queue is empty\n");
		return NULL;
	}
	retValue = pq->dataList[0];
	/* move the last to the top */
	pq->dataList[0] = pq->dataList[pq->capacity - 1];
	//free (pq->dataList[pq->capacity - 1]);
	pq->priority[0] = pq->priority[pq->capacity - 1];
	//free (pq->priority[pq->capacity - 1]);
	/* reallocate */
	pq->capacity--;
	pq->dataList = realloc(pq->dataList, sizeof(void *) * pq->capacity);
	pq->priority = realloc(pq->priority, sizeof(int) * pq->capacity);
		
	downHeap(pq, 0);
	
	return retValue;
}

int empty(struct priorityQueue *pq) {
	return pq->capacity == 0;
}

void upHeap(struct priorityQueue *pq) {
	int i, j;
	void *tempData;
	int tempPriority;
	
	if (pq->capacity == 1) {
		return;
	}
	tempData = pq->dataList[pq->capacity - 1];
	tempPriority = pq->priority[pq->capacity - 1];
	i = pq->capacity - 1;
	j = ((i + 1) / 2) - 1;
	while (tempPriority > (pq->priority)[j]) {
		pq->priority[i] = pq->priority[j];
		pq->dataList[i] = pq->dataList[j];
		i = j;
		j = ((i + 1) / 2) - 1;
		if (j < 0) {
			break;
		}
	}
	pq->priority[i] = tempPriority;
	pq->dataList[i] = tempData;
}

void downHeap(struct priorityQueue *pq, int startIndex) {
	int i, j;
	void *tempData;
	int tempPriority;
	if (pq->capacity == 1 || pq->capacity == 0) {
		return;
	}
	i = startIndex;
	tempData = pq->dataList[i];
	tempPriority = pq->priority[i];
	while((i + 1) <= pq->capacity / 2) {
		j = (i + 1) * 2 - 1;
		if ( j + 1 < pq->capacity && pq->priority[j] < pq->priority[j + 1]) {
			j++;
		}
		if (tempPriority >= pq->priority[j]) {
			break;
		}
		pq->priority[i] = pq->priority[j];
		pq->dataList[i] = pq->dataList[j];
		i = j;
	}
	pq->priority[i] = tempPriority;
	pq->dataList[i] = tempData;
}

void freeQueue(struct priorityQueue *pq) {
	if (!pq) {
		return;
	}
	if (pq->dataList) {
		free(pq->dataList);
	}
	if (pq->priority) {
		free (pq->priority);
	}
	free (pq);
}

/* sort the datalist in pq according to the priority */
void heapSort(struct priorityQueue *pq) {
	int i;
	if (!pq || pq->capacity <= 1) {
		return;
	}
	for(i = pq->capacity / 2; i >= 0; i--) {
		downHeap(pq, i);
	}
}

/* success: 1, failure: 0 */
int changePriority(struct priorityQueue *pq, void *data, int newPriority) {
	int i, flag = 0;
	for (i = 0; i < pq->capacity; i++) {
		if (pq->dataList[i] == data) {
			flag = 1;
			break;
		}
	}

	/* return if data is not in the priority queue */
	if (!flag) {
		printf("data is not in the priority queue\n");
		printf("the data's address is %p\n\n\n", data);
		return flag;
	}

	pq->priority[i] = newPriority;
	heapSort(pq);
	return flag;
}

void printDatalistAddress(struct priorityQueue *pq) {
	int i;
	for (i = 0; i < pq->capacity; i++) {
		printf ("%d is %p, the priority is %d\n", i, pq->dataList[i], pq->priority[i]);
	}
}
