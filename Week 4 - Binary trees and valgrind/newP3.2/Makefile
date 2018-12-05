P3.2:P3.2.o avl.o llqueue.o
	gcc -o P3.2 -Wall -g P3.2.o avl.o llqueue.o

P3.2.o:P3.2.c avl.h
	gcc -c P3.2.c -Wall -g

avl.o:avl.c avl.h llqueue.h
	gcc -c avl.c -Wall -g

llqueue.o:llqueue.c llqueue.h
	gcc -c llqueue.c -Wall -g