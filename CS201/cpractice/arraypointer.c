#include <stdio.h>

int main() {
	
	int arr[10];
	int * arrpoint;

	for (int i = 0; i < 10; i++) {
		arr[i] = 5*i;
	}

	arrpoint = &arr[5];

	printf("%d\n", arr[5]);

	arrpoint+=2;
	*arrpoint+=10;

	for (int i = 0; i < 10; i++) {
		printf("%d\n", arr[i]);
	}


	return 0;
}
