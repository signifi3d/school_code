#include "table.h"

#include <iostream>

using namespace std;

int main()
{
    node * root = NULL;
    build(root);
    display(root);

    cout << "Sum of nodes: " << sumOfNodes(root) << endl;
    node * newRoot = NULL;
    copyLeaf(root, newRoot);
    cout << "All leaves inserted into new tree:" << endl << endl;
    display(newRoot);

    display(root);
    destroy(root);
    destroy(newRoot);
    return 0;
}
