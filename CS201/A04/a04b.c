#include <stdio.h>
#include <stdlib.h>

// You are only allowed to make changes to this code as specified by the comments in it.

// The code you submit must have these two values.
#define N_TIMES		600000
#define ARRAY_SIZE	 10000

int main(void)
{
	double	*array = calloc(ARRAY_SIZE, sizeof(double));
	double	sum = 0;
	int		i;

	// You can add variables between this comment ...
	double *p;
	double acc0, acc1, acc2, acc3, acc4, acc5, acc6, acc7, acc8, acc9;
	// ... and this one.

	// Please change 'your name' to your actual name.
	printf("CS201 - Asgmt 4 - Blake Eakin\n");

	for (i = 0; i < N_TIMES; i++) {

		// You can change anything between this comment ...

		int     j;

		for (p = array; p < &array[ARRAY_SIZE]; p+=100) {
			acc0 += *(p+0) +*(p+1) +*(p+2) +*(p+3) +*(p+4) +*(p+5) +*(p+6) +*(p+7) +*(p+8) +*(p+9);
			acc1 += *(p+10) +*(p+11) +*(p+12) +*(p+13) +*(p+14) +*(p+15) +*(p+16) +*(p+17) +*(p+18) +*(p+19);
			acc2 += *(p+20) +*(p+21) +*(p+22) +*(p+23) +*(p+24) +*(p+25) +*(p+26) +*(p+27) +*(p+28) +*(p+29);
			acc3 += *(p+30) +*(p+31) +*(p+32) +*(p+33) +*(p+34) +*(p+35) +*(p+36) +*(p+37) +*(p+38) +*(p+39);
			acc4 += *(p+40) +*(p+41) +*(p+42) +*(p+43) +*(p+44) +*(p+45) +*(p+46) +*(p+47) +*(p+48) +*(p+49);
			acc5 += *(p+50) +*(p+51) +*(p+52) +*(p+53) +*(p+54) +*(p+55) +*(p+56) +*(p+57) +*(p+58) +*(p+59);
			acc6 += *(p+60) +*(p+61) +*(p+62) +*(p+63) +*(p+64) +*(p+65) +*(p+66) +*(p+67) +*(p+68) +*(p+69);
			acc7 += *(p+70) +*(p+71) +*(p+72) +*(p+73) +*(p+74) +*(p+75) +*(p+76) +*(p+77) +*(p+78) +*(p+79);
			acc8 += *(p+80) +*(p+81) +*(p+82) +*(p+83) +*(p+84) +*(p+85) +*(p+86) +*(p+87) +*(p+88) +*(p+89);
			acc9 += *(p+90) +*(p+91) +*(p+92) +*(p+93) +*(p+94) +*(p+95) +*(p+96) +*(p+97) +*(p+98) +*(p+99);

			}

		// ... and this one. But your inner loop must do the same
		// number of additions as this one does.

		}

	// You can add some final code between this comment ...
	sum += acc0 + acc1 + acc2 + acc3 + acc4 + acc5 + acc6 + acc7 + acc8 + acc9;
	// ... and this one.

	return 0;
}
