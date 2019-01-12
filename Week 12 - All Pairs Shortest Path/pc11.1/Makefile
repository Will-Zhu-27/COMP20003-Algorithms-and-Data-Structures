fw.o: fw.c adjmatrix.h
	gcc -Wall -c fw.c -g

adjmatrix.o: adjmatrix.c adjmatrix.h
	gcc -Wall -c adjmatrix.c -g

pc11.1.o: pc11.1.c fw.h adjmatrix.h
	gcc -Wall -c pc11.1.c -g

pc11.1: pc11.1.o fw.o adjmatrix.o
	gcc -Wall -o pc11.1 pc11.1.o fw.o adjmatrix.o -g