/*Project 1
 *Blake Eakin
 *9/24/2018
 *CS 162 Online
 */
#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

enum Origin {US, Europe, Japan}; 

ifstream openCars(char *fileName) {
	
	ifstream fileIn;
	fileIn.open(fileName);

	return fileIn;
}

void originCount(ifstream& carStream) {
	
	char input[100];
	int carCounts[3] = {0};
	
	while (!carStream.eof()) {
		carStream.getline(input, 100);
		if ( strstr(input, "US") ) {
			++carCounts[US];
		} else if ( strstr(input, "Europe") ) {
			++carCounts[Europe];
		} else if ( strstr(input, "Japan") ) {
			++carCounts[Japan];
		}
	}

	cout << "Number of cars from the US: " << carCounts[US] << endl;
	cout << "Number of cars from Europe: " << carCounts[Europe] << endl;
	cout << "Number of cars from Japan: " << carCounts[Japan] << endl;
	
	carStream.clear();
	carStream.seekg(0, ios::beg);

	return;
}

void weightCount(ifstream& carStream) {
	
	char input[100];
	int firstRangeCount=0, secondRangeCount=0, thirdRangeCount=0, fourthRangeCount=0;
	
	while(!carStream.eof()) {
		for (int i = 0; i < 9; i++) {
			if ( i == 8 ) carStream.getline(input, 100);
			else carStream.getline(input, 100, ';');
			if ( i == 5 ) {
				if ( strcmp(input, "1000") > 0 && strcmp(input, "2000") < 0 ) {
					++firstRangeCount;
				} else if ( strcmp(input, "2000") >= 0 && strcmp(input, "3000") < 0 ) {
					++secondRangeCount;
				} else if ( strcmp( input, "3000") >= 0 && strcmp(input, "4000") < 0 ) {
					++thirdRangeCount;
				} else if ( strcmp(input, "4000") >= 0 ) {
					++fourthRangeCount;
				}
			}
		}
	}
	
	cout << "# of cars weighing from 1000 to 2000: " << firstRangeCount << endl;
	cout << "# of cars weighing from 2000 to 3000: " << secondRangeCount << endl;
	cout << "# of cars weighing from 3000 to 4000: " << thirdRangeCount << endl;
	cout << "# of cars weighing greater than 4000: " << fourthRangeCount << endl;

	carStream.clear();
	carStream.seekg(0, ios::beg);

	return;
}

int main() {
char fileName[20] = "cars.txt";
ifstream carFile = openCars(fileName);
originCount(carFile);
weightCount(carFile);

return 0;
}
