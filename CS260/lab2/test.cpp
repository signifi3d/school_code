#include <iostream>

int main() {

int * n;
int *o;

n = new int(5);
o = n;
delete n;
n = NULL;

std::cout << o << std::endl;
std::cout << n << std::endl;

return 0;
}
