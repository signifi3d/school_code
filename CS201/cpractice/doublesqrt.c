#include <stdio.h>

double doubSqrt(double a) {
	double constant = 1.34;
	double out;

	asm(
	"vmovsd %1, %%xmm0\n"
	"sqrtsd %%xmm0,%%xmm0\n"
	"vmulsd %2, %%xmm0, %%xmm0\n"
	"movq %%xmm0,%0\n"
	: "=m"(out)
	: "m" (a), "m" (constant)
	);

	return out;
}

int main() {
	double in;

	scanf("%lf", &in);
	printf("%lf\n", doubSqrt(in));

	return 0;
}
