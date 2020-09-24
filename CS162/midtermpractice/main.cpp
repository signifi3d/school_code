#include "array.h"
#include <iostream>
using namespace std;

const int CAP = 100;
int main()
{
	int list[CAP];
	int size = 10;
    build(list, size);
    display(list, size);

	std::cout<<numOfEven(list, size);
	insert(list, size, 5, 5);
    display(list, size);
    
    return 0;
}
