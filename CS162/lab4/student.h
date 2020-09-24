#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
using namespace std;

class Student
{
public:
	Student(const char initId[], double gpa);
	bool isLessThanByID(const Student& aStudent) const;
	bool qualifyForHonor(double minGpaForHonor) const;
	void print()const;
private:
	const static int MAX_CHAR = 100;
	char 	id[MAX_CHAR];
	double	gpa;
};
#endif
