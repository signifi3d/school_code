all: supplied.o main.o table.o
	g++ supplied.o main.o table.o -o main

main.o: main.cpp
	g++ -c main.cpp

table.o: table.cpp
	g++ -c table.cpp

clean:
	rm main main.o table.o
