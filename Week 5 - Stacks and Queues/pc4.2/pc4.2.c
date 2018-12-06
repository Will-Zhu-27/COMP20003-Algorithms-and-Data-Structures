#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stack.h"

#define PROBLEMCOUNT 9
/* 
    Returns 1 if the null-terminated string given has 
    matched brackets and 0 otherwise. Only parentheses
    "()" are considered brackets for the purposes of
    this problem (though others are, in principle, 
    relatively trivial extensions of logic you've 
    applied before, so if you'd like to give it a
    go, feel free).
*/
int bracketCheck(char *input);


int main(int argc, char **argv){
    int i;
    char *problems[PROBLEMCOUNT];
    problems[0] = "No brackets.";
    problems[1] = "(One level of brackets)";
    problems[2] = "(Missing end bracket";
    problems[3] = "((Two levels of bracket))";
    problems[4] = "((((Four levels of bracket))))";
    problems[5] = "((Set)(Of)(Brackets)(at)(same)(level))";
    problems[6] = "(((Set)(Of))(Brackets)(at(different)((levels))))";
    problems[7] = "(((Set)(Of))(Mismatched(Brackets)(at(different)((levels))))";
    problems[8] = "Missing start bracket)";
    
    for(i = 0; i < PROBLEMCOUNT; i++){
        if(bracketCheck(problems[i])){
            printf("Matched:   %s\n",problems[i]);
        } else {
            printf("Unmatched: %s\n",problems[i]);
        }
    }
    
    return 0;
}

int bracketCheck(char *input){
    /* FILL IN HERE */
    struct stack *stack = makeStack();
    int i = 0;
    for (i = 0; i < strlen(input); i++) {
    	if (input[i] == '(') {
    		push(stack, '(');
		} else if (input[i]==')') {
			if (! empty(stack) && pop(stack) == '(') {
				continue;
			} else {
				return 0;
			}
		}
	}
	if (! empty(stack)) {
		return 0;
	} else {
		return 1;
	}
}

