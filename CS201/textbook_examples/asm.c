#include "stdio.h"

int add (int a) {
	int sum;

	asm(
		"fun:"
		" movl $0,%%eax\n"
		" jmp test\n"
		"loop:\n"
		" xorq %%rdi,%%rax\n"
		" shrq %%rdi\n"
		"test:\n"
		" testq %%rdi,%%rdi\n"
		" jne loop\n"
		" andl $1,%%eax\n"
		: "=a" (sum)
		: "D" (a)
	);

	return sum;
}

int main() {

	for (int i = 0; i < 20; ++i) {
		printf("%d, %d\n", i, add(i));
	}

	return 0;
}
