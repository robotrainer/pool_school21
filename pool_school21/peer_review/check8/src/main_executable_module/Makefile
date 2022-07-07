CC=gcc
CFLAGS=-c -Wall -Wextra -Werror

all: ../../build/Quest_3

../../build/Quest_3: main_executable_module.o ../yet_another_decision_module/decision.o ../data_libs/data_io.o ../data_libs/data_stat.o ../data_module/data_process.o
	  $(CC) -o ../../build/Quest_3 main_executable_module.o ../yet_another_decision_module/decision.o ../data_libs/data_io.o ../data_libs/data_stat.o ../data_module/data_process.o

main_executable_module.o: main_executable_module.c ../data_libs/data_stat.h ../data_libs/data_io.h ../yet_another_decision_module/decision.h
		$(CC) $(CFLAGS) main_executable_module.c ../data_libs/data_stat.c ../data_libs/data_io.c ../yet_another_decision_module/decision.c

decision.o: ../yet_another_decision_module/decision.h ../yet_another_decision_module/decision.c 
		$(CC) $(CFLAGS) ../yet_another_decision_module/decision.c

data_io.o: ../data_libs/ata_io.h ../data_libs/data_io.c
		$(CC) $(CFLAGS) ../data_libs/data_io.c

data_stat.o: ../data_libs/data_stat.h d../data_libs/ata_stat.c
		$(CC) $(CFLAGS) ../data_libs/data_stat.c

data_process.o: ../data_module/data_process.h ../data_module/data_process.c
		$(CC) $(CFLAGS) ../data_module/data_process.c

rebuild:
		$(MAKE) clean
		$(MAKE) all