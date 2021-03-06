//Written by: Blake Eakin
//Date: 7/14/2018
//Sources: None
//Assignment 4

#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>

using namespace std;

int main() {

        ifstream fin;
        string fpath;

        double orAverage = 0.0, caAverage = 0.0, waAverage = 0.0, totalAverage = 0.0;
        double orTotal = 0.0, caTotal = 0.0, waTotal = 0.0, totalTotal = 0.0;
        int orCount = 0, caCount = 0, waCount = 0, totalCount = 0;

        cout << "Please enter filepath: ";
        cin >> fpath;

        fin.open(fpath);

        if(fin.is_open()) {
                while ( !fin.eof()  ) {
                        string stateNameBuffer;
                        float gasPriceBuffer;

                        fin >> stateNameBuffer;
                        if (stateNameBuffer == "") break;
                        cout << left << setw(13) << stateNameBuffer;
                        fin >> stateNameBuffer;
                        cout << setw(13) << stateNameBuffer;
                        fin >> gasPriceBuffer;
                        cout << setw(13) << gasPriceBuffer << endl;

                        if (stateNameBuffer == "Ca") {
                                caCount++;
                                caTotal += gasPriceBuffer;
                        }
                        else if (stateNameBuffer == "Or") {
                                orCount++;
                                orTotal += gasPriceBuffer;
                        }
                        else if (stateNameBuffer == "Wa") {
                                waCount++;
                                waTotal += gasPriceBuffer;
                        }
                        totalCount++;
                        totalTotal += gasPriceBuffer;
                }

                orAverage = orTotal / orCount;
                caAverage = caTotal / caCount;
                waAverage = waTotal / waCount;
                totalAverage = totalTotal / totalCount;

                cout << "California average gas price: " << fixed << setprecision(3) << caAverage << endl;
                cout << "Oregon average gas price: "  << orAverage << endl;
                cout << "Washington average gas price: " << waAverage << endl;
                cout << "Overall average gas price: " << totalAverage << endl;

                cout << "The state with the highest average gas price is: ";

                if (orAverage > caAverage && orAverage > waAverage) {
                        cout << "Oregon" << endl;
                }
                else if ( caAverage > orAverage && caAverage > waAverage ) {
                        cout << "California" << endl;
                }
                else {
                        cout << "Washington" << endl;
                }

                cout << "The state with the lowest average gas price is: ";
                if (orAverage < caAverage && orAverage < waAverage) {
                        cout << "Oregon" << endl;
                }
                else if ( caAverage < orAverage && caAverage < waAverage ) {
                        cout << "California" << endl;
                }
                else {
                        cout << "Washington" << endl;
                }

                fin.close();
        }
        else {
                cerr << "Incorrect pathnamne.";
                return 1;
        }


        return 0;
}