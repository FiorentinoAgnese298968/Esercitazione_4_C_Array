#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>

using namespace std;

bool readFile(const string& filename,
              double& S, int& n, double*& w,
              double*& r);

double calcReturn(int n, double* w, double* r);

double calcVal(double S, double returnVal);

bool writeFile(const string& outfilename, double S,
               int n, const double* w, const double* r,
               double returnVal, double finalVal);

