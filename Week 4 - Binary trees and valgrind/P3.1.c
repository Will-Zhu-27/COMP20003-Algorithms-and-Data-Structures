/* main.c */
//%stdin: "8 4 9 11 6 7 1 5 3 14 10 13 2"
#include <stdio.h>
#include <stdlib.h>
#include "bst.h"
int main(int argc, char **argv){
	int inputData;
	int lookupValue;
	struct bst *bst = NULL;
	while(scanf("%d",&inputData) > 0){
		bst = bstInsert(bst, inputData);
	}
	drawTree(bst);
	//fflush(stdout);
	getchar();
	
	printf("type a value to lookup\n");
	while(scanf("%d",&lookupValue) == 1){
		lookup(lookupValue, bst);
	}
	freeTree(bst);
	return 0;
}
