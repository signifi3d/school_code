/*******************************************************************************
 * NAME: Blake Eakin
 * ASSIGNMENT: Lab 2
 * SOURCES: None
 *
 * This lab emulates a low-level full adder circuit on 8-bit binary addition
 * with the allowance of an extra bit to avoid overflow issues.
 ******************************************************************************/

 #include <iostream>
 #include <cmath>
 #include <string>

//This struct is to aid with returning two values from a function
 struct bSumResult {
    bool sum = 0;
    bool carry = 0;
 };


bool            ANDgate(bool, bool);
bool            ORgate(bool, bool);
bool            NOTgate(bool);
bool            XORgate(bool, bool);
bSumResult      halfAdder(bool, bool);
bSumResult      fullAdder(bool, bool, bool);
int             bStringToInt(std::string);


int main() {

    std::string s_lval;
    std::string s_rval;
    int         sum_lval = 0;
    int         sum_rval = 0;
    int         sum_res = 0;
    bSumResult  sum_tmp;

    std::cout << "Blake Eakin" << std::endl << std::endl;

    //Main loop
    for (int i = 0; i < 4; ++i) {
        //Convert strings to int to make logical operations easier, and
        //check for any improper inputs
        std::cout << "Input first binary number to sum: ";
        std::getline(std::cin, s_lval);
        sum_lval = bStringToInt(s_lval);

        if (sum_lval == -1 || s_lval.length() > 10) {
            std::cerr << s_lval << " is not a proper 8-bit binary number." 
                << std::endl << std::endl;
            --i;
            continue;
        }

        std::cout << "Input second binary number to sum: ";
        std::getline(std::cin, s_rval);
        sum_rval = bStringToInt(s_rval);

        if (sum_rval == -1 || s_rval.length() > 10) {
            std::cerr << s_rval << " is not a proper 8-bit binary number." 
                << std::endl << std::endl;
            --i;
            continue;
        }
        
        std::cout << "The numbers to be added are " << s_lval << " and " 
            << s_rval << std::endl;

        //Grabs LSB from both #s and feeds them to fullAdder with last carry
        //Right shifts both #s, ends loop if carry and both #s are 0
        for(int j = 0;sum_lval != 0 || sum_rval != 0 || sum_tmp.carry != 0;++j){
           sum_tmp  =  fullAdder(sum_lval & 1, sum_rval & 1, sum_tmp.carry);
           sum_lval =  sum_lval >> 1;
           sum_rval =  sum_rval >> 1;
           sum_res |=  (1<<j)*sum_tmp.sum;
        }


        //Starting from highest possible power of 2, print 1/0 if in result
        std::cout << "The answer is ";
        for (int j = sum_res > 255 ? 8 : 7; j >= 0; --j)  {
            //Pad with 0s if overflowed past 8 bits
            if (j == 8)
                std::cout << "000";

            //Bit shifting for quick powers of 2
            std::cout << ((sum_res & (1<<j)) != 0);

            //Spaces every 4 bits
            if (j % 4 == 0)
                std::cout << " ";
        }
        std::cout << std::endl << std::endl;

        //Reset sum for next run
        sum_res = 0;
    }//end main loop

    return 0;
}


bool ANDgate(bool in_one, bool in_two) {
    return in_one && in_two;
}


bool ORgate(bool in_one, bool in_two) {
    return in_one || in_two;
}


bool NOTgate(bool in) {
    return !in;
}


bool XORgate(bool in_one, bool in_two) {
    return ANDgate(ORgate(in_one, in_two), NOTgate(ANDgate(in_one, in_two)));
}


bSumResult halfAdder(bool in_one, bool in_two) {
    bSumResult res;
    
    res.sum = XORgate(in_one, in_two);
    res.carry = ANDgate(in_one, in_two);

    return res;
}


bSumResult fullAdder(bool in_one, bool in_two, bool carry) {
    bSumResult res_one;
    bSumResult res_two;

    std::cout << "The bits are " << in_one << " and " << in_two 
        << ". The carry in is " << carry;

    res_one = halfAdder(in_one, in_two);
    res_two = halfAdder(res_one.sum, carry);
    res_two.carry = ORgate(res_two.carry, res_one.carry);

    std::cout << ". The sum is " << res_two.sum << ". The carry out is " 
        << res_two.carry << std::endl;

    return res_two;
}


int bStringToInt(std::string b_string) {
    int res = 0;

    for (int i = 0; i < 9; ++i) {
        //Check for space or null
        if (b_string[i] == ' ')
            continue;
        else if (b_string[i] == 0)
            break;
        
        //Make space for next digit
        res = res << 1;

        //Set next digit to 1 if '1', keep as 0 if '0', error otherwise
        if (b_string[i] == '1') 
            res |= 1;
        else if (b_string[i] == '0')
            continue;
        else {
            //Output -1 if there is an error
            std::cerr << b_string[i] << " is not a valid binary digit." 
                << std::endl;
            return -1;
        }
    }

    return res;
}
