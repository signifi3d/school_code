/*******************
 * NAME: Blake Eakin
 * ASSIGNMENT: Lab 1
 * SOURCES: None
 ******************/

#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <cmath>

//This type is necessary for implementing the cross product operation
struct OrderedPair {
    std::string x;
    std::string y;

    //Need a boolean equals operator for checking elements already in the set
    bool operator==(const OrderedPair& rvalue) const {
        return x == rvalue.x && y == rvalue.y;
    }
};


/*Implemented Set as a templated class for possible future use and to use it
 *for holding strings as well as OrderedPairs for cross products
 */
template <class T>
class Set {
    public:
	Set();
        Set(const std::string);
        T& operator[](std::size_t);
        int cardinality();
        bool hasElement(const T) const;
        bool append(const T);
        Set<T> intersection(const Set<T>) const;
        Set<T> setUnion(Set<T>);
        Set<T> difference(Set<T>);
        Set<OrderedPair> crossProduct(Set<T>);
        double powerSetCardinality();
    private:
        std::vector<T> set_vector;
};


int main() {

    std::cout << "Blake Eakin" << std::endl;

    std::string user_input;
    Set<std::string> set_a, set_b, res_set;
    Set<OrderedPair> crossproduct_res;


    std::cout << "Input the items in set A, separated by spaces: ";
    //Use getline to take in a whole space-delimited line up to the \n
    std::getline(std::cin, user_input);

    //static_cast to initialize already declared Set objects
    set_a = static_cast<Set<std::string>>(user_input);

    std::cout << "The following is a list of the items in set A. A contains " 
    	<< set_a.cardinality() << " items." << std::endl << std::endl;

    std::cout << "A = { ";
    for (int i = 0; i < set_a.cardinality(); ++i) {
        std::cout << set_a[i] << " ";
    }
    std::cout << "}" << std::endl << std::endl;


    std::cout << "Input the items in set B, separated by spaces: ";
    std::getline(std::cin, user_input);
    set_b = static_cast<Set<std::string>>(user_input);

    std::cout << "The following is a list of items in set B. B contains " 
    	<< set_b.cardinality() << " items." << std::endl << std::endl;

    std::cout << "B = { ";
    for (int i = 0; i < set_b.cardinality(); ++i) {
	std::cout << set_b[i] << " ";
    }
    std::cout << "}" << std::endl << std::endl;

    /* All of the following is generally the same for each operation. Get the
     * result of the operation, iterate through and print the elements, print
     * the cardinality.
     */

    //Intersection
    res_set = set_a.intersection(set_b);
    
    std::cout << "A ∩ B contains the following:" << std::endl << "{ ";
    for (int i = 0; i < res_set.cardinality(); ++i) {
        std::cout << res_set[i] << " ";
    } std::cout << "}" << std::endl;

    std::cout << "The cardinality of A ∩ B is: " << res_set.cardinality() 
    	<< std::endl << std::endl;

    //Union
    res_set = set_a.setUnion(set_b);

    std::cout << "A ∪ B contains the following:" << std::endl << "{ ";
    for (int i = 0; i < res_set.cardinality(); ++i) {
        std::cout << res_set[i] << " ";
    }
    std::cout << "}" << std::endl;

    std::cout << "The cardinality of A ∪ B is: " << res_set.cardinality() 
    	<< std::endl << std::endl;

    //A - B
    res_set = set_a.difference(set_b);

    std::cout << "A - B = { ";
    for (int i = 0; i < res_set.cardinality(); ++i) {
        std::cout << res_set[i] << " ";
    }
    std::cout << "}" << std::endl;

    std::cout << "The cardinality is: " << res_set.cardinality() << std::endl 
    	<< std::endl;

    //B - A
    res_set = set_b.difference(set_a);

    std::cout << "B - A = { ";
    for (int i = 0; i < res_set.cardinality(); ++i) {
        std::cout << res_set[i] << " ";
    }

    std::cout << "}" << std::endl;

    std::cout << "The cardinality is: " << res_set.cardinality() << std::endl 
    	<< std::endl;

    //Cross product and cardinality of its power set
    crossproduct_res = set_a.crossProduct(set_b);

    std::cout << "The cardinality of A ⨯ B is: " 
    	<< crossproduct_res.cardinality() << std::endl;

    std::cout << "A ⨯ B contains { ";
    for (int i = 0; i < crossproduct_res.cardinality(); ++i) {
        std::cout << "(" << crossproduct_res[i].x << ", " 
	    << crossproduct_res[i].y << ") ";
    }
    std::cout << "}" << std::endl;

    std::cout << "The cardinality of the power set of the cross product is: "
    	<< crossproduct_res.powerSetCardinality() << std::endl;

    return 0;
}

