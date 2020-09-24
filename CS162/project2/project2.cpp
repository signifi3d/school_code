/* CS 162 Online Project 2
 * By: Blake Eakin
 * Date: 10/5/2018
 * 
 * Terminal interface for car database implemented using struct to model car data and
 * an array to hold a list of car data.
 */
#include <iostream>
#include <fstream>
#include <cstring>
#include <iomanip>
#include "utilities.h"


using namespace std;

//Constants and data models
const char *FILEPATH = "cars.txt";

enum Cat { US, Europe, Japan };

struct CarType {
	char carName[50];
	double mpg;
	int cylinders;
	double displacement;
	double horsepower;
	double weight;
	double acceleration;
	int model;
	Cat origin;
};

//Function prototypes
int menuLoop(CarType*&, int);
int enterNewCar(CarType*&, int);
void displayCars(const CarType*, int);
int removeCar(CarType*&, int);
void searchByOrigin(const CarType*, int);
void searchByName(const CarType*, int);
void searchByModel(const CarType*, int);
void updateDatabase(const CarType*, int);
int loadList(CarType*&);


int main() {
	CarType* carList = NULL;
	int listLength = loadList(carList);
	listLength = menuLoop(carList, listLength);
	updateDatabase(carList, listLength);

	return 0;
}

int menuLoop(CarType*& carList, int listLength) {
//Main menu loop, valid input is number of menu item
	char userChoice[20];
	int workingListLength = listLength;

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
			workingListLength = enterNewCar(carList, workingListLength);
		} else if ( !strcmp(userChoice, "2") ) {
			displayCars(carList, workingListLength);
		} else if ( !strcmp(userChoice, "3") ) {
			workingListLength = removeCar(carList, workingListLength);
		} else if ( !strcmp(userChoice, "4") ) {
			searchByOrigin(carList, workingListLength);
		} else if ( !strcmp(userChoice, "5") ) {
			searchByName(carList, workingListLength);
		} else if ( !strcmp(userChoice, "6") ) {
			searchByModel(carList, workingListLength);
		} else if ( !strcmp(userChoice, "7") || !strcmp(userChoice, "q") || !strcmp(userChoice, "quit") || !strcmp(userChoice, "Q") || !strcmp(userChoice, "Quit")) {
			cout << "Thank you for using my car database program." << endl;
			break;
		} else {
			cout << "Invalid input. Please select a menu item by number." << endl;
		}
	}

	return workingListLength;
}

int loadList(CarType*& carList) {
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

	carList = new CarType[lineCount];
	
	for (int i = 0; i < lineCount; i++) {
		dbInFile.get(inBuffer, 100, ';');
		strcpy(carList[i].carName, inBuffer);
		dbInFile.ignore(100,';');
		dbInFile.get(inBuffer, 100, ';');
		carList[i].mpg = cstod(inBuffer);
		dbInFile.ignore(100,';');
		dbInFile.get(inBuffer, 100, ';');
		carList[i].cylinders = cstoi(inBuffer);
		dbInFile.ignore(100,';');
		dbInFile.get(inBuffer, 100, ';');
		carList[i].displacement = cstod(inBuffer);
		dbInFile.ignore(100,';');
		dbInFile.get(inBuffer, 100, ';');
		carList[i].horsepower = cstod(inBuffer);
		dbInFile.ignore(100,';');
		dbInFile.get(inBuffer, 100, ';');
		carList[i].weight = cstod(inBuffer);
		dbInFile.ignore(100,';');
		dbInFile.get(inBuffer, 100, ';');
		carList[i].acceleration = cstod(inBuffer);
		dbInFile.ignore(100,';');
		dbInFile.get(inBuffer, 100, ';');
		carList[i].model = cstoi(inBuffer);
		dbInFile.ignore(100,';');
		dbInFile.get(inBuffer, 100, '\n');
		dbInFile.ignore(100,'\n');
		if ( !strcmp(inBuffer, "US") ) carList[i].origin = US;
		else if ( !strcmp(inBuffer, "Europe") ) carList[i].origin = Europe;
		else if ( !strcmp(inBuffer, "Japan") ) carList[i].origin = Japan;
	}

	dbInFile.close();

	return lineCount;
}

