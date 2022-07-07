CC=gcc
CFLAGS=-Wall -Wextra -Werror
BUILD=../build/

strlen_tests: s21_string.o s21_string_test_strlen.o
	$(CC) $(CFLAGS) s21_string.o s21_string_test.o -o $(BUILD)Quest_1

strcmp_tests: s21_string.o s21_string_test_strcmp.o
	$(CC) $(CFLAGS) s21_string.o s21_string_test.o -o $(BUILD)Quest_2

strcpy_tests: s21_string.o s21_string_test_strcpy.o
	$(CC) $(CFLAGS) s21_string.o s21_string_test.o -o $(BUILD)Quest_3

strcat_tests: s21_string.o s21_string_test_strcat.o
	$(CC) $(CFLAGS) s21_string.o s21_string_test.o -o $(BUILD)Quest_4

strchr_tests: s21_string.o s21_string_test_strchr.o
	$(CC) $(CFLAGS) s21_string.o s21_string_test.o -o $(BUILD)Quest_5

s21_string.o: s21_string.c
	$(CC) $(CFLAGS) s21_string.c -c

s21_string_test_strlen.o: s21_string_test.c
	$(CC) $(CFLAGS) -DSTRLEN s21_string_test.c -c

s21_string_test_strcmp.o: s21_string_test.c
	$(CC) $(CFLAGS) -DSTRCMP s21_string_test.c -c

s21_string_test_strcpy.o: s21_string_test.c
	$(CC) $(CFLAGS) -DSTRCPY s21_string_test.c -c

s21_string_test_strcat.o: s21_string_test.c
	$(CC) $(CFLAGS) -DSTRCAT s21_string_test.c -c

s21_string_test_strchr.o: s21_string_test.c
	$(CC) $(CFLAGS) -DSTRCHR s21_string_test.c -c

clean:
	rm -rf *.o $(BUILD)Quest_1 $(BUILD)Quest_2 $(BUILD)Quest_3 $(BUILD)Quest_4 $(BUILD)Quest_5

rebuild_strlen: clean strlen_tests

rebuild_strcmp: clean strcmp_tests

rebuild_strcpy: clean strcpy_tests

rebuild_strcat: clean strcat_tests

rebuild_strchr: clean strchr_tests