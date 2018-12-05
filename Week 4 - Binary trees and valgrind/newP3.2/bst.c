/* bst.c */
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "llqueue.h"
#include "bst.h"
struct bst {
	struct bst *left;
	struct bst *right;
	struct bst *parent;
	int data;
	int depth;
	int counter;
};

/* indirect function prototyoe */
int countDepth(struct bst *parent);
void rightRotation(struct bst *node);
void leftRotation(struct bst *node);
/* after insert a node, update all node's counter and depth using the inserted node as parameter */
void update(struct bst **node);
void keepBalanced(struct bst *node);

void rightRotation(struct bst *node) {
	struct bst *parent = node->parent;
	struct bst *lChild = node->left;
	struct bst *lRChild = node->left->right;
	printf("node %d right rotates\n", node->data);
	/* lChild becomes node */
	if (parent) {
		if (parent->left == node) {
			parent->left = lChild;
		} else {
			parent->right = lChild;
		}
	}
	lChild->parent = parent;
	
	/* node becomes lRchild */
	node->parent = lChild;
	lChild->right = node;
	
	/* lRChild becomes rLchild */
	node->left = lRChild;
	if (lRChild) {
		lRChild->parent = node;
	}
	printf("右旋转函数结束\n");
	//printf("从%d节点开始更新");
	update(&node);
}

void leftRotation(struct bst *node) {
	struct bst *parent = node->parent;
	struct bst *rChild = node->right;
	struct bst *rLChild = node->right->left;
	printf("node %d left rotates\n", node->data);
	/* rChild becomes node */
	rChild->parent = parent;
	if (parent) {
		if (parent->left == node) {
			parent->left = rChild;
		} else {
			parent->right = rChild;
		}
	}
	
	/* node becomes lChild */
	node->parent = rChild;
	rChild->left = node;
	
	/* rLChild beomces lRchild */
	node->right = rLChild;
	if (rLChild) {
		rLChild->parent = node;
	}
	update(&node);
}
/*
The function you are to write. Takes a parent pointer (null for the root),
and returns the tree with the child in the right position. Returns the
item in a new tree with null left/right pointers.
*/
struct bst *bstInsert(struct bst *parent, int data){
	/* Write this function. */
	struct bst **currentNodePtr = &parent;
	struct bst *parentCurrentNode = NULL;
	
	while (*currentNodePtr) {
		parentCurrentNode = *currentNodePtr;
		if ((*currentNodePtr)->data > data) {
			currentNodePtr = &((*currentNodePtr)->left);
		} else {
			currentNodePtr = &((*currentNodePtr)->right);
		}
	}
	(*currentNodePtr) = (struct bst *)malloc(sizeof(struct bst));
	(*currentNodePtr)->data = data;
	(*currentNodePtr)->right = NULL;
	(*currentNodePtr)->left = NULL;
	(*currentNodePtr)->parent = parentCurrentNode;
	(*currentNodePtr)->depth = -1;
	(*currentNodePtr)->counter = 0;
	printf("新节点%d的前一个节点是",(*currentNodePtr)->data);
	if ((*currentNodePtr)->parent) {
		printf("%d\n",(*currentNodePtr)->parent->data);
	} else {
		printf("null\n");
	}
	/* update all node's depth and counter */
	update(currentNodePtr);
	/*if ((*currentNodePtr)->data == 3) {
		printf("旋转\n");
		leftRotation((*currentNodePtr)->parent->parent);
		printf("旋转结束\n");
	}*/
	/* keep balanced */
	keepBalanced(*currentNodePtr);
	while(parent->parent) {
		parent = parent->parent;
	}
	/*
	printf("插入结束\nroot is %d\n",parent->data);
	if (parent->data == 2 && parent->left && parent->right) {
		printf("lChild is %d, depth is %d, counter is %d\n", parent->left->data, parent->left->depth, parent->left->counter);
		if (!parent->left->left) {
			printf("left is null\n");
		} else {
			exit(0);
		}
		if (!parent->left->right) {
			printf("right is null\n");
		} else {
			exit(0);
		}
		printf("rChild is %d, depth is %d, counter is %d\n", parent->right->data, parent->left->depth, parent->left->counter);
		if (!parent->right->left) {
			printf("left is null\n");
		} else {
			printf("left exists\n");
			exit(0);
		}
		if (!parent->right->right) {
			printf("right is null\n");
		} else {
			printf("right exists\n");
			exit(0);
		}
		drawTree(parent);
	}*/
	return parent;
}
/* after insert a node, update all node's counter and depth using the inserted node as parameter */
void update(struct bst **node) {
	struct bst **currentNodePtr = node;
	//int newCounter = 0;
	/* update all node's depth and counter */
	while(*currentNodePtr) {
		printf("现在更新节点%d的counter值\n",(*currentNodePtr)->data); 
		(*currentNodePtr)->depth = countDepth((*currentNodePtr));
		(*currentNodePtr)->counter = countDepth((*currentNodePtr)->left) - countDepth((*currentNodePtr)->right);
		/*if (newCounter == (*currentNodePtr)->counter) {
			break;
		} else {
			(*currentNodePtr)->counter = newCounter;
		}*/
		currentNodePtr = &((*currentNodePtr)->parent);
	}
}

