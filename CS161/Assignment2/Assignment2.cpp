// Written by: Blake Eakin
// Date: 25 June 2018
// Sources: None

#include <iostream>                 
#include <string>      


using namespace std;

int main()
{
	int year, year_span, days, leap_years, nyDay;
	cout << "Welcome to Blake's New Year's Day Calculator" << endl << "What year? ";
	cin >> year;
	while (year < 1900 or year > 2099) {
		cout << "Please enter a year between 1900 and 2099. ";
		cin >> year;
	}
	year_span = (year - 1900);
	leap_years = year_span / 4;
	days = (year_span * 365 + leap_years) % 7;
	if (days == 6 && year_span % 4 != 0) {
		nyDay = 0;
	}
	else {
		if (year_span % 4 == 0 && year != 1900) {
			nyDay = days;
		}
		else {
			nyDay = days + 1;
		}
	}
	cout << "New Year's Day " << year << " fell on day " << nyDay << " of the week" << endl << "Thanks for using Blake's New Year's Day Calculator";

	return 0;
}