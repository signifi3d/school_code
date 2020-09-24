#include "table.h"

#include <iostream>

using namespace std;

int main()
{
    node * root = NULL;
    build(root);
    display(root);

    /*  PLACE YOUR FUNCTION CALL HERE */
    cout << "number of nodes: " << numberOfNodes(root) << endl;
    removeSmallest(root);
    cout << "number of evens removed: " << removeEven(root) << endl;

    display(root);
    destroy(root);
    return 0;
}
