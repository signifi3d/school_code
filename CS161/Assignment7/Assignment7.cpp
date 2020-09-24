//Name: Blake Eakin
//Date: 8/10/2018
//Sources: None
//Assignment 7

#include <iostream>
#include <string>

class date {
//date is a class that holds all information and functions relating to a date entered in the format dd mmm yyyy.
//Months must be entered in a three letter format starting with a capital letter, years must be between 1900 and 2099.
//I chose to implement this as a class instead of a struct with separate functions in order to brush up on the concepts
//before CS 162, and because I wanted to make it easiest to modularize each section of the problem in an interrelated way
//so that I didn't have to change stuff all over the place while developing the program, so that I could get away with just
// writing a simple main function to start, build a skeleton of the class, and then just keep plugging in functionality
// without much effect elsewhere.
public:
	date(int inDay, std::string inMonth, int inYear);
	bool isValidDate();
	std::string getDayOfWeek();
	friend std::ostream& operator<<(std::ostream& out, const date& dout);
private:
	int day, year;
	std::string month;
	int daysInMonth;
	int dayOfTheWeek;
	bool leapYear;
	std::string dayOfWeek;
	bool validDate;
	bool checkValidity();
	int calcDaysInMonth(int monthCode);
	int convertMonthCode(std::string monthCode);
	int calcDayOfTheWeek();
	bool isLeapYear();
};


date::date(int inDay, std::string inMonth, int inYear) {
	day = inDay;
	month = inMonth;
	year = inYear;
	leapYear = isLeapYear();
	daysInMonth = calcDaysInMonth(convertMonthCode(month));
	validDate = checkValidity();
	dayOfTheWeek = calcDayOfTheWeek();
}

bool date::isValidDate() {
	return validDate;
}

bool date::checkValidity() {
	//Checks whether the stored date is valid per assignment parameters.
	//Checks the bounds of the years, then checks to make sure -1 wasn't returned for the month input, and then checks to make sure 
	//the day is in the proper bounds for the given month.
	if (year < 1900 || year > 2099 || !daysInMonth || day > daysInMonth || day <= 0) return false;
	else return true;
}

std::string date::getDayOfWeek() {
	//returns a string version of the day of the week from Sunday-Saturday, 0-6 respectively
	//returns Out Of Bounds if outside of that range. This shouldn't be a problem based on 
	//how the other methods that have access to getDayOfTheWeek are constrained.
	if (dayOfTheWeek == 1) return "Monday";
	else if (dayOfTheWeek == 2) return "Tuesday";
	else if (dayOfTheWeek == 3) return "Wednesday";
	else if (dayOfTheWeek == 4) return "Thursday";
	else if (dayOfTheWeek == 5) return "Friday";
	else if (dayOfTheWeek == 6) return "Saturday";
	else if (dayOfTheWeek == 0) return "Sunday";
	else return "Out of Bounds";
}

int date::calcDaysInMonth(int monthCode) {
	//Returns the days in the month for the specified month, passed by number of month in year, 1-12, returns -1 otherwise
	if (monthCode == 1 || monthCode == 3 || monthCode == 5 || monthCode == 7 || monthCode == 8 || monthCode == 10 || monthCode == 12) return 31;
	else if (monthCode == 4 || monthCode == 6 || monthCode == 9 || monthCode == 11) return 30;
	else if (monthCode == 2) {
		if (leapYear) return 29;
		else return 28;
	}
	else return -1;
}

int date::convertMonthCode(std::string monthCode) {
	//Converts three letter month code into number of corresponding month in year 1-12, or returns -1 if invalid code
	if (monthCode == "Jan") {
		return 1;
	}
	else if (monthCode == "Feb") {
		return 2;
	}
	else if (monthCode == "Mar") {
		return 3;
	}
	else if (monthCode == "Apr") {
		return 4;
	}
	else if (monthCode == "May") {
		return 5;
	}
	else if (monthCode == "Jun") {
		return 6;
	}
	else if (monthCode == "Jul") {
		return 7;
	}
	else if (monthCode == "Aug") {
		return 8;
	}
	else if (monthCode == "Sep") {
		return 9;
	}
	else if (monthCode == "Oct") {
		return 10;
	}
	else if (monthCode == "Nov") {
		return 11;
	}
	else if (monthCode == "Dec") {
		return 12;
	}
	else return -1;
}

bool date::isLeapYear() {
	//Typical check to see if a year is a leap year or not, for checking if a day of 29 is valid in a given February
	if (year % 4 != 0) return false;
	if (year % 100 != 0) return true;
	if (year % 400 == 0) return true;
	else return false;
}

int date::calcDayOfTheWeek() {
	//Calculates an integer code for what day of the week the date falls on, based on the knowledge that jan 1 1900 was a monday
	int daysSoFar = day, yearSpan, leapYears, nyDay;
	for (int i = convertMonthCode(month)-1; i > 0; i--) {
		daysSoFar += calcDaysInMonth(i);
	}
	yearSpan = (year - 1900);
	leapYears = (yearSpan - 1) / 4;
	nyDay = ((yearSpan * 365 + leapYears)) % 7;
	return (daysSoFar + nyDay ) % 7;

}

std::ostream& operator<<(std::ostream& out, const date& dout) {
	//This overloaded output stream operator is just to make output implementation a little cleaner
	out << dout.day << " " << dout.month << " " << dout.year;
	return out;
}

int main() {
	int inDay, inYear;
	std::string inMonth;
	date *inDate;

	std::cout << "Welcome to Blake's Weekday Calculator" << std::endl << "What is the date (dd mmm yyyy): ";
	std::cin >> inDay >> inMonth >> inYear;
	inDate = new date(inDay, inMonth, inYear);
	if (inDate->isValidDate()) {
		std::cout << *inDate << " falls on a " << inDate->getDayOfWeek() << std::endl;
	}
	else {
		std::cout << *inDate << " is not a valid date." << std::endl;
	}
	std::cout << "Thank you for using Blake's Weekday Calculator." << std::endl << std::endl;

	return 0;
}