// do not change this code except in the following ways:
//   * write code for the following functions:
//      * bigOrSmallEndian()
//      * getNextHexInt()
//      * printNumberData()
//   * change studentName by changing "I. Forgot" to your actual name

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

static char *studentName = "Blake Eakin";

// report whether machine is big or small endian
void bigOrSmallEndian()
{
	int endDeterminant = 0xEEFF;
	unsigned char* determinantPointer = (unsigned char*) &endDeterminant;

	if (determinantPointer[0] == 0xFF)
		printf("byte order: little-endian\n");
	else
		printf("byte order: big-endian\n");
	
	return;
}

// get next int (entered in hex) using scanf()
// returns true (success) or false (failure)
// if call succeeded, return int value via iPtr
bool getNextHexInt(unsigned int *iPtr)
{
	return scanf("%X",iPtr);
}

// print requested data for the given number
void printNumberData(int i)
{
	int 	signBitMask = 0x80000000;
	int  	expBitMask = 0x7F800000;
	int 	fractBitMask = 0x007FFFFF;
	int 	quietMask = 0x00400000;
	bool 	signBitActive = i & signBitMask && signBitMask;
	int 	expBits = (i & expBitMask) >> 23;
	int 	fractBits = i & fractBitMask;
	
	printf("signBit: %d, expBits %d, fractBits 0x%.8X\n", signBitActive, expBits, fractBits);
	
	if ( expBits ) {
		if ( expBits == 255 ) {
			if ( fractBits ) {
				printf("%cNaN\n", fractBits & quietMask ? 'Q' : 'S');
			} else {
				printf("%cinfinity\n", signBitActive ? '-' : '+');
			}
		} else {
			printf("normalized:   exp = %d\n", expBits - 127);
		}
	} else {
		if ( fractBits ) {
			printf("denormalized: exp = %d\n", expBits - 127);
		} else {
			printf("%czero\n", signBitActive ? '-' : '+');
		}
	}

	return;
}

// do not change this function in any way
int main(int argc, char **argv)
{
	unsigned int	i;					// number currently being analyzed
	bool			validInput;			// was user input valid?

	printf("CS201 - A01p - %s\n\n", studentName);
	bigOrSmallEndian();
	for (;;) {
		if (argc == 1)						// allow grading script to control ...
			printf("> ");					// ... whether prompt character is printed
		validInput = getNextHexInt(&i);
		printf("0x%08X\n", i);
		if (! validInput) {					// encountered bad input
			printf("bad input\n");
			while (getchar() != '\n') ;		// flush bad line from input buffer
			continue;
			}
		printNumberData(i);
		if (i == 0) {
			printf("bye...\n");
			break;
			}
		}
	printf("\n");
	return 0;
}
