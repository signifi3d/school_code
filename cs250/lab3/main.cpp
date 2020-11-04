/******************************************************************************
 * NAME: Blake Eakin
 * ASSIGNMENT: Lab 3
 * SOURCES: https://gmplib.org/manual/ 
 *
 * Implements the Euclidean Algorithm and a Division Algorithm using the GNU
 * GMP library for handling large integers.
 *****************************************************************************/

 #include <iostream>
 #include <gmp.h>

struct div_res {
    mpz_t q;
    mpz_t r;
}; 

void gcd(mpz_t res, const mpz_t x, const mpz_t y);
void division(div_res * result, const mpz_t x, const mpz_t y);

int main() {
    mpz_t x, y, d, x_max;
    div_res result;

    mpz_init(x);
    mpz_init(y);
    mpz_init(d);
    mpz_init(x_max);
    mpz_init(result.q);
    mpz_init(result.r);

    mpz_ui_pow_ui(x_max, 10, 50); //set up max boundary for x-values

    std::cout << "Blake Eakin" << std::endl;

    std::cout << "Please enter an x such that 1 <= x < 10^50 : ";

    mpz_inp_str(x, stdin, 10);

    //Check for x bounds
    if (mpz_cmp_ui(x, 0) <= 0 || mpz_cmp(x, x_max) >= 0) {
        std::cerr << "x must fulfill 1 <= x < 10^50" << std::endl;
        return 1;
    }
    
    std::cout << "Please enter a y such that 1 <= y < x : ";

    mpz_inp_str(y, stdin, 10);

    //Check for y bounds
    if (mpz_cmp_ui(y, 0) <= 0 || mpz_cmp(y, x) >= 0) {
        std::cerr << "y must fulfill 1 <= y < x" << std::endl;
        return 1;
    }

    std::cout << "The greatest common divisor of x and y is : ";
    gcd(d, x, y);
    mpz_out_str(stdout, 10, d);
    std::cout << std::endl;
    
    division(&result, x, y);

    std::cout << "The quotient of x / y is : ";
    mpz_out_str(stdout, 10, result.q);
    std::cout << std::endl << "The remainder of x / y is : ";
    mpz_out_str(stdout, 10, result.r);
    std::cout << std::endl;

    mpz_clear(x);
    mpz_clear(y);
    mpz_clear(x_max);
    mpz_clear(d);
    mpz_clear(result.q);
    mpz_clear(result.r);

    return 0;
}


void gcd(mpz_t res, const mpz_t x, const mpz_t y) {
    mpz_t a, b, r;

    mpz_init(r);
    mpz_init(a);
    mpz_init(b);

    mpz_set(a, x);
    mpz_set(b, y);
    
    while(mpz_cmp_ui(b, 0) != 0) {
        mpz_mod(r, a, b);
        mpz_set(a, b);
        mpz_set(b, r);
    }

    mpz_set(res, a);

    mpz_clear(a);
    mpz_clear(b);
    mpz_clear(r);

}


void division(div_res * result, const mpz_t x, const mpz_t y) {

    mpz_set(result->r, x);

    while (mpz_cmp(result->r, y) >= 0) {
        mpz_sub(result->r, result->r, y);
        mpz_add_ui(result->q, result->q, 1);
    }
}
