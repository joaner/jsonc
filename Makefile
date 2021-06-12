.PHONY: all test clean

all: compile
compile:
	gcc -Wall -std=c99 src/main.c -o jsonc
test:
	./jsonc test/1.json
clean:
	rm -f jsonc