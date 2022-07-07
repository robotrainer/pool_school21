CC=gcc
CFLAGS=-c -Wall -Wextra -Werror
YET=yet_another_decision_module/
LIBS=data_libs/

all: main

main: yet_another_decision_module_entry.o decision.o data_io.o data_stat.o decision.o
	$(CC) -Wall -Wextra -Werror yet_another_decision_module_entry.o data_io.o data_stat.o decision.o -o main

yet_another_decision_module_entry.o: $(YET)yet_another_decision_module_entry.c
	$(CC) $(CFLAGS) $(YET)yet_another_decision_module_entry.c

decision.o: $(YET)decision.c $(YET)decision.h
	$(CC) $(CFLAGS) $(YET)decision.c

data_io.o: $(LIBS)data_io.c $(LIBS)data_io.h
	$(CC) $(CFLAGS) $(LIBS)data_io.c

data_stat.o: $(LIBS)data_stat.c $(LIBS)data_stat.h
	$(CC) $(CFLAGS) $(LIBS)data_stat.c

clean:
	rm -rf *.o main