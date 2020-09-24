all: supplied.o list.o main.o
	g++ supplied.o list.o main.o -o main

list.o: list.cpp
	g++ -c list.cpp

main.o: main.cpp
	g++ -c main.cpp

clean:
	rm list.o main.o main
