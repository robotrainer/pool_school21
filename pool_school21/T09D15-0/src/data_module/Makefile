all: main

main: data_module_entry.o data_io.o data_stat.o data_process.o
	gcc -Wall -Wextra -Werror data_module_entry.o data_io.o data_stat.o data_process.o -o main

data_module_entry.o: data_module/data_module_entry.c
	gcc -Wall -Wextra -Werror -c data_module/data_module_entry.c

data_process.o: data_module/data_process.c data_module/data_process.h
	gcc -Wall -Wextra -Werror -c data_module/data_process.c

data_io.o: data_libs/data_io.c data_libs/data_io.h
	gcc -Wall -Wextra -Werror -c data_libs/data_io.c

data_stat.o: data_libs/data_stat.c data_libs/data_stat.h
	gcc -Wall -Wextra -Werror -c data_libs/data_stat.c

clean:
	rm -rf *.o main