digraph.o: digraph.c digraph.h
	gcc -Wall -c digraph.c -g

testDigraph.o: testDigraph.c digraph.h
	gcc -Wall -c testDigraph.c -g

testDigraph: digraph.o testDigraph.o
	gcc -Wall -o testDigraph digraph.o testDigraph.o -g