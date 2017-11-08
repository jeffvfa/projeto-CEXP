CC=gcc
CFLAGS=-I.
DEPS = graph.h
OBJ = graph.o main.o 

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

graph: $(OBJ)
	gcc -o $@ $^ $(CFLAGS)