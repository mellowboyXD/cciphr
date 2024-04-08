build: src/main.c src/cipher.c src/utils.c
	clang -o ./out/cciphr.out ./src/main.c ./src/cipher.c ./src/utils.c 

clean: out/cciphr.out 
	rm ./out/cciphr.out
