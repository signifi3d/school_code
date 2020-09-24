#include "student.h"

int main()
{
	Student s1("G10", 3.9);
	Student s2("G20", 3.5);

	s1.print();
	s2.print();

	cout << s1.isLessThanByID(s2) << endl;
	cout << s2.isLessThanByID(s1) << endl;
	cout << s2.qualifyForHonor(3.6) << endl;
	cout << s1.qualifyForHonor(3.4) << endl;


	return 0;
}
