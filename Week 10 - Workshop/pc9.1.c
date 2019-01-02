#include "pqueue.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#define UNTRAVERSABLE '#'
#define START 'S'
#define CASTLE 'C'
#define REACHABLE 'R'
#define EMPTY ' '
#define XSIZE 6
#define YSIZE 6

/* Prints the path from the S symbol in the map
    to the C symbol which doesn't ever stop on
    any # symbols. The map given, of size xSize by
    ySize can be modified freely and needn't be
    kept in any way consistent with the original
    map. */
void printPath(char map[XSIZE][YSIZE + 1], int xSize, int ySize);

void printPath(char map[XSIZE][YSIZE + 1], int xSize, int ySize){
    int i, j;
    struct coordinatePair {
        int x;
        int y;
    };
    struct coordinatePair startPair = { .x = -1, .y = -1 };
    
    for(i = 0; i < XSIZE; i++){
        for(j = 0; j < YSIZE; j++){
            if(map[i][j] == START){
                startPair.x = i;
                startPair.y = j;
                /* Could also just let the loops
                    run, but may as well break
                    out of both. */
                break;
            }
        }
        if(startPair.x != -1){
            break;
        }
    }
    /* FILL IN */
	struct coordinatePair *passPair;
	struct coordinatePair *currentPair = NULL;
	struct coordinatePair castlePair = {
		.x = -1,
		.y = -1
	};
	struct coordinatePair movePair;
	
	int xDiff;
	int yDiff;
	int xMult;
	int yMult;
	int priority;
	int k;
	
	struct coordinatePair prev[XSIZE][YSIZE];
	
	struct pqueue *queue = makeQueue();
	
	enqueue(queue, 0, &startPair);
	
	while(!empty(queue)){
		currentPair = (struct coordinatePair *) dequeue(queue);
		if (map[currentPair->x][currentPair->y] == CASTLE) {
			castlePair.x = currentPair->x;
			castlePair.y = currentPair->y;
			
			free(currentPair);
			while(!empty(queue)) {
				currentPair = (struct coordinatePair *) dequeue(queue);
				if(currentPair != &startPair) {
					free(currentPair);
				}
			}
			break;
		}
				
		for (i = 0; i < 2; i++) {
			for(j = 0; j < 2; j++) {
				xDiff = 1 + j%2;
				yDiff = 2 - j%2;
				for (k = 0; k < 4; k++) {
					xMult = (k % 2) * 2 - 1;
					yMult = (k / 2) * 2 - 1;
					if((currentPair->x + xDiff * xMult) < XSIZE &&
						(currentPair->y + yDiff * yMult) < YSIZE &&
						(currentPair->x + xDiff * xMult) >= 0 &&
						(currentPair->y + yDiff * yMult) >= 0 &&
						(map[currentPair->x + xDiff * xMult][currentPair->y + yDiff * yMult] == EMPTY ||
						map[currentPair->x + xDiff * xMult][currentPair->y + yDiff*yMult] == CASTLE)
					) {
						prev[currentPair->x + xDiff * xMult][currentPair->y + yDiff * yMult] = *currentPair;
						passPair = (struct coordinatePair *)malloc(sizeof(struct coordinatePair));
						assert(passPair);
								
						passPair->x = currentPair->x + xDiff * xMult;
						passPair->y = currentPair->y + yDiff * yMult;
								
						if(map[currentPair->x + xDiff * xMult][currentPair->y + yDiff * yMult] == EMPTY) {
							map[currentPair->x + xDiff * xMult][currentPair->y + yDiff * yMult] = REACHABLE;
							enqueue(queue, 1, passPair);
						} else {
							enqueue(queue, -1, passPair);
						}
					}
				}
			}
		}
		if(currentPair != &startPair) {
			free(currentPair);
		}
	}
	if(castlePair.x == -1) {
		printf("No path to castle.\n");
	} else {
		printf("Castle position = %d, %d\n", castlePair.x, castlePair.y);
		movePair = castlePair;
		while(movePair.x != startPair.x || movePair.y != startPair.y) {
			movePair = prev[movePair.x][movePair.y];
			printf("Come from %d, %d\n", movePair.x, movePair.y);
		}
	}
	freeQueue(queue);
}

int main(int argc, char **argv){
    char map[XSIZE][YSIZE + 1] = {
        "     C",
        "  #  #",
        "# # ##",
        "#  # #",
        "# #   ",
        " S    "
    };
    
    printPath(map, XSIZE, YSIZE);
    
    return 0;
}
