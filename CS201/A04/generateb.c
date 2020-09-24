#include <stdio.h>

int main() {

	for (int i = 0; i < 10; ++i) {
		printf("acc%d += ", i);
		for (int j = 0; j < 9; ++j) {
			printf("array[j+%d] +", j+(10*i)); 
		}
		printf("array[j+%d];\n", 9+(10*i));
	}

	return 0;
}
