all: supplied.o main.o dlist.o
	g++ supplied.o main.o dlist.o -o main

main.o: main.cpp
	g++ -c main.cpp

dlist.o: dlist.cpp
	g++ -c dlist.cpp

clean:
	rm main.o dlist.o main
