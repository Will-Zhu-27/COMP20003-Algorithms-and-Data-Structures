//%stdin: "5 4 this 2 is 4 some 7 example 4 text"
//%stdout: "this is some example text"
//%memtotalnoterm: 21
//%memtotal: 26
//%memaux: 40
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
int main(int argc, char **argv){
	int numStrings;
	int nextStringLength;
	int i, j;
	char **strings;
	/* Read number of strings to store. */
	/* Allocate space for the array of strings. */
	/* For each string, get its length, allocate space for it
	and read all the characters into the string.
	Note: Remember, these are standard strings. */
	/* The below prints all words in the array with spaces between them. */
	do{
		printf("type the number of stings you want to store\n");
		//fflush(stdin);
	}while(scanf("%d", &numStrings) != 1 && numStrings > 0);
	
	if ((strings = (char **)calloc(numStrings, sizeof(char *))) == NULL) {
		printf("calloc error!\n");
		return EXIT_FAILURE;
	}
	for (i = 0; i < numStrings; i++) {
		scanf("%d ", &nextStringLength);
		strings[i] = (char *)calloc(nextStringLength + 1, sizeof(char));
		//fflush(stdin);
		for (j = 0; j< nextStringLength; j++) {
			scanf("%c", &strings[i][j]);
		}
	}
	if(numStrings > 0){
		printf("%s",strings[0]);
	}
	for(i = 1; i < numStrings; i++){
		printf(" %s",strings[i]);
	}
	printf("\n");
	
	/* free the memory */
	for (i = 0; i < numStrings; i++) {
		free (strings[i]);
	}
	free (strings);
	return 0;
}
