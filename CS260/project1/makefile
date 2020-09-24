FLAGS=-g -Wall
all: driver.o ArtistCatalog.o ArtistRecord.o SongRecord.o
	g++ $(FLAGS) driver.o ArtistCatalog.o ArtistRecord.o SongRecord.o -o project1

driver.o: driver.cpp
	g++ -c $(FLAGS) driver.cpp

ArtistCatalog.o: ArtistCatalog.cpp
	g++ -c $(FLAGS) ArtistCatalog.cpp

ArtistRecord.o: ArtistRecord.cpp
	g++ -c $(FLAGS) ArtistRecord.cpp

SongRecord.o: SongRecord.cpp
	g++ -c $(FLAGS) SongRecord.cpp

clean:
	rm project1 *.o
