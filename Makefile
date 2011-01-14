CC=gcc
CFLAGS=-c -Wall
EXECUTABLE=dsh

all: $(EXECUTABLE) 

$(EXECUTABLE): main.o input.o util.o
	$(CC) main.o input.o util.o -o $(EXECUTABLE)

main.o: 
	$(CC) $(CFLAGS) main.c -o main.o

input.o:
	$(CC) $(CFLAGS) input.c -o input.o

util.o:
	$(CC) $(CFLAGS) util.c -o util.o

.PHONY: clean

clean:
	rm *.o

