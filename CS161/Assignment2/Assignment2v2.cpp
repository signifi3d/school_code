// Written by: Blake Eakin
// Date: 1 July 2018
// Sources: None

#include <iostream>      

using namespace std;

int main()
{
	int year, yearSpan, leapYears, nyDay;
	cout << "Welcome to Blake's New Year's Day Calculator" << endl << "What year? ";
	cin >> year;

	yearSpan = (year - 1900);
	leapYears = (yearSpan-1) / 4;
	nyDay = ((yearSpan * 365 + leapYears) + 1) % 7;

	cout << "New Year's Day " << year << " fell on day " << nyDay << " of the week" << endl << "Thanks for using Blake's New Year's Day Calculator" << endl;

	return 0;
}