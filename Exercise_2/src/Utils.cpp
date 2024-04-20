#include "Utils.hpp"
#include <fstream>
#include <iostream>
#include <sstream>
#include <iomanip>

using namespace std;
bool readFile(const string& filename,
              double& S, int& n, double*& w,
              double*& r){
    ifstream file;
    file.open(filename);

    if(file.fail()){
        cerr<<"file open failed"<< endl;
        return false;
    }
    string line;
    getline(file, line);
    istringstream getS(line.substr(line.find(';') + 1)); //estrae la stringa di posizione successiva al ;
    getS >> S;

    getline(file, line);

    istringstream getN(line.substr(line.find(';') + 1));
    getN >> n;


    w = new double[n];
    r = new double[n];

    getline(file, line);

    for (int i = 0; i < n; ++i) {
        getline(file, line);
        stringstream getVal(line);
        char delim;
        getVal >> delim >> w[i] >> delim >> r[i];

    }

    file.close();
    return true;
}

double calcReturn(int n, double* w, double* r) {
    double returnVal = 0.0;
    for (int i = 0; i < n; ++i) {
        returnVal += w[i] * r[i];
    }
    return returnVal;
}

double calcVal(double S, double returnVal) {
    return S * (1 + returnVal);
}

bool writeFile(const string& outfilename, double S, int n, const double* w, const double* r, double returnVal, double finalVal){
    ofstream outfile;
    outfile.open(outfilename);

    if(outfile.fail()){
        cerr<<"file open failed" << endl;
        return false;
    }

    outfile << "S = " << fixed << setprecision(2) << S << ", n = " << n << endl;

    outfile << "w = [ ";
    for (int i = 0; i < n; ++i) {
        outfile << w[i];
        if (i < n - 1) outfile << " ";
    }
    outfile << " ]" << endl;

    outfile << "r = [ ";
    for (int i = 0; i < n; ++i) {
        outfile << r[i];
        if (i < n - 1) outfile << " ";
    }
    outfile << " ]" << endl;

    outfile << "Rate of return of the portfolio: " << fixed << setprecision(4) << returnVal << endl;
    outfile << "V: " << fixed << setprecision(2) << finalVal << endl;

    outfile.close();
    return true;
}
