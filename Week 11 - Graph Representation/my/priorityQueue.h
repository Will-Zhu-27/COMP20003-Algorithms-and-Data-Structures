/* priorityQueue.h */
struct priorityQueue {
	void **dataList;
	int *priority;
	int capacity;
};


struct priorityQueue *makePriorityQueue();

/* enqueue one item into an already-formed heap and put it in right location */
void enqueue(struct priorityQueue *pq, void *data, int priority);

/* just insert it into the tail of priority queue 
	after all items are inserted, use heapSort */
void directEnqueue (struct priorityQueue *pq, void *data, int priority);

void *dequeue(struct priorityQueue *pq);

int empty(struct priorityQueue *pq);

void freeQueue(struct priorityQueue *pq);

/* sort the datalist in pq according to the priority */
void heapSort(struct priorityQueue *pq);

/* change one data's priority and use update function to rearrange */
int changePriority(struct priorityQueue *pq, void *data, int newPriority);

void printDatalistAddress(struct priorityQueue *pq);
