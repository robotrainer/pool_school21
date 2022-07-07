CC=gcc
CFLAGS=-Wall -Wextra -Werror
YET=../yet_another_decision_module/
LIBS=../data_libs/
MODULE=../data_module/
BUILD=../../build/

build: main

main: decision.o data_io.o data_stat.o main_executable_module.o data_process.o data_sort.o
	$(CC) $(CFLAG) main_executable_module.o data_io.o data_stat.o decision.o data_sort.o data_process.o -o $(BUILD)Quest_3

build_with_macro: decision.o data_stat.o main_executable_module_macro.o data_process.o data_sort.o
	$(CC) $(CFLAG) main_executable_module.o data_stat.o decision.o data_sort.o data_process.o -o $(BUILD)Quest_4

build_with_static: decision.o data_io.o libdata_stat.a main_executable_module.o data_process.o data_sort.o
	$(CC) $(CFLAG) main_executable_module.o data_io.o decision.o data_sort.o data_process.o -o $(BUILD)Quest_5 -L$(LIBS) -ldata_stat

build_with_dynamic: decision.o data_io.o main_executable_module.o libdata_process.so data_sort.o
	$(CC) $(CFLAG) main_executable_module.o data_io.o decision.o data_sort.o -o $(BUILD)Quest_6 -L$(LIBS) -ldata_process -Wl,-rpath,$(LIBS)

libdata_process.so: $(MODULE)data_process.c $(LIBS)data_stat.c
	$(CC) $(CFLAGS) -c -fPIC $(MODULE)data_process.c
	$(CC) $(CFLAGS) -c -fPIC $(LIBS)data_stat.c
	$(CC) -shared -o $(LIBS)libdata_process.so data_process.o data_stat.o

libdata_stat.a: data_stat.o
	ar r $(LIBS)libdata_stat.a data_stat.o

main_executable_module.o: main_executable_module.c
	$(CC) $(CFLAGS) -c main_executable_module.c

main_executable_module_macro.o: main_executable_module.c
	$(CC) $(CFLAGS) -c -DMACROS main_executable_module.c

decision.o: $(YET)decision.c $(YET)decision.h
	$(CC) $(CFLAGS) -c $(YET)decision.c

data_process.o: $(MODULE)data_process.c $(MODULE)data_process.h
	$(CC) $(CFLAGS) -c $(MODULE)data_process.c

data_sort.o: $(LIBS)data_sort.c $(LIBS)data_sort.h
	$(CC) $(CFLAGS) -c $(LIBS)data_sort.c

data_io.o: $(LIBS)data_io.c $(LIBS)data_io.h
	$(CC) $(CFLAGS) -c $(LIBS)data_io.c

data_stat.o: $(LIBS)data_stat.c $(LIBS)data_stat.h
	$(CC) $(CFLAGS) -c $(LIBS)data_stat.c

clean:
	rm -rf *.o $(BUILD)Quest_3 $(BUILD)Quest_4 $(BUILD)Quest_5 $(BUILD)Quest_6 $(LIBS)*.a $(LIBS)*.so

rebuild: clean build