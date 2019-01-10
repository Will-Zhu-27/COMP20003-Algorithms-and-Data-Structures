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

/* according to the priority, rearrange the priority queue */
void update(struct priorityQueue *pq);

/* change one data's priority and use update function to rearrange */
void changePriority(struct priorityQueue *pq, void *data, int newPriority);
