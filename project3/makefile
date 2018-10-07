CC = gcc
CFLAGS =  -DTESTFUNC -std=c99 -g -Wall

OBJS = main.o is_prime.o add.o test.o

.PHONY = clean

./a.out : $(OBJS)
	$(CC) $(CFLAGS) $(OBJS)

main.o : main.c
	$(CC) -c $(CFLAGS) main.c

is_prime.o : is_prime.c is_prime.h
	$(CC) -c $(CFLAGS) is_prime.c

add.oo : add.c add.h
	$(CC) -c $(CFLAGS) add.c

test.o : test.c test.h
	$(CC) -c $(CFLAGS) test.c

clean :
	rm -rf $(OBJS) ./a.out
