SOURCES = $(wildcard *.c)

CC = gcc
CFLAGS = -std=c11 -g -Wall

%.o: %.c %.h
	$(CC) -c $(CFLAGS) $<


main: main.o rio.o server.o
	$(CXX) -pthread -o $@ $^
run: 
	bash start.sh

clean: 
	$(RM) $(wildcard *.exe) $(wildcard *.o)
	rm main
