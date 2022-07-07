CC=gcc
CFLAGS=-c -Wall
LDFLAGS=
SOURCES=state_sort.c
OBJECTS=$(SOURCES: .c=.o)
EXECUTABLE= state_sort


state_sort: $(SOURCES) $(EXECUTABLE)

.c.o:
	$(CC) $(CFLAGS) $< -o $a

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

search:
	$(CC) $(LDFLAGS) state_search.c -o state_search
clear:
	$(CC) $(LDFLAGS) clear_state.c -o clear_state