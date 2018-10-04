CC = gcc
CFLAGS = -std=c99 -Wall -Werror
RM = rm -f

MAINOBJS = ncat.o roman.o

.PHONY: clean

ncat: $(MAINOBJS)
	$(CC) $(CFLAGS) -o ncat $(MAINOBJS)

roman.o: roman.c roman.h
	$(CC) $(CFLAGS) -c -o roman.o roman.c

ncat.o: ncat.c roman.h
	$(CC) $(CFLAGS) -c -o ncat.o ncat.c

clean:
	$(RM) ncat.o roman.o ncat

