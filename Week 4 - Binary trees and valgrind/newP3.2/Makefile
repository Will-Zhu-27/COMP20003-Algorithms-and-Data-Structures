P3.2:P3.2.o bst.o llqueue.o
	gcc -o P3.2 -Wall -g P3.2.o bst.o llqueue.o

P3.2.o:P3.2.c bst.h
	gcc -c P3.2.c -Wall -g

bst.o:bst.c bst.h llqueue.h
	gcc -c bst.c -Wall -g

llqueue.o:llqueue.c llqueue.h
	gcc -c llqueue.c -Wall -g