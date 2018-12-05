/* main.c */
//%stdin: "8 4 9 11 6 7 1 5 3 14 10 13 2"
#include <stdio.h>
#include <stdlib.h>
#include "avl.h"
int main(int argc, char **argv){
	int inputData;
	struct bst *bst = NULL;
	while(scanf("%d",&inputData) > 0){
		bst = avlInsert(bst, inputData);
	}
	drawTree(bst);	
	printf("type the value you want to look up\n");
	fflush(stdin);
	while(scanf("%d",&inputData) > 0) {
		lookup(inputData, bst);
	}
	freeTree(bst);
	return 0;
}
