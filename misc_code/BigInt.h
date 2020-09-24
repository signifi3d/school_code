#include <iostream>
#ifndef BIGINT_H
#define BIGINT_H
class BigInt {
	
	public:
		BigInt();
		BigInt &operator+( int const &add);
		BigInt &operator=( int const &eq);
		int &operator[](const int &index) const; 
		friend std::ostream &operator<<(std::ostream &out, const BigInt& toOut);
		int placesNum() const;
	private:
		int digits;
		int* numArray;
		void newPlace(int const &toAppend);
		void newPlaces(int const &numOfPlaces);
		void carryover(int const &index);
};
#endif
