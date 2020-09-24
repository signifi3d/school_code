all: main.o array.o supplied.o
	g++ main.o array.o supplied.o -o main

main.o: main.cpp
	g++ -c main.cpp

array.o: array.cpp
	g++ -c array.cpp

clean: 
	rm *.o main
