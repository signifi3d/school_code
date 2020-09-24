all: driver.o SiteTable.o TopicList.o Site.o
	g++ -g driver.o SiteTable.o TopicList.o Site.o -o project3

driver.o: driver.cpp
	g++ -g -c driver.cpp

SiteTable.o: SiteTable.cpp
	g++ -g -c SiteTable.cpp

TopicList.o: TopicList.cpp
	g++ -g -c TopicList.cpp

Site.o: Site.cpp
	g++ -g -c Site.cpp

clean:
	rm *.o project3
