#include "list.h"
using namespace std;

int main()
{
	node * head = NULL;
	build(head);
	display(head);

	cout << "Number of evens in the list: " << countEven(head) << endl;
	cout << "Number of even elements removed from the list: " << removeEven(head) << endl;
	cout << "The list after removal: ";
	display(head);

	return 0;
}
