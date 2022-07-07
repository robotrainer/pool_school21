FLAGS=-Wall -Werror -Wextra

all: cipher

cipher: cipher.c
	gcc $(FLAGS) cipher.c -o ../build/cipher

clean:
	rm -rf *.out ../*txt ../build/cipher

rebuild:
	make clean
	make all
