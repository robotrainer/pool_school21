CC=gcc
CFLAGS=-Wall -Wextra -Werror
BUILD=../build/

all: cipher

cipher: work_with_file.o cipher.o logger.o
	$(CC) $(CFLAGS) work_with_file.o cipher.o logger.o -o $(BUILD)cipher

loggin_cipher: work_with_file.o cipher.o logger.o
	$(CC) $(CFLAGS) work_with_file.o cipher.o logger.o -o $(BUILD)loggin_cipher

logger.o: logger.c logger.h log_levels.h
	$(CC) $(CFLAGS) logger.c -c

cipher.o: cipher.c
	$(CC) $(CFLAGS) cipher.c -c

work_with_file.o: work_with_file.c work_with_file.h
	$(CC) $(CFLAGS) work_with_file.c -c

clean:
	rm -rf *.o $(BUILD)cipher

rebuild: clean all