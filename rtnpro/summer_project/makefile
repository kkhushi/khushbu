SHELL=/bin/sh
CC=/usr/bin/gcc

CFLAGS=-x c -ansi -c -I/home/student/Desktop/nee/
LIBS=-lm

sp:  sp.o
	$(CC)  -o sp sp.o $(LIBS)
sp.o:  sp.c
	$(CC) $(CFLAGS) sp.c
clean:
	rm -f ./*.o sp

