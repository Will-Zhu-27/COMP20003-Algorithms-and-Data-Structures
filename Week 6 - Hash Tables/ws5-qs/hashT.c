/* hashT.c */
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "hashT.h"

struct hashTable {
    int size;
    int used;
    void **data;
    int *(*hash)(void *);
    void (*insert)(struct hashTable *, int *, void *);
    void (*print)(void *);
};

void insertLP(struct hashTable *table, int *key, void *value){
    /* Write this. NOTE: if you have already written insertDH,
        this is one line of code. */
    insertDH(table, key, value, 1);
}

void insertDH5(struct hashTable *table, int *key, void *value){
    /* Write code to calculate the interval from the key and 
        then call insertDH with this value. */
    int interval = *((int *)value) % 5 + 1; 
    insertDH(table, key, value, interval);
}

void insertDH(struct hashTable *table, int *key, void *value, int hash2key){
    /* Write this. */
   int tries = table->size;
   int nextTry = *key;
   while (tries > 0) {
		if(! table->data[nextTry]) {
			table->data[nextTry] = value;
			return;
		} else {
			nextTry = (nextTry + hash2key) % table->size;
		}
		tries--;
   }
    
    
    
}

struct hashTable *create(int tableSize, int *(*hash)(void *), 
    void (*insert)(struct hashTable *, int *, void *), void (*print)(void *)){
    int i;
    struct hashTable *returnTable = (struct hashTable *) malloc(sizeof(struct hashTable));
    assert(returnTable);
    
    returnTable->size = tableSize;
    returnTable->used = 0;
    returnTable->hash = hash;
    returnTable->insert = insert;
    returnTable->print = print;
    returnTable->data = (void **) malloc(sizeof(void *)*tableSize);
    assert(returnTable->data);
    
    /* Set all elements to NULL, so we know which elements
        are used. */
    for(i = 0; i < tableSize; i++){
        (returnTable->data)[i] = NULL;
    }
    
    return returnTable;
}

void insert(struct hashTable *table, void *value){
    int *key;
    key = table->hash(value);
    table->insert(table, key, value);
    free(key);
}

void printTable(struct hashTable *table){
    int i;
    printf("|");
    for(i = 0; i < table->size; i++){
        if(table->data[i]){
            table->print(table->data[i]);
        } else {
            printf(" ");
        }
        printf("|");
    }
    printf("\n");
}

void freeHashTable(struct hashTable *table) {
	free(table->data);
	free(table);
}

