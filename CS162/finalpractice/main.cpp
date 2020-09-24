#include "list.h"
using namespace std;

int main()
{
	node * head = NULL;
	build(head);
	display(head);
	
	cout << sumOfList(head) << endl;
	insert(head, 0, 15);
	display(head);
	insert(head, 1, 16);
	display(head);
	insert(head, 13, 8888888);
	display(head);
	return 0;
}
