all: supplied.o table.o main.o
	g++ supplied.o table.o main.o -o main

table.o: table.cpp
	g++ -c table.cpp

main.o: main.cpp
	g++ -c main.cpp

clean:
	rm table.o main.o main
