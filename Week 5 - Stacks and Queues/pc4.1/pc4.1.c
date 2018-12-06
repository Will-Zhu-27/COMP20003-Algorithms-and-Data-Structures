/* Add your stack implementation from Programming 4.1 
    and change the data type from integer to character */

/* Compresses all duplicate characters into character and
    count pairs in given input and prints the results. */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stack.h"

void compress(char *input);

int main(int argc, char **argv){
    char *input = "Aaaaaa, screamed the amateur magician as the aardvark ate the apple he'd prepared...";
    
    compress(input);
    
    return 0;
}

void compress(char *input){
    /* FILL IN HERE */
    struct stack *stack = makeStack();
    int i;
    char lastItem;
    char stackItem;
    int count = 0;
    for (i = 0; i < strlen(input); i++) {
    	if (! empty(stack)) {
    		if (lastItem != input[i]) {
    			count = 0;
    			while (! empty(stack)) {
    				stackItem = pop(stack);
    				count++;
				}
				printf("%c%d",stackItem, count);
			}
		}
    	push(stack, input[i]);
    	lastItem = input[i];
	}
	if (! empty(stack)) {
    	if (lastItem != input[i]) {
    		count = 0;
    		while (! empty(stack)) {
    			stackItem = pop(stack);
    			count++;
			}
			printf("%c%d",stackItem, count);
		}
	}
	printf("\n");
	freeStack(&stack);
}
