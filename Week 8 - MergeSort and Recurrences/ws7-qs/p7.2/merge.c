/* merge.c */
#include <stdlib.h>
#include <assert.h>
#include <stdio.h>
/* merge two sorted array, first -- mid, mid + 1 -- last */
void merge(int *list, int first, int mid, int last);
void merge(int *list, int first, int mid, int last) {
	int i, j, k;
	int *temp = NULL;
	temp = (int *)malloc(sizeof(int) * (last - first + 1));
	if (!temp) {
		printf("malloc error!\n");
		exit(EXIT_FAILURE);
	} 
	for (i = first, j = mid + 1, k = 0; k < last - first + 1; k++) {
		if (i > mid) {
			temp[k] = list[j++];
			continue;
		}
		if (j > last) {
			temp[k] = list[i++];
			continue;
		}
		if (list[i] < list [j]) {
			temp[k] = list[i++];
		} else {
			temp[k] = list[j++];
		}
	}
	
	/* copy temp array to original array */
	for (i = first, j = 0; i <= last; i++, j++) {
		list[i] = temp[j];
	}
	free(temp);
}

int *mergeSort(int *list, int size){
    int first = 0, mid = 0, last = 0, period = 1;
    while(first + period <= size) {	
    	mid = first + period - 1;
    	if (mid >= size) {
    		mid = size - 1;
		}
    	last = mid + period;
    	if (last >= size) {
    		last = size - 1;
		}
    	merge(list, first, mid, last);
    	//printf("first = %d, mid = %d, last = %d\n", first, mid, last);
    	//printArray(list + first, last - first + 1);
    	first = last + 1;
		if (first >= size) {
    		first = 0;
    		period *=2;
		}
	}
    return list;
}
