#include <stdio.h>

int main() {

	int c, count;

	while ((c = getchar()) != 0) {
		if (c == '\n')
			++count;	
	}

	printf("%10d\n", count);

	return 0;
}
