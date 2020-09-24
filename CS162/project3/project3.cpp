/* CS 162 Online Project 3
 * By: Blake Eakin
 * Date: 10/15/2018
 * 
 * Terminal interface for car database implemented using classes  to model car data and
 * hold a list of car data.
 */
#include <iostream>
#include <fstream>
#include <cstring>
#include <iomanip>
#include "CarType.h"
#include "CarList.h"
#include "utilities.h"


using namespace std;

//Constants and data models
const char *FILEPATH = "cars.txt";
const char LINEBREAK[] =  "+-------+--------------------------------------------------+-------------+-----------+--------------+------------+-------------+--------------+-------------+--------+";

void printLabels() {
	cout << "| " << setw(6) << "Index" << "| " << setw(49) << left << "Car Name" << "| " << setw(12) << "MGP" << "| " << setw(10) << "Cylinders" << "| " << setw(13) << "Displacement" << "| " << setw(11) << "Horsepower" << "| " << setw(12) << "Weight" << "| " << setw(13) << "Acceleration" << "| " << setw(12) << "Model" << "| " << setw(7) << "Origin" << "|" << endl;
}

//Function prototypes
void menuLoop(CarList*&);
void loadList(CarList*&);
void enterNewCar(CarList*&);
void removeCar(CarList*&);
void displayCars(CarList*);
void updateDatabase(CarList*);
void searchByOrigin(CarList*);
void searchByName(CarList*);
void searchByModel(CarList*);


int main() {
	CarList* dbList = NULL;
	loadList(dbList);
	menuLoop(dbList);
	updateDatabase(dbList);

	return 0;
}


void menuLoop(CarList*& list) {
//Main menu loop, valid input is number of menu item
	char userChoice[20];

	while (1) {
		cout << "What would you like to do?" << endl;
		cout << "1. Input a new car." << endl;
		cout << "2. Display all car entries." << endl;
		cout << "3. Remove a car" << endl;
		cout << "4. Search for a car by its origin." << endl;
		cout << "5. Search for a car by name." << endl;
		cout << "6. Search for a car by model." << endl;
		cout << "7. Quit." << endl;
		cout << "Please enter a menu item number: ";
		cin.getline(userChoice, 20);
		flushCin();
		if ( !strcmp(userChoice, "1" ) ) {
			enterNewCar(list);
		} else if ( !strcmp(userChoice, "2") ) {
			displayCars(list);
		} else if ( !strcmp(userChoice, "3") ) {
			removeCar(list);
		} else if ( !strcmp(userChoice, "4") ) {
			searchByOrigin(list);
		} else if ( !strcmp(userChoice, "5") ) {
			searchByName(list);
		} else if ( !strcmp(userChoice, "6") ) {
			searchByModel(list);
		} else if ( !strcmp(userChoice, "7") || !strcmp(userChoice, "q") || !strcmp(userChoice, "quit") || !strcmp(userChoice, "Q") || !strcmp(userChoice, "Quit")) {
			cout << "Thank you for using my car database program." << endl;
			break;
		} else {
			cout << "Invalid input. Please select a menu item by number." << endl;
		}
	}

	return;
}

void loadList(CarList*& list) {
//Initializes list of car data entries from the database file. Returns number of entries.
	ifstream dbInFile;
	dbInFile.open(FILEPATH);
	
	int lineCount = 0;
	char inBuffer[500];
	while ( dbInFile.getline(inBuffer, 500, '\n') ) {
		lineCount++;
	}
	
	dbInFile.clear();
	dbInFile.seekg(0, ios::beg);

	list = new CarList();
	
	for (int i = 0; i < lineCount; i++) {
		CarType* currCar = new CarType(); 
		dbInFile.get(inBuffer, 100, ';');
		currCar->setName(inBuffer);
		dbInFile.ignore(100,';');
		dbInFile.get(inBuffer, 100, ';');
		currCar->setMPG(cstod(inBuffer));
		dbInFile.ignore(100,';');
		dbInFile.get(inBuffer, 100, ';');
		currCar->setCylinders(cstoi(inBuffer));
		dbInFile.ignore(100,';');
		dbInFile.get(inBuffer, 100, ';');
		currCar->setDisplacement(cstod(inBuffer));
		dbInFile.ignore(100,';');
		dbInFile.get(inBuffer, 100, ';');
		currCar->setHorsepower(cstod(inBuffer));
		dbInFile.ignore(100,';');
		dbInFile.get(inBuffer, 100, ';');
		currCar->setWeight(cstod(inBuffer));
		dbInFile.ignore(100,';');
		dbInFile.get(inBuffer, 100, ';');
		currCar->setAcceleration(cstod(inBuffer));
		dbInFile.ignore(100,';');
		dbInFile.get(inBuffer, 100, ';');
		currCar->setModel(cstoi(inBuffer));
		dbInFile.ignore(100,';');
		dbInFile.get(inBuffer, 100, '\n');
		dbInFile.ignore(100,'\n');
		if ( !strcmp(inBuffer, "US") ) currCar->setOrigin(US);
		else if ( !strcmp(inBuffer, "Europe") ) currCar->setOrigin(Europe);
		else if ( !strcmp(inBuffer, "Japan") ) currCar->setOrigin(Japan);
		list->addCar(*currCar);
	}

	dbInFile.close();

	return;
}

