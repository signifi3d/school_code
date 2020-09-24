all: main.o list.o supplied.o
	g++ main.o list.o supplied.o -o main

main.o: main.cpp
	g++ -c main.cpp

list.o: list.cpp
	g++ -c list.cpp

clean:
	rm main.o list.o main
