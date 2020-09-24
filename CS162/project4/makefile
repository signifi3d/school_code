CC=g++
SOURCE=project4.cpp utilities.h
FLAGS=-c -g -Wall

all: project4 

project4: project4.o CarList.o CarType.o
	$(CC) project4.o CarList.o CarType.o -o project4

project4.o: $(SOURCE) 
	$(CC) $(FLAGS) $(SOURCE)

CarList.o: CarList.cpp
	$(CC) $(FLAGS) CarList.cpp

CarType.o: CarType.cpp
	$(CC) $(FLAGS) CarType.cpp

clean:
	rm *.o *.gch project4 
