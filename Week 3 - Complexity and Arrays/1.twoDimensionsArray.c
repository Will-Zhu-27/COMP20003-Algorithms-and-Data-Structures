#include <stdio.h>
#include <stdlib.h>
int main(int argc, char **argv){
	int i,j;
	int a[10][20];
	int *b[10];
	/* Write code here to use b in the below loops. */
	for(i = 0; i < 10; i++){
		b[i] = (int *)malloc(sizeof(int) * 20);
		for(j = 0; j < 20; j++){
			/* This fills a and b with the numbers 0 -> 199 */
			a[i][j] = i*20 + j;
			b[i][j] = i*20 + j;
		}
	}
	for(i = 0; i < 10; i++){
		for(j = 0; j < 20; j++){
		/* Feel free to modify this to do different things, only prints
		when i == j to give less output, no real significance. */
			if(i == j){
				printf("a[%d][%d] = %d, b[%d][%d] = %d\n",i,j,a[i][j],i,j,b[i][j]);
			}
		}
	}
	/* free b arrays */
	for (i = 0; i< 10; i++) {
		free(b[i]);
	}
	return 0;
}
