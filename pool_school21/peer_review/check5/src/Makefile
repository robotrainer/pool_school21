strlen_test: s21_string.o s21_string_test.o
	gcc -DQuest1 s21_string.c s21_string_test.c -o ../build/Quest1
s21_string.o: s21_string.c
	gcc -c s21_string.c -o s21_string.o 
s21_string_test.o: s21_string_test.c
	gcc -c -DQuest1 s21_string_test.c -o s21_string_test.o

clear:
	rm -rf *.0 
