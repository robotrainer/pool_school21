CC=gcc
flag=-c -Wall -Wextra -Werror
pt1 =../build/cipher
all: cipher
cipher.o: cipher.c
	$(CC) $(flag) cipher.c

cipher: cipher.o
	$(CC) cipher.o -o $(pt1)