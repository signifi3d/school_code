CC=g++
SOURCE=app.cpp
FLAGS=-c -Wall

all: app 

app: app.o
	$(CC) app.o -o app

app.o: app.cpp
	$(CC) $(FLAGS) app.cpp

clean:
	rm *.o app 
