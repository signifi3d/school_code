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
	double acc0, acc1, acc2, acc3, acc4, acc5, acc6, acc7, acc8, acc9;

	// ... and this one.

	// Please change 'your name' to your actual name.
	printf("CS201 - Asgmt 4 - Blake Eakin\n");

	for (i = 0; i < N_TIMES; i++) {

		// You can change anything between this comment ...

		int     j;

		for (j = 0; j < ARRAY_SIZE;j+=100) {
			acc0 += array[j+0] +array[j+1] +array[j+2] +array[j+3] +array[j+4] +array[j+5] +array[j+6] +array[j+7] +array[j+8] +array[j+9];
			acc1 += array[j+10] +array[j+11] +array[j+12] +array[j+13] +array[j+14] +array[j+15] +array[j+16] +array[j+17] +array[j+18] +array[j+19];
			acc2 += array[j+20] +array[j+21] +array[j+22] +array[j+23] +array[j+24] +array[j+25] +array[j+26] +array[j+27] +array[j+28] +array[j+29];
			acc3 += array[j+30] +array[j+31] +array[j+32] +array[j+33] +array[j+34] +array[j+35] +array[j+36] +array[j+37] +array[j+38] +array[j+39];
			acc4 += array[j+40] +array[j+41] +array[j+42] +array[j+43] +array[j+44] +array[j+45] +array[j+46] +array[j+47] +array[j+48] +array[j+49];
			acc5 += array[j+50] +array[j+51] +array[j+52] +array[j+53] +array[j+54] +array[j+55] +array[j+56] +array[j+57] +array[j+58] +array[j+59];
			acc6 += array[j+60] +array[j+61] +array[j+62] +array[j+63] +array[j+64] +array[j+65] +array[j+66] +array[j+67] +array[j+68] +array[j+69];
			acc7 += array[j+70] +array[j+71] +array[j+72] +array[j+73] +array[j+74] +array[j+75] +array[j+76] +array[j+77] +array[j+78] +array[j+79];
			acc8 += array[j+80] +array[j+81] +array[j+82] +array[j+83] +array[j+84] +array[j+85] +array[j+86] +array[j+87] +array[j+88] +array[j+89];
			acc9 += array[j+90] +array[j+91] +array[j+92] +array[j+93] +array[j+94] +array[j+95] +array[j+96] +array[j+97] +array[j+98] +array[j+99];

			}

		// ... and this one. But your inner loop must do the same
		// number of additions as this one does.

		}

	// You can add some final code between this comment ...

	sum += acc0 + acc1 + acc2 + acc3 + acc4 + acc5 + acc6 + acc7 + acc8 + acc9;
	// ... and this one.

	return 0;
}
