#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define STARTSIZE 13
#define INPUTSIZE 14
#define SENTINEL -1
/* Declare hash table data structure */
struct hashTable {
	int *arrayPtr;
	int allocated;
	int used;
};

/* return next prime number after prime number n*/
int nextPrime(int n) {
	int i, nextPrime = n + 1, isPrime = 1;
	while(1) {
		isPrime = 1;
		for ( i = 2; i <= (int)sqrt(nextPrime); i++) {
			if ( nextPrime % i == 0) {
				isPrime = 0;
				nextPrime++;
				break;
			}
		}
		if (isPrime == 1) {
			return nextPrime;
		}
	}
}
/* Create an empty hash table */
struct hashTable *createHashtable(int allocated) {
	struct hashTable *returnHashTable = NULL;
	int i = 0; 
	if ((returnHashTable = (struct hashTable *)malloc(sizeof(struct hashTable))) == NULL) {
		printf("malloc error\n");
		exit(EXIT_FAILURE);
	}
	returnHashTable->allocated = allocated;
	returnHashTable->used = 0;
	if ((returnHashTable->arrayPtr = (int *)malloc(sizeof(int) * returnHashTable->allocated)) == NULL) {
		printf("malloc error\n");
		exit(EXIT_FAILURE);
	}
	for (i = 0; i < returnHashTable->allocated; i++) {
		returnHashTable->arrayPtr[i] = SENTINEL;
	}
	return returnHashTable;
}
/* Write insert function */
void insert(struct hashTable *hashTable, int data) {
	int newSize, oldSize;
	int *newArray = NULL;
	int *oldArray = NULL;
	int i = 0;
	int nextTry;
	
	if (!hashTable) {
		printf("hash table doesn't exist\n'");
		return;
	}
	
	if (hashTable->used + 1 > hashTable->allocated) {
		hashTable->used = 0;
		
		oldSize = hashTable->allocated;
		newSize = nextPrime(hashTable->allocated);
		newArray = (int *)malloc(sizeof(int) * newSize);
		oldArray = hashTable->arrayPtr;
		
		hashTable->allocated = newSize;
		hashTable->arrayPtr = newArray;
		for (i = 0; i < newSize; i++) {
			hashTable->arrayPtr[i] = SENTINEL;
		}
		for ( i = 0; i < oldSize; i++) {
			if (oldArray[i] != SENTINEL) {
				insert(hashTable, oldArray[i]);	
			}	
		}
		free(oldArray);
	}
	
	nextTry = (data * 97) % hashTable->allocated;
	while(1) {
		if (hashTable->arrayPtr[nextTry] == SENTINEL) {
			hashTable->arrayPtr[nextTry] = data;
			hashTable->used++;
			return;
		} else {
			nextTry = (nextTry + 1) % hashTable->allocated;
		}
	}
}

/* Write printTable function. */
void printTable(struct hashTable *hashTable) {
	int i;
	if (!hashTable) {
		printf("hash table doesn't exist\n");
		return;
	};
	
	for (i = 0; i < hashTable->allocated; i++) {
		if (i == 0) {
			printf("|");
		}
		printf(" %d |", hashTable->arrayPtr[i]);
	}
	printf("\n");
}

/* Write freeTable function. */
void freeTable(struct hashTable *hashTable) {
	free(hashTable->arrayPtr);
	free(hashTable);
}

int main(int argc, char **argv){
    
    int inputs[INPUTSIZE] = {2, 3, 97, 23, 15, 21, 4, 23, 29, 37, 5, 23, 28, 40};
    
    /* Declare table. */
    struct hashTable *hashTable = NULL;
    int i;
    
    /* Create empty table. */
    printf("Created hash table of size 13\n");
    hashTable = createHashtable(STARTSIZE);
    printTable(hashTable);
    
    
	for(i = 0; i < INPUTSIZE; i++){
        printf("Inserting %d\n",inputs[i]);
        insert( hashTable , inputs[i]);
        printTable( hashTable );
    }
    printf("Finished inserting items into table\n");
    printf("the size of table is %d, used %d\n", hashTable->allocated, hashTable->used);
    freeTable(hashTable);
    
    return 0;
}
