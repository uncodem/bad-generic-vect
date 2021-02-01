CC := gcc
CFLAGS := -Wall -pedantic -c

all: tests

tests: test.o test2.o
	$(CC) -o build/test build/test.o
	$(CC) -o build/test2 build/test2.o
	$(CC) -o build/test3 build/test3.o
	rm build/*.o

test.o: | build
	$(CC) test.c $(CFLAGS)
	mv test.o build

test2.o: | build
	$(CC) test2.c $(CFLAGS)
	mv test2.o build

test3.o: | build
	$(CC) test3.c $(CFLAGS)
	mv test3.o build

build:
	mkdir -p $@

clean: | build
	rm build/*
