CC := gcc
CFLAGS := -Wall -pedantic -c

all: tests

tests: test.o test2.o
	$(CC) -o build/test build/test.o
	$(CC) -o build/test2 build/test2.o
	rm build/*.o

test.o:
	$(CC) test.c $(CFLAGS)
	mv test.o build

test2.o:
	$(CC) test2.c $(CFLAGS)
	mv test2.o build

clean:
	rm build/*