void enterNewCar(CarList*& list) {
//Queries user for data for a new car entry to the database. Adds to end of array. Returns new length of array.
//Each entry has its own dedicated loop to validate each entry's unique input and not have to restart the whole 
//entry upon user input error. Need to find a more elegant solution.
	char inBuffer[50];
	bool inputValidated = 1;
	CarType* newCar = new CarType();
	cout << "Please enter new car's information." << endl;
	do {
		cout << "Car name: ";
		cin.getline(inBuffer, 50);
		flushCin();
		if ( strlen(inBuffer) == 0 ) {
			cout << "Please enter a name for the new car entry." << endl;
			inputValidated = 0;
		}
		else {
			cstrToUpper(inBuffer);
			newCar->setName(inBuffer);
			inputValidated = 1;
		}
	} while (!inputValidated);
	do {
		cout << "MPG: ";
		cin.getline(inBuffer, 50);
		flushCin();
		try {
			newCar->setMPG(cstod(inBuffer));
		} catch (...) {
			cout << "Invalid input, please only enter a decimal value." << endl;
			inputValidated = 0;
			continue;
		}
		inputValidated = 1;
	} while (!inputValidated);
	do {
		cout << "Cylinders: ";
		cin.getline(inBuffer, 50);
		flushCin();
		try {
			newCar->setCylinders(cstoi(inBuffer));
		} catch (...) {
			cout << "Invalid input, please only enter an integer value." << endl;
			inputValidated = 0;
			continue;
		}
		inputValidated = 1;
	} while (!inputValidated);
	do {
		cout << "Displacement: ";
		cin.getline(inBuffer, 50);
		flushCin();
		try {
			newCar->setDisplacement(cstod(inBuffer));
		} catch (...) {
			cout << "Invalid input, please only enter a decimal value." << endl;
			inputValidated = 0;
			continue;
		}
		inputValidated = 1;
	} while (!inputValidated);
	do {
		cout << "Horsepower: ";
		cin.getline(inBuffer, 50);
		flushCin();
		try {
			newCar->setHorsepower(cstod(inBuffer));
		} catch (...) {
			cout << "Invalid input, please only enter a decimal value." << endl;
			inputValidated = 0;
			continue;
		} 
		inputValidated = 1;
	} while (!inputValidated);
	do {
		cout << "Weight: ";
		cin.getline(inBuffer, 50);
		flushCin();
		try {
			newCar->setWeight(cstod(inBuffer));
		} catch (...) { 
			cout << "Invalid input, please only enter a decimal value." << endl;
			inputValidated = 0;
			continue;
		}
		inputValidated = 1;
	} while (!inputValidated);
	do {
		cout << "Acceleration: ";
		cin.getline(inBuffer, 50);
		flushCin();
		try {
			newCar->setAcceleration(cstod(inBuffer));
		} catch (...) {
			cout << "Invalid input, please only enter a decimal value." << endl;
			inputValidated = 0;
			continue;
		} 
		inputValidated = 1;
	} while (!inputValidated);
	do {
		cout << "Model: ";
		cin.getline(inBuffer, 50);
		flushCin();
		try {
			newCar->setModel(cstoi(inBuffer));
		} catch (...) {
			cout << "Invalid input, please only enter an integer value." << endl;
			inputValidated = 0;
			continue;
		}
		inputValidated = 1;
	} while (!inputValidated);
	do {
		cout << "Origin: ";
		cin.getline(inBuffer, 50);
		flushCin();
		if ( !strcmp(inBuffer, "US" ) ) {
			newCar->setOrigin(US);
			inputValidated = 1;
		} else if ( !strcmp(inBuffer, "Europe") ) {
			newCar->setOrigin(Europe);
			inputValidated = 1;
		} else if ( !strcmp(inBuffer, "Japan") ) {
			newCar->setOrigin(Japan);
			inputValidated = 1;
		} else {
			cout << "Invalid input, please only enter either US, Japan, or Europe." << endl;
			inputValidated = 0;
		}
	} while (!inputValidated);
	
	list->addCar(*newCar);

	cout << newCar->getName() << " has been added to the database. Notice: No changes will be saved to the database until application termination." << endl;

	return;

}


