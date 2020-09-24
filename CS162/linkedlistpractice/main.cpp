#include "list.h"
using namespace std;

int main()
{
	node * head = NULL;
	build(head);
	display(head);
	
	cout << hasCycle(head) << endl;
	
	return 0;
}