void keepBalanced(struct bst *node) {
	printf("KeepBalanced from %d\n", node->data);
	while(node) {
		if (node->counter < -1) {
			if (node->right->counter > 0) {	
				rightRotation(node->right);
			}
			leftRotation(node);
		} else if (node->counter > 1) {
			if (node->left->counter <0) {
				leftRotation(node->left);
			}
			rightRotation(node);
		}
		node = node->parent;
	}
}
void freeTree(struct bst *parent){
	if(! parent){
	return;
	}
	/* Fill in function according to function description. */
	freeTree(parent->left);
	freeTree(parent->right);
	free(parent);
}
/* Calculate the number of spaces which need to appear before and after the
data point at a given depth to allow a single character to occur in all
children below it. */
int spacesAtDepth(int depth);
/* Calculate the depth to the deepest child of a given node. */
int countDepth(struct bst *parent);
/* Draws the tree. You will need to change this if your bst uses different names. */
/* You needn't understand how this works, but you're welcome to try. */
void drawTree(struct bst *parent){
	int i;
	if(!parent){
		/* Done, no tree to print. */
		return;
	}
	struct llqueue *currentQueue = newQueue();
	struct llqueue *nextQueue = newQueue();
	/* Used for swapping. */
	struct llqueue *tempQueue;
	/* Current node being processed */
	struct bst *current;
	/* The depth of the parent, used to work out where to place the value. */
	int depth = countDepth(parent);
	/* The number of spaces needed at the current level before and after each
	data value. */
	int spaces = spacesAtDepth(depth);
	/* Add the parent node to the queue. */
	queue(&currentQueue, parent);
	while(!empty(currentQueue) && depth >= 0){
		current = (struct bst *) dequeue(currentQueue);
		for(i = 0; i < spaces; i++){
			printf(" ");
		}
		if(current){
			printf("%2d",current->data);
		} else {
			printf(" ");
		}
		for(i = 0; i < spaces; i++){
			printf(" ");
		}
		/* Account for parent's space */
		printf(" ");
		/* Queue any children for next row */
		if(current && current->left){
			queue(&nextQueue, current->left);
		} else {
			/* Mark empty space so spacing stays consistent. */
			queue(&nextQueue, NULL);
		}
		if(current && current->right){
			queue(&nextQueue, current->right);
		} else {
			/* Mark empty space so spacing stays consistent. */
			queue(&nextQueue, NULL);
		}
		if(empty(currentQueue)){
			/* Start new row. */
			printf("\n");
			/* Update depth information. */
			depth--;
			spaces = spacesAtDepth(depth);
			/* Swap the new row to the current row. */
			tempQueue = currentQueue;
			currentQueue = nextQueue;
			nextQueue = tempQueue;
		}
	}
	/* If we reach depth 0, the queue may still have contents
	we must empty first. */
	while(!empty(currentQueue)){
		current = (struct bst *) dequeue(currentQueue);
	}
	if(tempQueue){
		free(nextQueue);
	}
	if(currentQueue){
		free(currentQueue);
	}
}
int countDepth(struct bst *parent){
	int leftDepth;
	int rightDepth;
	if(!parent){
		/* Here we assume a leaf node is at depth -1, other choices are possible. */
		return -1;
	}
	printf("countDepth: %d\n", parent->data);
	leftDepth = countDepth(parent->left);
	rightDepth = countDepth(parent->right);
	if(leftDepth > rightDepth){
		return leftDepth + 1;
	} else {
		return rightDepth + 1;
	}
}
int spacesAtDepth(int depth){
	int cDepth = depth;
	int result = 1;
	while(cDepth > 0){
	result = 2*result + 1;
	cDepth--;
	}
	return result;
}
