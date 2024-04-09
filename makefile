all: build

build: src/main.c src/cipher.c src/utils.c
	cd out/; clang -Wall -g -c ../src/main.c ../src/cipher.c ../src/utils.c
	clang -g -Wall -o bin/cciphr out/main.o out/cipher.o out/utils.o

clean: out/cipher.o out/utils.o out/main.o 
	rm out/cipher.o out/utils.o out/main.o
