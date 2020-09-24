CC=g++
SOURCE=project3.cpp utilities.h
FLAGS=-c -g -Wall

all: project3 

project3: project3.o CarList.o CarType.o
	$(CC) project3.o CarList.o CarType.o -o project3

project3.o: $(SOURCE) 
	$(CC) $(FLAGS) $(SOURCE)

CarList.o: CarList.cpp
	$(CC) $(FLAGS) CarList.cpp

CarType.o: CarType.cpp
	$(CC) $(FLAGS) CarType.cpp

clean:
	rm *.o *.gch project3 