void displayCars(CarList* list) {
//Loops through the entire length of the list and prints each entry into a formatted table
	cout << LINEBREAK << endl;
	printLabels();
	cout << LINEBREAK << endl;
	for (int i = 0; i < list->getSize(); i++) {
		CarType currCar = list->getCarAt(i);
		cout << "| " << setw(6) << i << "| " << setw(49) << left << currCar.getName() << "| " << setw(12) << currCar.getMPG() << "| " << setw(10) << currCar.getCylinders() << "| " << setw(13) << currCar.getDisplacement() << "| " << setw(11) << currCar.getHorsepower() << "| " << setw(12) << currCar.getWeight() << "| " << setw(13) << currCar.getAcceleration() << "| " << setw(12) << currCar.getModel() << "| ";
		switch (currCar.getOrigin()) {
			case 0:
				cout << setw(7) << "US" << "|" << endl;
				break;
			case 1:
				cout << setw(7) << "Europe" << "|" << endl;
				break;
			case 2:
				cout << setw(7) << "Japan" << "|" << endl;
				break;
			default:
				cout << setw(7) << "Unknown" << "|" << endl; 
		}
		cout << LINEBREAK << endl;
		if (i % 25 == 0 && i > 20) {
			printLabels();
			cout << LINEBREAK << endl;
		}
	}
	cout << "There are " << list->getSize() << " cars in the database." << endl << endl;

	return;
}

void removeCar(CarList*& list) {
	int removalIndex = 0;
	char inBuffer[50];
	while (1) {
		cout << "At what index is the car you want to remove? ";
		cin.getline(inBuffer, 50);
		flushCin();
		try {
			removalIndex = cstoi(inBuffer);
		} catch (...) { 
			cout << "Invalid input, please input an integer between 0 and " << list->getSize()-1 <<"."<<endl;
			continue;
		}
		if (removalIndex >= 0 && removalIndex < list->getSize()) break;
		else {
			cout << "Invalid input, please input an integer between 0 and " << list->getSize()-1 <<"."<<endl;
		}
	}
	
	strcpy(inBuffer, list->getCarAt(removalIndex).getName());
	list->removeCarAt(removalIndex);
	
	cout << inBuffer << " has been removed from the database. Notice: No changes will be saved until application termination." << endl;

	return;
}

void searchByOrigin(CarList* list) {
//Queries user for an origin to search for, constrained to only one of the three
//valid options. Loops through the length of the car array and outputs only the
//entries that match the search term.
	int resultCount = 0;
	Cat searchTerm;
	char userInput[20];
	
	do {
		cout << "Which origin would you like to search for? (US, Japan, Europe): ";
		cin.getline(userInput, 20);
		flushCin();
		if ( !strcmp(userInput, "US") ) {
			searchTerm = US;
			break;
		} else if ( !strcmp(userInput, "Japan") ) {
			searchTerm = Japan;
			break;
		} else if ( !strcmp(userInput, "Europe") ) {
			searchTerm = Europe;
			break;
		} else {
			cout << "Invalid input, please only enter US, Japan, or Europe" << endl;
		}
	} while(1);

	cout << LINEBREAK << endl;
	printLabels();
	cout << LINEBREAK << endl;

	for (int i = 0; i < list->getSize(); i++) {
		CarType currCar = list->getCarAt(i);
		if (currCar.getOrigin() == searchTerm) {
			cout << "| " << setw(6) << i << "| " << setw(49) << left << currCar.getName() << "| " << setw(12) << currCar.getMPG() << "| " << setw(10) << currCar.getCylinders() << "| " << setw(13) << currCar.getDisplacement() << "| " << setw(11) << currCar.getHorsepower() << "| " << setw(12) << currCar.getWeight() << "| " << setw(13) << currCar.getAcceleration() << "| " << setw(12) << currCar.getModel() << "| ";
			
			switch (currCar.getOrigin()) {
				case 0:
					cout << setw(7) << "US" << "|" << endl;
					break;
				case 1:	
					cout << setw(7) << "Europe" << "|" << endl;
					break;
				case 2:
					cout << setw(7) << "Japan" << "|" << endl;
					break;
				default:
					cout << setw(7) << "Unknown" << "|" << endl; 
			}
			cout << LINEBREAK << endl;
			++resultCount;
			if (resultCount % 25 == 0) {
				printLabels();
				cout << LINEBREAK << endl;
			}
		}
	}
	cout << resultCount << " entries found with origin of " << userInput << endl;

	return;
}

