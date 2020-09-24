CC=g++
SOURCE=project2.cpp utilities.h
FLAGS=-c -g -Wall

all: project2 

project2: project2.o
	$(CC) project2.o -o project2

project2.o: $(SOURCE) 
	$(CC) $(FLAGS) $(SOURCE)

clean:
	rm *.o *.gch project2 
