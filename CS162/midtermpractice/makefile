all: main.o array.o supplied.o
	g++ main.o array.o supplied.o

main.o: main.cpp
	g++ -c main.cpp

array.o: array.cpp
	g++ -c array.cpp

clean: Nothing
	rm *.o a.out
