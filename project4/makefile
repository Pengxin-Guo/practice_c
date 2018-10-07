CC = gcc
CFLAGS = -I./thirdpart/include -DTESTFUNC -std=c99 -g -Wall
OBJS = main.o is_prime.o add.o binary_search.o func_binary.o newton.o func_newton.o palindrome_number.o

.PHONY : clean

./a.out : $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) thirdpart/libs/libtest.a

main.o : main.c
	$(CC) -c $(CFLAGS) main.c

is_prime.o : is_prime.c is_prime.h
	$(CC) -c $(CFLAGS) is_prime.c

add.o : add.c add.h
	$(CC) -c $(CFLAGS) add.c

binary_search.o : binary_search.c binary_search.h
	$(CC) -c $(CFLAGS) binary_search.c

func_binary.o : func_binary.c func_binary.h
	$(CC) -c $(CFLAGS) func_binary.c

newton.o : newton.c newton.h
	$(CC) -c $(CFLAGS) newton.c

func_newton.o : func_newton.c func_newton.h
	$(CC) -c $(CFLAGS) func_newton.c

palindrome_number.o : palindrome_number.c palindrome_number.h
	$(CC) -c $(CFLAGS) palindrome_number.c

clean :
	rm -rf *.o a.out