void searchByName(CarList* list) {
//Queries user for a search term. Nearly any input is accepted. Loops through the car array
//and prints entries that have a car name containing the search term, along with count of 
//matching entries. 
	int resultCount = 0;
	char userInput[50];
	cout << "What car would you like to search for?: ";
	cin.getline(userInput, 50);
	flushCin();
	cstrToUpper(userInput);

	cout << LINEBREAK << endl;
	printLabels();
	cout << LINEBREAK << endl;

	for (int i = 0; i < list->getSize(); i++) {
		CarType currCar = list->getCarAt(i);
		if (strstr(currCar.getName(), userInput) != NULL) {
			cout << "| " << setw(6) << i << "| " << setw(49) << left << currCar.getName() << "| " << setw(12) << currCar.getMPG() << "| " << setw(10) << currCar.getCylinders() << "| " << setw(13) << currCar.getDisplacement() << "| " << setw(11) << currCar.getHorsepower() << "| " << setw(12) << currCar.getWeight() << "| " << setw(13) << currCar.getAcceleration() << "| " << setw(12) << currCar.getModel() << "| ";
			
			switch (currCar.getOrigin()) {
				case 0:
					cout << setw(7) << "US" << "|" << endl;
					break;
				case 1:	
					cout << setw(7) << "Europe" << "|" << endl;
					break;
				case 2:
					cout << setw(7) << "Japan" << "|" << endl;
					break;
				default:
					cout << setw(7) << "Unknown" << "|" << endl; 
			}
			cout << LINEBREAK << endl;
			++resultCount;
			if (resultCount % 25 == 0) {
				printLabels();
				cout << LINEBREAK << endl;
			}
		}
	}
	cout << resultCount << " entries found containing " << userInput << endl;

	return;
}
void searchByModel(CarList* list) { 
	int resultCount = 0;
	int searchTerm;
	char userInput[20];
	
	do {
		cout << "Which model would you like to search for? (Positive integers only): ";
		try {
			cin.getline(userInput, 20, '\n');
			searchTerm = cstoi(userInput);
		}
		catch (...) {
			cout << "Invalid input, please only enter positive integers." << endl;
			flushCin();
			continue;
		}
		break;
	} while(1);

	cout << LINEBREAK << endl;
	printLabels();
	cout << LINEBREAK << endl;

	for (int i = 0; i < list->getSize(); i++) {
		CarType currCar = list->getCarAt(i);
		if (currCar.getModel() == searchTerm) {
			cout << "| " << setw(6) << i << "| " << setw(49) << left << currCar.getName() << "| " << setw(12) << currCar.getMPG() << "| " << setw(10) << currCar.getCylinders() << "| " << setw(13) << currCar.getDisplacement() << "| " << setw(11) << currCar.getHorsepower() << "| " << setw(12) << currCar.getWeight() << "| " << setw(13) << currCar.getAcceleration() << "| " << setw(12) << currCar.getModel() << "| ";
			
			switch (currCar.getOrigin()) {
				case 0:
					cout << setw(7) << "US" << "|" << endl;
					break;
				case 1:	
					cout << setw(7) << "Europe" << "|" << endl;
					break;
				case 2:
					cout << setw(7) << "Japan" << "|" << endl;
					break;
				default:
					cout << setw(7) << "Unknown" << "|" << endl; 
			}
			cout << LINEBREAK << endl;
			++resultCount;
			if (resultCount % 25 == 0) {
				printLabels();
				cout << LINEBREAK << endl;
			}
		}
	}
	cout << resultCount << " entries found with model number of " << searchTerm << endl;

	return;
}

void updateDatabase(CarList* list) {
//Opens up the car database file and overwrites with the contents of the current car array.
	ofstream updateStream(FILEPATH, ios::trunc);

	for (int i = 0; i < list->getSize(); i++) {
		CarType currCar = list->getCarAt(i);
		updateStream << currCar.getName() << ";";
		updateStream << fixed << setprecision(2) << currCar.getMPG() << ";";
		updateStream << currCar.getCylinders() << ";";
		updateStream << currCar.getDisplacement() << ";";
		updateStream << currCar.getHorsepower() << ";";
		updateStream << currCar.getWeight() << ";";
		updateStream << currCar.getAcceleration() << ";";
		updateStream << currCar.getModel() << ";";
		switch(currCar.getOrigin()) {
			case 0:
				updateStream << "US" << endl;
				break;
			case 1:
				updateStream << "Europe" << endl;
				break;
			case 2:
				updateStream << "Japan" << endl;
				break;
			default:
				updateStream << "Unknown" << endl;
		}
	}

	updateStream.close();

	return;
}
