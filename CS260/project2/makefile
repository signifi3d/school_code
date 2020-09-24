all: driver.o WaitManager.o PromotionManager.o ContactList.o PartyQueue.o CustomerContact.o PartyInfo.o ContactDatabase.o
	g++ driver.o WaitManager.o PromotionManager.o ContactList.o CustomerContact.o PartyInfo.o PartyQueue.o ContactDatabase.o -o project2

WaitManager.o: WaitManager.cpp
	g++ -c WaitManager.cpp

PromotionManager.o: PromotionManager.cpp
	g++ -c PromotionManager.cpp

driver.o: driver.cpp
	g++ -c driver.cpp

ContactList.o: ContactList.cpp
	g++ -c ContactList.cpp

PartyQueue.o: PartyQueue.cpp
	g++ -c PartyQueue.cpp

CustomerContact.o: CustomerContact.cpp
	g++ -c CustomerContact.cpp

PartyInfo.o: PartyInfo.cpp
	g++ -c PartyInfo.cpp

ContactDatabase.o: ContactDatabase.cpp
	g++ -c ContactDatabase.cpp

clean:
	rm *.o project2; echo "" > contacts.txt
