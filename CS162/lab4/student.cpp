#include "student.h"
#include <cstring>

Student::Student(const char initID[], double gpa) {
	strcpy(id, initID);
	this->gpa = gpa;
}

bool Student::isLessThanByID(const Student& aStudent) const {
	for (int i = 0; i < MAX_CHAR; i++) {
		if (this->id[i] < aStudent.id[i]) return true;
		if( this->id[i] == '\0' ) break;
	}
	return false;
}

bool Student::qualifyForHonor(double minGpaForHonor) const {
	if (this->gpa >= minGpaForHonor) return true;
	return false;
}

void Student::print() const
{
	cout << id << '\t' << gpa << endl;
}
