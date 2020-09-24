#include <stdio.h>

int main() {

	printf("0x%.8x\n", 193417);
	printf("0x%.8x\n", ~(~0<<16)&193417);

	return 0;
}
