//Written By: Blake Eakin
//Sources: None
//Date: 8/2/2018
//Assignment 6
//This program decodes all simple caesar cyphers in ASCII format
#include <iostream>
#include <fstream>
#include <string>

char mostFrequent(std::ifstream&);
int calcOffset(char);
void decrypt(std::ifstream&, int);
int highestIndex(int*,int);

int main () {

//Here I take in a string of the file path and check to make sure it opens correctly
std::string filePath;
std::ifstream inFile;

std::cout << "Input file path: ";
std::cin >> filePath;

inFile.open(filePath.c_str());

if ( !inFile.is_open() ) {
        std::cout << "Incorrect file path." << std::endl;
        return 0;
}

//These are the function calls that are the meat of the program.
//Decrypt takes the file stream reference and the caesar offest and prints each
//character decrypted, one at a time, ignoring non-alphabet characters.
decrypt( inFile, calcOffset( mostFrequent( inFile ) ) );

return 0;

}

void decrypt(std::ifstream& inFile, int offset) {
//This function takes in a file stream reference and a character offset and prints decrypted characters to standard out.
        char charBuffer;

        while ( inFile.peek() != EOF ) {
        //This loop just continutes until the end of the file is reached.
                inFile.get( charBuffer );
                //Store the next character in charBuffer, if this isn't used then the end of the file is never reached.
                if ( charBuffer >= 65 && charBuffer <= 90 ) {
                //This condition checks for alphabet characters in the ASCII upper case range
                        charBuffer -= offset;
                        if ( charBuffer > 90 ) charBuffer = 64 + ( charBuffer - 90 );
                        if ( charBuffer < 65 ) charBuffer = 91 - ( 65 - charBuffer );
                        //These two conditions check to see if the character went out of the bounds of the ASCII upper case codes
                }
                else if ( charBuffer >= 97 && charBuffer <= 122 ) {
                //This condition does the same thing, but with lower case letters
                        charBuffer -= offset;
                        if ( charBuffer > 122 ) charBuffer = 96 + ( charBuffer - 122 );
                        if ( charBuffer < 97 ) charBuffer = 123 - ( 97 - charBuffer );
                }
                std::cout<<charBuffer;
                //Output the character, the loop ends up here directly if no alphabetic character is found.
                //While I would usually rather have another structure to handle the outputting functionality, this works for the assignment at hand.
        }
}

char mostFrequent(std::ifstream& inFile) {
//mostFrequent loops through each character in the file and counts each alphabet character, then returns the character of highest frequency
        char charBuffer;
        int charCount[26] = {};

        while ( inFile.peek() != EOF ) {
                inFile.get( charBuffer );
                if ( charBuffer >= 65 && charBuffer <= 90 ) {
                //This condition just converts uppercase to lowercase, though I guess it could just convert the
                //uppercase code down to an array-index-friendly number and then I could change the next conditional
                //to an else if and skip out on the possibility of going through two differen statements, but
                //I don't thihnk it'll be too necessary in this project.
                        charBuffer = charBuffer + 32;
                }

                if ( charBuffer >= 97 && charBuffer <= 122 ) {
                //Checks if it's a lowercase ASCII character, then subtracts by the code where the ASCII lowercase
                //alphabet starts so that it's a number that can be used for our array.
                        charCount[ charBuffer - 97 ]++;
                }
        }

        inFile.clear();
        inFile.seekg( 0, std::ios::beg);
        //We'll be at the end of the file, so these statements reset back to the beginning so it can be used again later in the program.

        return highestIndex(charCount, 26) + 97;
        //convert the index friendly number back up to lowercase ASCII code
}

int calcOffset( char offsetChar ) {
//calcOffset simply calculates how far from the ASCII code for lowercase e our letter is. It's fine if it returns a negative.
        return offsetChar - 101;
}

int highestIndex(int* arr, int size) {
//highestIndex just loops through an array to find the index of the largest integer value in the array.
        int highest = 0;
        for (int i = 1; i < size ; i++) {
                if ( arr[highest] < arr[i] ) highest = i;
        }

        return highest;
}