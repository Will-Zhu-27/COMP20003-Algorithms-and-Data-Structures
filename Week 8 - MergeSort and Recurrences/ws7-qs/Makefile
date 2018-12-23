p7.1.o: p7.1.c merge.h ll.h
	gcc -Wall -c p7.1.c -g

ll.o: ll.c ll.h
	gcc -Wall -c ll.c -g

queue.o: queue.c queue.h
	gcc -Wall -c queue.c -g

merge.o: merge.c merge.h queue.h
	gcc -Wall -c merge.c -g

p7.1: p7.1.o ll.o queue.o merge.o
	gcc -Wall -o p7.1 p7.1.o ll.o queue.o merge.o -g