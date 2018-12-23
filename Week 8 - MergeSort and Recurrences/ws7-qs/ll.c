/* ll.c */
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include "ll.h"

struct linkedList *prepend(struct linkedList *head, int item){
    /* FILL IN if using. */
    struct linkedList *newHead = (struct linkedList *)malloc(sizeof(struct linkedList));
    if (!newHead) {
    	printf("malloc error!\n");
    	exit(EXIT_FAILURE);
	}
	
    newHead->item = item;
    newHead->next = head;
    return newHead;
}

/* Add a linked list item to the end of the list, traversing all items. */
struct linkedList *append(struct linkedList *head, int item){
    /* FILL IN if using. */
    struct linkedList *newEnd = (struct linkedList *)malloc(sizeof(struct linkedList));
    struct linkedList *currentEnd = head;
    
    if (!newEnd) {
    	printf("malloc error!\n");
    	exit(EXIT_FAILURE);
	}
    
    newEnd->item = item;
    newEnd->next = NULL;
    
    if (!head) {
    	return newEnd;
	}
	
    while(currentEnd->next) {
    	currentEnd = currentEnd->next;
	}
	currentEnd->next = newEnd;
    return head;
}

void freeList(struct linkedList *list) {
	struct linkedList *temp = NULL;
	while (list) {
		temp = list;
		list = list->next;
		free(temp);
	}
}
