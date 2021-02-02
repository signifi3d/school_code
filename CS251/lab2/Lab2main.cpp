/*******************
 * NAME: Blake Eakin
 * ASSIGNMENT: Lab 2
 * SOURCES: 
 ******************/

#include <iostream>
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


int main() {

    std::cout << "Blake Eakin" << std::endl;

    std::cout << "This program will print the result of the operation a^n mod p"
        << std::endl;
    //Input loop
    for (int i = 0; i < 4; ++i) {
        unsigned int a, n, mod;

        std::cout << "Input a, the base: ";
        std::cin >> a;
        std::cout << "Input n, the exponent: ";
        std::cin >> n;
        std::cout << "Input p, the modulus: ";
        std::cin >> mod;
        
        std::cout << a << "^" << n << "mod" << mod << "=" 
            << residue(a, n, mod) << std::endl;

    }

    return 0;
}
