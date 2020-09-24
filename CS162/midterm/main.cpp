#include "array.h"
using namespace std;

const int CAP = 100;
int main()
{
	int list[CAP];
	int size = 10;
    build(list, size);
    display(list, size);

    int toRemove = 0;

    cin>>toRemove;
    remove(list,size,toRemove);
    display(list, size);
    
    return 0;
}
