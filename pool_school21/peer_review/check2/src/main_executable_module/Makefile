all: ../../build/Quest_3

../../build/Quest_3: main_executable_module.o data_sort.o data_process.o decision.o data_io.o data_stat.o
	gcc main_executable_module.o data_sort.o data_process.o decision.o data_io.o data_stat.o -o ../../build/Quest_3

main_executable_module.o: main_executable_module.c ../data_libs/data_io.h ../data_module/data_process.h data_sort.h ../yet_another_decision_module/decision.h
	gcc -c main_executable_module.c

data_sort.o: data_sort.c data_sort.h
	gcc -c data_sort.c

data_process.o: ../data_module/data_process.c ../data_module/data_process.h ../data_libs/data_stat.h
	gcc -c ../data_module/data_process.c

decision.o: ../yet_another_decision_module/decision.c ../yet_another_decision_module/decision.h ../data_libs/data_stat.h
	gcc -c ../yet_another_decision_module/decision.c

data_io.o: ../data_libs/data_io.c ../data_libs/data_io.h
	gcc -c ../data_libs/data_io.c

data_stat.o: ../data_libs/data_stat.c ../data_libs/data_stat.h
	gcc -c ../data_libs/data_stat.c

clean:
	rm -rf *.o ../../build/Quest_3

rebuild: clean all
