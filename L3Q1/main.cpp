//  L3Q1
//
//  author: Andrew Bishop

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <cmath>
using namespace std;

void printHeader(ostream &outStream) {
    outStream << right << setw(10) << "deg";
    outStream << setw(10) << "rad" << setw(10);
    outStream << "sin" << setw(10) << "cos" << endl;
    
    outStream << right << setw(10) << "------";
    outStream << setw(10) << "------" << setw(10);
    outStream << "------" << setw(10) << "------" << endl;
}

void printEntry(ostream &outStream, double value) {
    double radian = value * M_PI / 180;
    double sine = sin(radian);
    double cosine = cos(radian);
    
    outStream << right << setw(10);
    outStream << fixed << setprecision(1);
    outStream << value << setw(10) << setprecision(4);
    outStream << radian << setw(10) << sine;
    outStream << setw(10) << cosine << endl;
}

int main(int argc, const char *argv[], const char *envp[]) {
    
    string ifile = "default.txt";;
    string ofile;
    ifstream input;
    ofstream output;
    
    if (argc >= 2) {
        ifile = argv[1];
    }

    input.open(ifile);

    if (!input.is_open()) {
        cout << "Error: could not open file " << ifile << endl;
        return 0;
    }
    
    // prepend "result_" to output file
    ofile = "result_" + ifile;
    
    output.open(ofile);
    if (!output.is_open()) {
        cout << "Error: could not open " << ofile << " for writing." << endl;
        return 0;
    }
    
    printHeader(cout);
    printHeader(output);
    
    double degrees;

    while (!input.eof()) {
        input >> degrees;
        printEntry(cout, degrees);
        printEntry(output, degrees);
    }
    
    cout << "\nOutput data saved to file: " << ofile << endl;
    
    return 0;
        
}