int enterNewCar(CarType*& carList, int listLength) {
//Queries user for data for a new car entry to the database. Adds to end of array. Returns new length of array.
//Each entry has its own dedicated loop to validate each entry's unique input and not have to restart the whole 
//entry upon user input error. Need to find a more elegant solution.
	char inBuffer[50];
	bool inputValidated = 1;
	CarType* newCarList = new CarType[listLength+1];
	for (int i = 0; i < listLength; i++) {
		newCarList[i] = carList[i];
	}

	cout << "Please enter new car's information." << endl;
	do {
		cout << "Car name: ";
		cin.getline(newCarList[listLength].carName, 50);
		flushCin();
		if ( strlen(newCarList[listLength].carName ) == 0 ) {
			cout << "Please enter a name for the new car entry." << endl;
			inputValidated = 0;
		}
		else {
			cstrToUpper(newCarList[listLength].carName);
			inputValidated = 1;
		}
	} while (!inputValidated);
	do {
		double mpgHolder = 0.0;
		cout << "MPG: ";
		cin.getline(inBuffer, 50);
		flushCin();
		try {
			mpgHolder = cstod(inBuffer);
		} catch (...) {
			cout << "Invalid input, please only enter a decimal value." << endl;
			inputValidated = 0;
			continue;
		}
		newCarList[listLength].mpg = mpgHolder;
		inputValidated = 1;
	} while (!inputValidated);
	do {
		int cylHolder = 0;
		cout << "Cylinders: ";
		cin.getline(inBuffer, 50);
		flushCin();
		try {
			cylHolder = cstoi(inBuffer);
		} catch (...) {
			cout << "Invalid input, please only enter an integer value." << endl;
			inputValidated = 0;
			continue;
		}
		newCarList[listLength].cylinders = cylHolder;
		inputValidated = 1;
	} while (!inputValidated);
	do {
		double dispHolder = 0.0;
		cout << "Displacement: ";
		cin.getline(inBuffer, 50);
		flushCin();
		try {
			dispHolder = cstod(inBuffer);
		} catch (...) {
			cout << "Invalid input, please only enter a decimal value." << endl;
			inputValidated = 0;
			continue;
		}
		newCarList[listLength].displacement = dispHolder;
		inputValidated = 1;
	} while (!inputValidated);
	do {
		double horseHolder = 0.0;
		cout << "Horsepower: ";
		cin.getline(inBuffer, 50);
		flushCin();
		try {
			horseHolder = cstod(inBuffer);
		} catch (...) {
			cout << "Invalid input, please only enter a decimal value." << endl;
			inputValidated = 0;
			continue;
		} 
		newCarList[listLength].horsepower = horseHolder;
		inputValidated = 1;
	} while (!inputValidated);
	do {
		double weightHolder = 0.0;
		cout << "Weight: ";
		cin.getline(inBuffer, 50);
		flushCin();
		try {
			weightHolder = cstod(inBuffer);
		} catch (...) { 
			cout << "Invalid input, please only enter a decimal value." << endl;
			inputValidated = 0;
			continue;
		}
		newCarList[listLength].weight = weightHolder;
		inputValidated = 1;
	} while (!inputValidated);
	do {
		double accelHolder = 0.0;
		cout << "Acceleration: ";
		cin.getline(inBuffer, 50);
		flushCin();
		try {
			accelHolder = cstod(inBuffer);
		} catch (...) {
			cout << "Invalid input, please only enter a decimal value." << endl;
			inputValidated = 0;
			continue;
		} 
		newCarList[listLength].acceleration = accelHolder;
		inputValidated = 1;
	} while (!inputValidated);
	do {
		int modelHolder = 0;
		cout << "Model No.: ";
		cin.getline(inBuffer, 50);
		flushCin();
		try {
			modelHolder = cstoi(inBuffer);
		} catch (...) {
			cout << "Invalid input, please only enter an integer value." << endl;
			inputValidated = 0;
			continue;
		}
		newCarList[listLength].model = modelHolder;
		inputValidated = 1;
	} while (!inputValidated);
	do {
		cout << "Origin: ";
		cin.getline(inBuffer, 50);
		flushCin();
		if ( !strcmp(inBuffer, "US" ) ) {
			newCarList[listLength].origin = US;
			inputValidated = 1;
		} else if ( !strcmp(inBuffer, "Europe") ) {
			newCarList[listLength].origin = Europe;
			inputValidated = 1;
		} else if ( !strcmp(inBuffer, "Japan") ) {
			newCarList[listLength].origin = Japan;
			inputValidated = 1;
		} else {
			cout << "Invalid input, please only enter either US, Japan, or Europe." << endl;
			inputValidated = 0;
		}
	} while (!inputValidated);
	
	cout << newCarList[listLength].carName << " has been added to the database. Notice: No changes will be saved to the database until application termination." << endl;
	delete [] carList;
	carList = newCarList;

	return listLength+1;

}

