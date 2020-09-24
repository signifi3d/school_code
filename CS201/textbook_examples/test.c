#include "stdio.h"

int main() {
	long sum = 0;
	long i;
	for (i = 0; i < 10; i++) {
		if ( i & 1 ) {
			continue;
		}
		sum += i;
	}

	printf("%d\n", sum);
}
