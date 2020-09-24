#include "table.h"

#include <iostream>

using namespace std;

int main()
{
    node * root = NULL;
    build(root);
    display(root);

    /*  PLACE YOUR FUNCTION CALL HERE */

	cout << "count: " << count(root) << endl;
	cout << "sum: " << sum(root) << endl;
	cout << "height: " << height(root) << endl;


    display(root);
    destroy(root);
    return 0;
}
