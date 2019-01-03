p10.1.o: p10.1.c digraph.h dijkstra.h
	gcc -Wall -c p10.1.c -g

digraph.o: digraph.c digraph.h
	gcc -Wall -c digraph.c -g

dijkstra.o: dijkstra.c dijkstra.h digraph.h pqueue.h
	gcc -Wall -c dijkstra.c -g

pqueue.o: pqueue.c pqueue.h
	gcc -Wall -c pqueue.c -g

p10.1: p10.1.o digraph.o dijkstra.o pqueue.o
	gcc -Wall -o p10.1 p10.1.o digraph.o dijkstra.o pqueue.o -g

