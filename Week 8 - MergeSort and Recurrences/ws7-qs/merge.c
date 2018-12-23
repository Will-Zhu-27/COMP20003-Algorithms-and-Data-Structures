/* merge.c */
#include <stdio.h>
#include "merge.h"
#include "queue.h"

struct linkedList *merge(struct linkedList *list1, struct linkedList *list2);

struct linkedList *mergeSort(struct linkedList *list){
    /* FILL IN SETUP FOR Linked List BOTTOM-UP mergesort */
    struct llq *queue1 = NULL;
    struct llq *queue2 = NULL;
    
    struct linkedList *list1, *list2;
    struct linkedList *sortedList = NULL;
	
	while(list) {
		list1 = list->next;
		list->next = NULL;
		queue1 = add(queue1, list);
		list = list1;
	}
    
    while(queue1 && queue1->next) {
    	list1 = dequeue(&queue1);
    	list2 = dequeue(&queue1);
    	
    	list1 = merge(list1, list2);
    	
    	queue2 = add(queue2, list1);
    	if (queue1 && (!queue1->next)) {
    		list1 = dequeue(&queue1);
    		queue2 = add(queue2, list1);
		}
		if (queue1 == NULL) {
			queue1 = queue2;
			queue2 = NULL;
		}
	}
	if (queue1) {
		sortedList = dequeue(&queue1);
	}
	return sortedList;
}

struct linkedList *merge(struct linkedList *list1, struct linkedList *list2) {
	struct linkedList *sortedList = NULL;
	struct linkedList **endOfList = &sortedList; 
	
	while(list1 && list2) {
		if (list1->item <= list2->item) {
			*endOfList = list1;
			list1 = list1->next;
		} else {
			*endOfList = list2;
			list2 = list2->next;	
		}
		(*endOfList)->next = NULL;
		endOfList = &((*endOfList)->next);
	}
	if (list1) {
		*endOfList = list1;
	}
	if (list2) {
		*endOfList = list2;
	}
	
	return sortedList;
}
