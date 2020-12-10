/*******************
 * NAME: Blake Eakin
 * ASSIGNMENT: Lab 5
 * SOURCES: None
 * 
 * Generates solutions for second order linear homogeneous recurrence relations
 * with constant coefficients.
 ******************/

 #include <iostream>
 #include <math.h>

struct quadratic_roots {
    float r1;
    float r2;
};

int quadratic(quadratic_roots * result, const float A, const float B);
void single_root(quadratic_roots * roots, const float a0, const float a1);
void distinct_roots(quadratic_roots * roots, const float a0, const float a1);

int main() {

    std::cout << "Blake Eakin" << std::endl << std::endl;

    double A, B, a0, a1;
    quadratic_roots roots;

    for (int i = 0; i < 4; ++i) {
        std::cout << "Input A: ";
        std::cin >> A;
        std::cout << "Input B: ";
        std::cin >> B;
        std::cout << "Input a0: ";
        std::cin >> a0;
        std::cout << "Input a1: ";
        std::cin >> a1;

        int res = quadratic(&roots, A, B);

        if (res == -1) {
            single_root(&roots, a0, a1);
        } else if (res == 1) {
            distinct_roots(&roots, a0, a1);
        } else {
            std::cout << "This solution has complex roots." << std::endl;
        }
    }

    return 0;
}


int quadratic(quadratic_roots * result, const float A, const float B) {
    //It's important to remember that in the characteristic equation A and B
    //are made to be negative of their original values.

    //The discriminant determines if roots are complex, single, or distinct
    float discriminant = (A*-1) * (A*-1) - 4 * (B*-1);

    if (discriminant < 0) {
        return 0;
    }

    result->r1 = (((A*-1)*-1) + sqrt(discriminant)) / 2;
    result->r2 = (((A*-1)*-1) - sqrt(discriminant)) / 2;

    //-1 if single root, 1 if distinct
    if (result->r1 == result->r2) {
        return -1;
    } else if (result->r1 != result->r2) {
        return 1;
    } 
}


void single_root(quadratic_roots * roots, const float a0, const float a1) {
    float C, D;

    C = a0;
    D = (a1 - a0 * roots->r1) / roots->r1;

    std::cout << "Formula for the sequence: an = (" << C << ")(" << roots->r1 
        << ")^n + ("<< D <<")*n*(" << roots->r1 << ")^n for every integer n>=0"
        << std::endl;

    std::cout << "First six terms of the sequence: ";
    for (int i = 0; i <= 5; ++i) {
        std::cout << C * pow(roots->r1, i) + D * i * pow(roots->r1, i);
        
        if (i != 5)
            std::cout << ", ";
    }
    std::cout << std::endl << std::endl;
}


void distinct_roots(quadratic_roots * roots, const float a0, const float a1) {
    float C, D;

    C = (a1 - a0 * roots->r2) / (roots->r1 - roots->r2);
    D = a0 - C;

    std::cout << "Formula for the sequence: an = (" << C << ")(" << roots->r1 
        << ")^n + (" << D << ")(" << roots->r2 << ")^n for every integer n>=0" 
        << std::endl;

    std::cout << "First six terms of the sequence: ";
    for (int i = 0; i <= 5; ++i) {
        std::cout << C * pow(roots->r1, i) + D * pow(roots->r2, i);

        if (i != 5)
            std::cout << ", ";
    }
    std::cout << std::endl << std::endl;
}
