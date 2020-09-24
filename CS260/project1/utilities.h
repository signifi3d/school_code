/* Creator: Blake Eakin
*  Date: 10/2/18
*  
*  These are a few functions I made to overcome some c++ obstacles
*  that come up frequently. 
*/

#include <cstring>
#include <cmath>
#include <limits>
#include <iostream>

int cstoi(char* stringToConvert) {
	
	int convertedInt = 0;

	if ( strlen(stringToConvert) == 0 ) throw "Empty string.";

	for (int i = 0; i < (int)std::strlen(stringToConvert); i++) {
		int intHolder = stringToConvert[i] - 48;
		if (intHolder > 9 || intHolder < 0) throw "Not a valid int.";
		convertedInt += intHolder * std::pow(10, (std::strlen(stringToConvert) - (i+1)));
	}

	return convertedInt;
}

double cstod(char* stringToConvert) {
	double convertedDouble = 0.0;

	int firstLength = std::strcspn(stringToConvert, ".");

	if ( strlen(stringToConvert) == 0 ) throw "Empty string.";

	for (int i = 0; i < (int)std::strlen(stringToConvert); i++) {
		if (i == firstLength) continue;
		
		double doubleHolder = (double)(stringToConvert[i] - 48);
		if(doubleHolder > 9 || doubleHolder < 0) throw "Not a valid double.";
		
		if (i < firstLength) convertedDouble += doubleHolder * std::pow(10, (firstLength - (i+1)));
		else if ( i > firstLength ) convertedDouble += doubleHolder / std::pow(10, i - (firstLength));
	}

	return convertedDouble;
}


void flushCin() {
	if (std::cin.fail()) {
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}
	return;
}

void cstrToUpper(char* toUpper) {
	for (int i = 0;toUpper[i]!='\0';i++) {
		if (toUpper[i] >= 'a' && toUpper[i] <= 'z') {
			toUpper[i] -= 32;
		}
	}	
}
