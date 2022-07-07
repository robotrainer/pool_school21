all: state_sort state_search clear_state

state_sort: state_sort.o
	gcc state_sort.o  -o ../build/Quest_1
state_sort.o: state_sort.c
	gcc -c state_sort.c
state_search: state_search.o
	gcc state_search.o  -o ../build/Quest_2
state_search.o: state_search.c
	gcc -c state_search.c
clear_state: clear_state.o
	gcc clear_state.o  -o ../build/Quest_3
clear_state.o: clear_state.c
	gcc -c clear_state.c
rebuild: clean_all all

clean_all: clean_o clean_exe clean_txt

clean_txt:
	rm -rf *.txt
clean_o:
	rm -rf *.o
clean_exe:
	rm -rf ../build/*