void displayCars(const CarType* carList, int listLength) {
//Loops through the entire length of the list and prints each entry into a formatted table
	char lineBreak[] =  "+-------+--------------------------------------------------+-------------+-----------+--------------+------------+-------------+--------------+-------------+--------+";
	cout << lineBreak << endl;
	cout << "| " << setw(6) << "Index" << "| " << setw(49) << left << "Car Name" << "| " << setw(12) << "MGP" << "| " << setw(10) << "Cylinders" << "| " << setw(13) << "Displacement" << "| " << setw(11) << "Horsepower" << "| " << setw(12) << "Weight" << "| " << setw(13) << "Acceleration" << "| " << setw(12) << "Model" << "| " << setw(7) << "Origin" << "|" << endl;
	cout << lineBreak << endl;
	for (int i = 0; i < listLength; i++) {
		cout << "| " << setw(6) << i << "| " << setw(49) << left << carList[i].carName << "| " << setw(12) << carList[i].mpg << "| " << setw(10) << carList[i].cylinders << "| " << setw(13) << carList[i].displacement << "| " << setw(11) << carList[i].horsepower << "| " << setw(12) << carList[i].weight << "| " << setw(13) << carList[i].acceleration << "| " << setw(12) << carList[i].model << "| ";
		switch (carList[i].origin) {
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
		cout << lineBreak << endl;
		if (i % 25 == 0) {
			cout << "| " << setw(6) << "Index" << "| " << setw(49) << left << "Car Name" << "| " << setw(5) << "MGP" << "| " << setw(10) << "Cylinders" << "| " << setw(13) << "Displacement" << "| " << setw(11) << "Horsepower" << "| " << setw(7) << "Weight" << "| " << setw(13) << "Acceleration" << "| " << setw(6) << "Model" << "| " << setw(7) << "Origin" << "|" << endl;
			cout << lineBreak << endl;
		}
	}
	cout << "There are " << listLength << " cars in the database." << endl << endl;

	return;
}

int removeCar(CarType*& carList, int listLength) {
//Queries the user for the index of the car to remove, creates a new array and copies every entry from
//the old array into the new one except for the index to be removed. Returns new array length.
	CarType* newCarList = new CarType[listLength-1];
	int removalIndex = 0, indexOffset = 0;
	char inBuffer[50];
	while (1) {
		cout << "At what index is the car you want to remove? ";
		cin.getline(inBuffer, 50);
		flushCin();
		try {
			removalIndex = cstoi(inBuffer);
		} catch (...) { 
			cout << "Invalid input, please input an integer between 0 and " << listLength-1 <<"."<<endl;
			continue;
		}
		if (removalIndex >= 0 && removalIndex < listLength) break;
		else {
			cout << "Invalid input, please input an integer between 0 and " << listLength-1 <<"."<<endl;
		}
	}

	for (int i = 0; i < listLength; i++) {
		if (i != removalIndex) {
			newCarList[i-indexOffset] = carList[i];
		}
		else indexOffset = 1;
	}
	
	cout << carList[removalIndex].carName << " has been removed from the database. Notice: No changes will be saved until application termination." << endl;

	delete [] carList;
	carList = newCarList;

	return listLength-1;
}

void searchByOrigin(const CarType* carList, int listLength) {
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

	char lineBreak[] =  "+-------+---------------------------------------+------+-----------+--------------+------------+--------+--------------+-------+--------+";
	cout << lineBreak << endl;
	cout << "| " << setw(6) << "Index" << "| " << setw(38) << left << "Car Name" << "| " << setw(5) << "MGP" << "| " << setw(10) << "Cylinders" << "| " << setw(13) << "Displacement" << "| " << setw(11) << "Horsepower" << "| " << setw(7) << "Weight" << "| " << setw(13) << "Acceleration" << "| " << setw(6) << "Model" << "| " << setw(7) << "Origin" << "|" << endl;
	cout << lineBreak << endl;

	for (int i = 0; i < listLength; i++) {
		if (carList[i].origin == searchTerm) {
			cout << "| " << setw(6) << i << "| " << setw(38) << left << carList[i].carName << "| " << setw(5) << carList[i].mpg << "| " << setw(10) << carList[i].cylinders << "| " << setw(13) << carList[i].displacement << "| " << setw(11) << carList[i].horsepower << "| " << setw(7) << carList[i].weight << "| " << setw(13) << carList[i].acceleration << "| " << setw(6) << carList[i].model << "| ";
			
			switch (carList[i].origin) {
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
			cout << lineBreak << endl;
			++resultCount;
		}
	}
	cout << resultCount << " entries found with origin of " << userInput << endl;

	return;
}

void searchByName(const CarType* carList, int listLength) {
//Queries user for a search term. Nearly any input is accepted. Loops through the car array
//and prints entries that have a car name containing the search term, along with count of 
//matching entries. 
	int resultCount = 0;
	char userInput[50];
	cout << "What car would you like to search for?: ";
	cin.getline(userInput, 50);
	flushCin();
	cstrToUpper(userInput);

	char lineBreak[] =  "+-------+---------------------------------------+------+-----------+--------------+------------+--------+--------------+-------+--------+";
	cout << lineBreak << endl;
	cout << "| " << setw(6) << "Index" << "| " << setw(38) << left << "Car Name" << "| " << setw(5) << "MGP" << "| " << setw(10) << "Cylinders" << "| " << setw(13) << "Displacement" << "| " << setw(11) << "Horsepower" << "| " << setw(7) << "Weight" << "| " << setw(13) << "Acceleration" << "| " << setw(6) << "Model" << "| " << setw(7) << "Origin" << "|" << endl;
	cout << lineBreak << endl;

	for (int i = 0; i < listLength; i++) {
		if (strstr(carList[i].carName, userInput) != NULL) {
			cout << "| " << setw(6) << i << "| " << setw(38) << left << carList[i].carName << "| " << setw(5) << carList[i].mpg << "| " << setw(10) << carList[i].cylinders << "| " << setw(13) << carList[i].displacement << "| " << setw(11) << carList[i].horsepower << "| " << setw(7) << carList[i].weight << "| " << setw(13) << carList[i].acceleration << "| " << setw(6) << carList[i].model << "| ";
			
			switch (carList[i].origin) {
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
			cout << lineBreak << endl;
			++resultCount;
		}
	}
	cout << resultCount << " entries found containing " << userInput << endl;

	return;
}
void searchByModel(const CarType* carList, int listLength) { 
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

	char lineBreak[] =  "+-------+---------------------------------------+------+-----------+--------------+------------+--------+--------------+-------+--------+";
	cout << lineBreak << endl;
	cout << "| " << setw(6) << "Index" << "| " << setw(38) << left << "Car Name" << "| " << setw(5) << "MGP" << "| " << setw(10) << "Cylinders" << "| " << setw(13) << "Displacement" << "| " << setw(11) << "Horsepower" << "| " << setw(7) << "Weight" << "| " << setw(13) << "Acceleration" << "| " << setw(6) << "Model" << "| " << setw(7) << "Origin" << "|" << endl;
	cout << lineBreak << endl;

	for (int i = 0; i < listLength; i++) {
		if (carList[i].model == searchTerm) {
			cout << "| " << setw(6) << i << "| " << setw(38) << left << carList[i].carName << "| " << setw(5) << carList[i].mpg << "| " << setw(10) << carList[i].cylinders << "| " << setw(13) << carList[i].displacement << "| " << setw(11) << carList[i].horsepower << "| " << setw(7) << carList[i].weight << "| " << setw(13) << carList[i].acceleration << "| " << setw(6) << carList[i].model << "| ";
			
			switch (carList[i].origin) {
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
			cout << lineBreak << endl;
			++resultCount;
		}
	}
	cout << resultCount << " entries found with model number of " << searchTerm << endl;

	return;
}

void updateDatabase(const CarType* carList, int listLength) {
//Opens up the car database file and overwrites with the contents of the current car array.
	ofstream updateStream(FILEPATH, ios::trunc);

	for (int i = 0; i < listLength; i++) {
		updateStream << carList[i].carName << ";";
		updateStream << fixed << setprecision(2) << carList[i].mpg << ";";
		updateStream << carList[i].cylinders << ";";
		updateStream << carList[i].displacement << ";";
		updateStream << carList[i].horsepower << ";";
		updateStream << carList[i].weight << ";";
		updateStream << carList[i].acceleration << ";";
		updateStream << carList[i].model << ";";
		if (carList[i].origin == US) updateStream << "US" << endl;
		else if (carList[i].origin == Europe) updateStream << "Europe" << endl;
		else if (carList[i].origin == Japan) updateStream << "Japan" << endl;
		else updateStream << "Unknown" << endl;
	}

	updateStream.close();

	return;
}
