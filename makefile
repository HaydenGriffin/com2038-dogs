CC = g++

INCDIR = include
SRCDIR = src

CFLAGS = -g -Wall -I$(INCDIR)

main: Dog.o main.o
	$(CC) Dog.o main.o -o main

main.o: $(SRCDIR)/main.cpp $(INCDIR)/Dog.h
	$(CC) $(CFLAGS) -c $(SRCDIR)/main.cpp

Dog.o: $(SRCDIR)/Dog.cpp $(INCDIR)/Dog.h
	$(CC) $(CFLAGS) -c $(SRCDIR)/Dog.cpp