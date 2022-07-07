CC= gcc
CFLAGS= -c -Wall -Wextra -Werror
F= -Wall -Wextra -Werror
all: s21_string_test.o s21_string.o
	$(CC) s21_string_test.o s21_string.o -o ../build/all
s21_string_test.o: s21_string_test.c s21_string_test.h s21_string.h
	$(CC) $(CFLAGS) s21_string_test.c s21_string_test.h s21_string.h
s21_string.o:
	$(CC) $(CFLAGS) s21_string.c s21_string.h

strlen_tests: s21_string.c s21_string_test.c
	$(CC) $(F) -D Q1 s21_string.c s21_string_test.c -o ../build/Quest_1
strcmp_tests: s21_string.c s21_string_test.c
	$(CC) $(F) -D Q2 s21_string.c s21_string_test.c -o ../build/Quest_2
strcpy_tests: s21_string.c s21_string_test.c
	$(CC) $(F) -D Q3 s21_string.c s21_string_test.c -o ../build/Quest_3
strcat_tests: s21_string.c s21_string_test.c
	$(CC) $(F) -D Q4 s21_string.c s21_string_test.c -o ../build/Quest_4
strchr_tests: s21_string.c s21_string_test.c
	$(CC) $(F) -D Q5 s21_string.c s21_string_test.c -o ../build/Quest_5


clean:
	rm -rf *.o ../build/Q*

rebuild:
	$(MAKE) clean
	$(MAKE) strlen_tests
