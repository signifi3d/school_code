/*******************************************************************************
 * NAME: Blake Eakin
 * ASSIGNMENT: Lab 1
 * SOURCES: None
 *
 * This lab processes truth values for predetermined statements and, by
 * considering them as part of a simple argument, evaluates the argument's
 * validity. Then it prints out a truth table of the variables, premise, and
 * conclusion along with whether or not the argument was valid.
 ******************************************************************************/

#include <iostream>
#include <iomanip>

#define PAD std::setw(7)


bool evalPrem(const bool p, const bool q, const bool r);
bool evalConc(const bool p, const bool q, const bool r);
void printRes(const bool (&t_table)[8][5]);


int main() {
    //Holds all truth values. NULL as premise and conclusion placeholder.
    bool t_table[8][5] = {
                            {true, true, true, NULL, NULL},
                            {true, true, false, NULL, NULL},
                            {true, false, true, NULL, NULL},
                            {true, false, false, NULL, NULL},
                            {false, true, true, NULL, NULL},
                            {false, true, false, NULL, NULL},
                            {false, false, true, NULL, NULL},
                            {false, false, false, NULL, NULL}
                        };


    std::cout << "Blake Eakin" << std::endl << std::endl;

    for (int i = 0; i < 8; ++i) {
        t_table[i][3] = evalPrem(t_table[i][0], t_table[i][1], t_table[i][2]);
        t_table[i][4] = evalConc(t_table[i][0], t_table[i][1], t_table[i][2]);
    }

    printRes(t_table);

    return 0;
}


bool evalPrem(const bool p, const bool q, const bool r) {
    //Edit the following line to change the premise.
    return ( (p || q ? r : true) && (!q == p) && ((!r || q) ^ p) );
    //return (p && r) ? q : true;
}


bool evalConc(const bool p, const bool q, const bool r) {
    //Edit the following line to change the conclusion.
    return !q && r;
    //return q || r;
}


void printRes(const bool (&t_table)[8][5]) {
    bool invalid = false;

    //Check for invalid rows.
    for (int row = 0; row < 8; ++row) {
        if (t_table[row][3] && !t_table[row][4]) {
            invalid = true;
            std::cout << "The argument is invalid in row " << row << std::endl;
        }
    }

    //Check if argument was valid.
    if (!invalid) {
        std::cout << "The argument is valid." << std::endl;
    }

    //Print truth table.
    std::cout << std::left << PAD << "Row" << PAD << "P" << PAD << "Q" << PAD 
        << "R" << PAD << "Prem" << PAD << "Concl" << std::endl;

    for (int row = 0; row < 8; ++row) {
        std::cout << PAD << row;

        for (int col = 0; col < 5; ++col) {
            std::cout << PAD << (t_table[row][col] ? "T" : "F");
        }

        std::cout << std::endl;
    }
}
