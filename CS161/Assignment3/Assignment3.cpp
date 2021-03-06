// Written by: Blake Eakin
// Date: 28 June 2018
// Sources: None
// Assignment 3

#include <iostream>                 
#include <iomanip>

using namespace std;

double passengerCalc() {
	double passengerFare = 0.0;
	int intin;

	cout << "How many passengers in your vehicle? (excluding the driver)" << endl << "\t Regular fare adults: ";
	cin >> intin;
	passengerFare += intin * 13.25;
	cout << "\t Senior Citizens or Disabled: ";
	cin >> intin;
	passengerFare += intin * 6.60;
	cout << "\t Youth: ";
	cin >> intin;
	passengerFare += intin * 6.60;

	return passengerFare;
}

int main()
{
	int intin;
	double fare = 0.0;
	char charin;
	cout << "Welcome to Blake Eakin's Fare Calculator" << endl << "Are you driving a vehicle onto the ferry? (y/n): ";
	cin >> charin;
	if (charin == 'y') {
		cout << "How long is your vehicle in feet? ";
		cin >> intin;
		if (intin < 22) {
			cout << "Is the driver a Senior Citizen or Disabled? (y/n): ";
			cin >> charin;
			if (intin < 14 && charin == 'n') {
				fare += 50.90 + passengerCalc();
			}
			else if (intin < 14 && charin == 'y') {
				fare += 44.25 + passengerCalc();
			}
			else if (intin >= 14 && charin == 'n') {
				fare += 63.75 + passengerCalc();
			}
			else if (intin >= 14 && charin == 'y') {
				fare += 57.10 + passengerCalc();
			}

		}
		else if (intin >= 22 && intin < 30) {
			cout << "Is your vehicle over 7 feet, 2 inches in height? (y/n): ";
			cin >> charin;
			if (charin == 'y') {
				fare += 197.10 + passengerCalc();
			}
			else if (charin == 'n') {
				fare += 98.70 + passengerCalc();
			}
			else {
				cout << "Invalid input.";
			}
		}
		else if (intin >= 30 && intin < 40) {
			fare += 263.80 + passengerCalc();
		}
		else {
			cout << "Vehicle size prohibited.";
		}
	}
	else if (charin == 'n') {
		cout << "How many Regular Fare Adults in your group? ";
		cin >> intin;
		fare += intin * 13.25;
		cout << "How many Senior Citizens or Disabled persons in your group? ";
		cin >> intin;
		fare += intin * 6.60;
		cout << "How many Youths in your group? ";
		cin >> intin;
		fare += intin * 6.60;
		cout << "How many bicycles? ";
		cin >> intin;
		fare += intin * 4.00;
	}
	else {
		cout << "Invalid Input";
	}
	cout << setprecision(2) << fixed << "Your total fare is $" << fare << endl;
	cout << "Thank you for using Blake Eakin's Fare Calculator";
	cin >> charin;

	return 0;
}
