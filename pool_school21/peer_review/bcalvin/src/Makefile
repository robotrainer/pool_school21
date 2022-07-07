CC = gcc
MAIN = cipher.c logger.c
FLAGS = -Wall -Werror -Wextra
DEL = ../build/Quest_1_2_3 ../build/logging_cipher *.txt

all: loggin_cipher

cipher:
	$(CC) $(FLAGS) $(MAIN) -o ../build/Quest_1_2_3

loggin_cipher:
	$(CC) $(FLAGS) $(MAIN) -o ../build/logging_cipher

clean:
	rm -rf *.o $(DEL)

rebuild:
	$(MAKE) clean
	$(MAKE) all