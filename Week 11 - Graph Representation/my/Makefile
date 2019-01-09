digraph.o: digraph.c digraph.h
	gcc -Wall -c digraph.c -g

testDigraph.o: testDigraph.c digraph.h
	gcc -Wall -c testDigraph.c -g

testDigraph: digraph.o testDigraph.o
	gcc -Wall -o testDigraph digraph.o testDigraph.o -g

testDijkstra.o: testDijkstra.c priorityQueue.h digraph.h
	gcc -Wall -c testDijkstra.c -g

priorityQueue.o: priorityQueue.c priorityQueue.h
	gcc -Wall -c priorityQueue.c -g

dijkstra.o: dijkstra.c dijkstra.h priorityQueue.h digraph.h
	gcc -Wall -c dijkstra.c -g

testDijkstra: testDijkstra.o  priorityQueue.o digraph.o dijkstra.o
	gcc -Wall -o testDigraph testDijkstra.o  priorityQueue.o digraph.o dijkstra.o -g

testPriorityQueue.o: testPriorityQueue.c priorityQueue.h
	gcc -Wall -c testPriorityQueue.c -g

testPriorityQueue: testPriorityQueue.o priorityQueue.o
	gcc -Wall -o testPriorityQueue testPriorityQueue.o priorityQueue.o -g