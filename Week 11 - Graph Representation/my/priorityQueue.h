/* priorityQueue.h */
struct priorityQueue {
	void **dataList;
	int *priority;
	int capacity;
};


struct priorityQueue *makePriorityQueue();

void enqueue(struct priorityQueue *pq, void *data, int priority);

void *dequeue(struct priorityQueue *pq);

int empty(struct priorityQueue *pq);

void freeQueue(struct priorityQueue *pq);

