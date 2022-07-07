CC=gcc
FLAGS=-Wall -Wextra -Werror

all: state_sort state_search

state_sort:
	$(CC) $(FLAGS) tate_sort.c struct.c -o ../build/Quest_1

state_search:
	$(CC) $(FLAGS) state_search.c struct.c -o ../build/Quest_2

clean:
	rm ../build/Quest*

rebuild: clean all