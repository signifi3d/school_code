#include <iostream>
#include "string.h"
using namespace std;

int main()
{
	char ** names;

	names = new char*[10];	

	names[0]=new char[8];
	strcpy(names[0],"charlie");

	names[1]=new char[6];
	strcpy(names[1],"sarah");

	cout << "Name 1: " << names[0] << endl;
	cout << "Name 2: " << names[1] << endl;

	delete [] names[0];
	delete [] names[1];
	delete [] names;

	return 0;
}

