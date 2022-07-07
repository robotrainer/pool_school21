TARGET1 = ../build/Quest_1
TARGET2 = ../build/Quest_2
TARGET3 = ../build/Quest_3
INCLUDE = s21_string_test.c s21_string.c

all: $(TARGET1) $(TARGET2)
	
clean:
	rm -rf $(TARGET1) $(TARGET2) *.o
strlen_tests:
	gcc -D STRLEN_TEST $(INCLUDE) -o $(TARGET1)
strcmp_tests:
	gcc -D STRCMP_TEST $(INCLUDE) -o $(TARGET2)
strcpy_tests:
	gcc -D STRCPY_TEST $(INCLUDE) -o $(TARGET3)
