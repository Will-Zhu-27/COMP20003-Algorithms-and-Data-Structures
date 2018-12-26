p7.2.o: p7.2.c merge.h
	gcc -Wall -c p7.2.c -g

merge.o: merge.c merge.h
	gcc -Wall -c merge.c -g

p7.2: p7.2.o merge.o
	gcc -Wall -o p7.2 p7.2.o merge.o -g