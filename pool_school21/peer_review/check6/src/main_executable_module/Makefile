CC=gcc
CFLAGS=-c -Wall -Werror -Wextra
SOURCES=main_executable_module.c ../yet_another_decision_module/decision.c ../data_libs/data_io.c ../data_libs/data_stat.c ../data_module/data_process.c
OBJECTS=$(SOURCES:.c=.o)
EXECUTABLE=../../build/Quest_3

OBJECTS_STAT=main_executable_module.o ../yet_another_decision_module/decision.o ../data_libs/data_io.o ../data_module/data_process.o
EXECUTABLE_STAT=../../build/Quest_5

OBJECTS_DYN=main_executable_module.o decision.o data_io.o
EXECUTABLE_DYN=../../build/Quest_6

SOURCES_MACRO=main_executable_module.c ../yet_another_decision_module/decision.c ../data_libs/data_io_macro.c ../data_libs/data_stat.c ../data_module/data_process.c ../data_libs/data_io.c
EXECUTABLE_MACRO=../../build/Quest_4

all: $(SOURCES) $(EXECUTABLE)
$(EXECUTABLE): $(OBJECTS)
	$(CC) $(OBJECTS) -o $@

.c.o:
	$(CC) $(CFLAGS) $< -o $@


clean:
	rm -f ../*/*.o
	rm -f ../../build/*
	rm -f ../main_executable_module/libdata_process.so
	rm -f ../main_executable_module/libdata_stat.a

rebuild: $(EXECUTABLE)
	make clean
	make all


build_with_macro: $(SOURCES_MACRO)
	$(CC) -D MACRO -c main_executable_module.c ../yet_another_decision_module/decision.c ../data_libs/data_io_macro.c ../data_libs/data_stat.c ../data_module/data_process.c ../data_libs/data_io.c
	$(CC) -D MACRO main_executable_module.o decision.o data_io_macro.o data_stat.o data_process.o data_io.o -o $(EXECUTABLE_MACRO)

build_with_static: $(EXECUTABLE_STAT)

$(EXECUTABLE_STAT): $(OBJECTS)
	make data_stat.a
	rm -f ../data_libs/data_stat.o
	$(CC) -o $(EXECUTABLE_STAT) $(OBJECTS_STAT) -L. -ldata_stat

data_stat.a: $(OBJECTS)
	ar r libdata_stat.a ../data_libs/data_stat.o


build_with_dynamic: $(EXECUTABLE_DYN)

$(EXECUTABLE_DYN):
	gcc -c -fPIC $(SOURCES)
	make data_process.so
	rm -f ../data_module/data_process.o ../data_libs/data_stat.o
	$(CC) -o $(EXECUTABLE_DYN) $(OBJECTS_DYN) -L. -ldata_process -Wl,-rpath,.

data_process.so: $(OBJECTS)
	gcc -shared -o libdata_process.so ../data_module/data_process.o ../data_libs/data_stat.o

