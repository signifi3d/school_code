#include "dlist.h"
#include <iostream>

using namespace std;

int main()
{
    node * head = NULL;
    build(head);
    display(head);

    //PLEASE PUT YOUR CODE HERE to call the function assigned
    
    cout << "Number of even elements: " << countEven(head) << std::endl;
    cout << "Number of elements removed: " << removeEven(head) << std::endl;
    cout << "List after removal: ";


    display(head);
    destroy(head);    
    return 0;
}
