#include <stdio.h>

int main() {

	for (int i = 0; i < 10; ++i) {
		printf("acc%d += ", i);
		for (int j = 0; j < 9; ++j) {
			printf("(arr[j+%d]*area + (j+%d)) +", j+(10*i), j+(10*i)); 
		}
		printf("(arr[j+%d]*area)+(j+%d));\n", 9+(10*i), 9+(10*i));
	}

	return 0;
}
