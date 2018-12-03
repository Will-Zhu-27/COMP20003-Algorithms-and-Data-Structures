P3.1:P3.1.o bst.o llqueue.o
	gcc -Wall -o P3.1 P3.1.o bst.o llqueue.o -g
	
P3.1.o:P3.1.c bst.h
	gcc -Wall -c P3.1.c -g
	
bst.o:bst.c bst.h llqueue.h
	gcc -Wall -c bst.c -g

llqueue.o:llqueue.c llqueue.h
	gcc -Wall -c llqueue.c -g
