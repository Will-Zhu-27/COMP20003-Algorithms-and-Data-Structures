/* stack.c */
#include <stdlib.h>
#include <assert.h>
#include <stdio.h>
#include "stack.h"
/* indirect function prototype */
struct stackItem;

struct stack {
    /* FILL IN: Define stack struct here. */
    struct stackItem *link; 
};

struct stackItem {
	char item;
	struct stackItem *next;
};

struct stack *makeStack(){
    /* FILL IN */
    struct stack *stack = (struct stack *)malloc(sizeof(struct stack));
    if (!stack) {
    	printf("malloc error!\n");
    	exit(EXIT_FAILURE);
	}
    stack->link = NULL;
    return stack;
}

void push(struct stack *stack, char item){
    /* FILL IN */
    struct stackItem *newNode = NULL;
    if (!stack) {
    	printf("stack doesn't exist!\n");
    	exit(EXIT_FAILURE);
	}
	newNode = (struct stackItem *)malloc(sizeof(struct stackItem));
	if (!newNode) {
		printf("malloc error!\n");
		exit(EXIT_FAILURE);
	}
	newNode->item = item;
	newNode->next = stack->link;
	stack->link = newNode;
}

char pop(struct stack *stack){
    /* FILL IN */
    struct stackItem *temp = NULL;
    char item;
    if (!stack || !stack->link) {
		return 0;
	}
	item = stack->link->item;
	temp = stack->link;
	stack->link = stack->link->next;
	free(temp);
    return item;
}

int empty(struct stack *stack){
    /* FILL IN */
    if (!stack || !stack->link) {
		return 1;
	}
    return 0;
}

void freeStack(struct stack **stack){
    /* FILL IN */
    if (!*stack) {
    	return;
	}
    while (!empty(*stack)) {
    	pop(*stack);
	}
    free(*stack);
    stack = NULL;
}