template <class T>
Set<T>::Set() {
    //Default constructor actually doesn't need to do anything.
}

template <class T>
Set<T>::Set(const std::string init_string) {
    //stringstream used to simplify extracting space delimited strings
    std::stringstream tok_string(init_string);
    T input_buf;

    //Check for null sets, will add a blank element otherwise.
    if ( init_string.empty() ) {
	return;
    }

    while ( !tok_string.eof()) {
        tok_string >> input_buf;
	
	//Only add to set if element doesn't already exist
        if ( !this->hasElement(input_buf) ) {
            set_vector.push_back(input_buf);
        }
    }
}

//Cardinality is just the size of the vector holding the elements
template <class T>
int Set<T>::cardinality() {
    return set_vector.size();
}


//Linear search for Set elements
template <class T>
bool Set<T>::hasElement(const T search_element) const {

    for ( auto & comp_element : set_vector ) {
        if ( comp_element == search_element ) {
            return true;
        }
    }

    return false;
}


/*Append a single element to the Set
 *Returns true if it was successfully appended
 *Returns false if element was already in the Set and thus not appended
 */
template <class T>
bool Set<T>::append(const T new_element) {

    if ( !this->hasElement(new_element) ) {
        set_vector.push_back(new_element);
        return true;
    }

    return false;
}


//O(m*n) search for elements in both sets, returns new intersection set
template <class T>
Set<T> Set<T>::intersection(const Set<T> intersect_set) const{
    Set<T> ret_set;

    for ( auto & element : set_vector ) {
        if ( intersect_set.hasElement(element) ) {
            ret_set.append(element);
        }
    }

    return ret_set;
}


//Iterate through both sets adding elements to a new union set
template <class T>
Set<T> Set<T>::setUnion(Set<T> union_set) {
    Set<T> ret_set;

    for ( auto & element : set_vector ) {
        ret_set.append(element);
    }
    
    for ( int i = 0; i < union_set.cardinality(); ++i ) {
        ret_set.append(union_set[i]);
    }

    return ret_set;
}

/*Iterate through this set and search passed set for matching elements
 *Append non-matching elements to return set.
 */
template <class T>
Set<T> Set<T>::difference(Set<T> diff_set) {
    Set<T> ret_set;

    for ( auto & element : set_vector ) {
        if ( !diff_set.hasElement(element) ) {
            ret_set.append(element);
        }
    }

    return ret_set;
}


/*Cross product is necessarily O(m*n), unfortunately the append function
 *does a check on each element in the vector to assure unique entries, which
 *is not necessary with the cross product, so that slows it down more than 
 *O(m*n) unnecessarily.
 */
template <class T>
Set<OrderedPair> Set<T>::crossProduct(Set<T> cross_set) {
    Set<OrderedPair> ret_set;

    for ( auto & element : set_vector ) {
        for (int i = 0; i < cross_set.cardinality(); ++i) {
            OrderedPair new_cross;
            new_cross.x = element;
            new_cross.y = cross_set[i];
            ret_set.append(new_cross);
        }
    }
    
    return ret_set;
}

//Cardinality of the power set of any set A is 2^n where n is |A|
template <class T>
double Set<T>::powerSetCardinality() {
    return std::pow(2, this->cardinality());
}


//Array subscript operator overloaded for simple iteration over set elements.
template <class T>
T& Set<T>::operator[](std::size_t index) {
    return set_vector[index];
}

