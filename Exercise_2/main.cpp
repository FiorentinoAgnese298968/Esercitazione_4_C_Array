#include <iostream>
#include "Utils.hpp"
#include <fstream>
#include <sstream>

using namespace std;

int main() {
    string filename = "./data.csv";
    string outfilename = "./result.txt";
    double S;
    int n;
    double* w = nullptr;
    double* r = nullptr;

    if (!readFile(filename, S, n, w, r)) {
        cerr << "Something went wrong with input" << endl;
        return -1;
    }

    double returnVal = calcReturn(n, w, r);
    cout << "Return value: " << returnVal << endl;

    double finalVal = calcVal(S, returnVal);
    cout << "Final value: " << finalVal << endl;

    if (!writeFile(outfilename, S, n, w, r, returnVal, finalVal)) {
        cerr << "Something went wrong with output" << endl;
        return -1;
    }
    cout << "Output successful" << endl;

    delete[] w;
    delete[] r;

    return 0;
}
