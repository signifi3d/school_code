// Written by: Blake Eakin
// Date: 25 June 2018
// Sources: None

#include <iostream>                 
#include <string>      


using namespace std;

int main()
{
	string subject;
	string name;
	string sign;

	cout << "Welcome to Blake Eakin's Crystal Ball!" << endl << "What is your name, please? ";
	cin >> name;
	cout << "Hello, " << name << " my name is Blake." << endl << "What is your astrological sign, " << name << "? ";
	cin >> sign;
	cout << "What subject are you studying, " << name << "? ";
	cin >> subject;
	cout << "Well " << name << ", your horoscope for " << sign << " says you will do very well in " << subject << "this term." << endl << "Good Luck!";

	return 0;
}