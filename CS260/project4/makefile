FLAGS=-Wall -g

all: driver.o SiteTree.o Site.o
	g++ ${FLAGS} driver.o SiteTree.o Site.o -o project4

driver.o: driver.cpp
	g++ ${FLAGS} -c driver.cpp

SiteTree.o: SiteTree.cpp
	g++ ${FLAGS} -c SiteTree.cpp

Site.o: Site.cpp
	g++ ${FLAGS} -c Site.cpp

clean:
	rm *.o project4
