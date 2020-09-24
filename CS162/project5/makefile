CC=g++
SOURCE=project5.cpp utilities.h
FLAGS=-c -g -Wall

all: project5 

project5: project5.o CarList.o CarType.o
	$(CC) project5.o CarList.o CarType.o -o project5

project5.o: $(SOURCE) 
	$(CC) $(FLAGS) $(SOURCE)

CarList.o: CarList.cpp
	$(CC) $(FLAGS) CarList.cpp

CarType.o: CarType.cpp
	$(CC) $(FLAGS) CarType.cpp

clean:
	rm *.o *.gch project5 
