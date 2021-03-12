/*******************
 * NAME: Blake Eakin
 * ASSIGNMENT: Lab 5  
 * SOURCES: 
 ******************/

#include <iostream>
#include <random>
#include <chrono>

using namespace std::chrono;

float hornersRuleEval(int poly[], float x, int degree);
float normalPolynomialEval(int poly[], float x, int degree);

int main() {

    std::cout << "Blake Eakin" << std::endl;

    for (int n = 1; n <= 20; ++n) {
        int coefficients[n+1];
        double x, result;
        steady_clock::time_point entry, exit;
        duration<double> difference; 

        //initialize random engine and distribution
        std::random_device rand;
        std::mt19937 engine(rand());
        std::normal_distribution<> dist(50, 10);

        //generate coefficients and x
        for (int i = 0; i <= n; ++i) {
            coefficients[i] = round(dist(engine));
        }

        x = dist(engine);

        //Print out polynomial information
        std::cout << "degree " << n << std::endl;

        for (int i = n; i >= 0; --i) {
            std::cout << coefficients[i] << "x^" << i;
            if ( i != 0 )
                std::cout << " + ";
            else
                std::cout << std::endl;
        }

        std::cout << "x = " << x << std::endl;

        //Get time and run horner's algorithm
        entry = steady_clock::now();
        result = hornersRuleEval(coefficients, x, n);
        exit = steady_clock::now();
        difference = duration_cast<duration<double>>(exit-entry);

        std::cout << "Horner " << difference.count() << "seconds." << std::endl;
        std::cout << "P(x)= " << result << std::endl;

        //Get time and run normal polynomial algorithm
        entry = steady_clock::now();
        result = normalPolynomialEval(coefficients, x, n);
        exit = steady_clock::now();
        difference = duration_cast<duration<double>>(exit-entry);

        std::cout << "Not Horner " << difference.count() << "seconds." 
            << std::endl;
        std::cout << "P(x)= " << result << std::endl << std::endl;
    }

    return 0;
}

//Horner's Rule as implemented in the book
float hornersRuleEval(int poly[], float x, int degree) {
    float polyval = poly[degree];

    for (int i = 1; i <= degree; ++i) {
        polyval = polyval*x + poly[degree-i];
    }

    return polyval;
}


float normalPolynomialEval(int poly[], float x, int degree) {
    float total = 0.0;

    //Go through each degree
    for (int i = degree; i >= 0; --i) {
        float product = 1.0;
        
        //Multiply the x value for each degree
        for (int j = 0; j < i; ++j) {
            product *= x;
        }

        //Multiply by coefficient and sum
        total += poly[i]*product;
    }

    return total;
}
