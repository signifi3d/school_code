/*************************************
 * NAME: Blake Eakin
 * ASSIGNMENT: Lab 3
 * SOURCES: 
 *
 * Decrypts RSA ciphers given pq and d
 *************************************/

#include <iostream>
#include <fstream>
#include <string>
#include <cmath>

//Recursive function for finding residues where n is a power of 2
unsigned int residue_power_of_two(unsigned int a, unsigned int n, int mod) {
    if ( n == 1 ) { //If at 1 we don't need to reduce anymore powers of 2
        return a % mod;
    } else { //If not 1 then shift n to get the next lower power of 2
        return (int)pow(residue_power_of_two(a, n>>1, mod), 2) % mod;
    }
}


unsigned int residue(unsigned int a, unsigned int n, int mod) {
    unsigned int power_of_two = 0x80000000; //Largest uint power of 2
    long long res = 1; //Start result at 1 for future multiplactions

    while (n != 0) {
        if ((n & power_of_two) != 0) {//If n contains this power of 2
            //Find corresponding residue
            res *= residue_power_of_two(a, power_of_two, mod);
            //Decrement n by contained power of 2
            n -= power_of_two;
        }
        
        power_of_two = power_of_two >> 1;//Shift to next lowest power of 2
    }

    return res % mod; //Final mod for residue
}


int main(int argc, char ** argv) {

    std::ifstream code_file;
    std::string input;
    unsigned int pq, d;
    int c;

    std::cout << "Blake Eakin" << << std::endl << std::endl;

    //Check for proper # of command line arguments
    if (argc != 2) {
        std::cerr << "Please include one, and only one, file as a commmand line"
            << "argument to " << argv[0] << std::endl;

        return 0;
    }

    code_file.open(argv[1]);

    //Test for file validity
    if (!code_file.is_open()) {
        std::cerr << "Error opening " << argv[1] << std::endl;

        return 0;
    }

    //Take in pq and d values and output them
    code_file >> input;
    std::cout << input;
    code_file >> input;
    std::cout << input;
    code_file >> pq;
    std::cout << pq << std::endl;

    code_file >> input;
    std::cout << input;
    code_file >> input;
    std::cout << input;
    code_file >> d;
    std::cout << d << std::endl << std::endl;

    //Loop through all of the cipher values, decrypt, and output
    while ( code_file >> c ) {
        std::cout << (char)residue(c, d, pq);
    }
    std::cout << std::endl;

    code_file.close();

    return 0;
}
