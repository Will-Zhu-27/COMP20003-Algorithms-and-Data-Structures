fw.o: fw.c adjmatrix.h
	gcc -Wall -c fw.c -g

adjmatrix.o: adjmatrix.c adjmatrix.h
	gcc -Wall -c adjmatrix.c -g

q11.1.o: q11.1.c fw.h adjmatrix.h
	gcc -Wall -c q11.1.c -g

q11.1: q11.1.o fw.o adjmatrix.o
	gcc -Wall -o q11.1 q11.1.o fw.o adjmatrix.o -g