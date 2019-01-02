pqueue.o: pqueue.c pqueue.h
	gcc -Wall -c pqueue.c -g

p9.1.o: p9.1.c pqueue.h
	gcc -Wall -c p9.1.c -g

p9.1: p9.1.o pqueue.o
	gcc -Wall -o p9.1 p9.1.o pqueue.o -g

pc9.1.o: pc9.1.c pqueue.h
	gcc -Wall -c pc9.1.c -g

pc9.1: pc9.1.o pqueue.o
	gcc -Wall -o pc9.1 pc9.1.o pqueue.o -g
