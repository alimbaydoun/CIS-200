#pragma once
#include<iostream>

#include<string>

#include<fstream>

using namespace std;

class Grader {
private:
    ifstream input;
    ofstream output;

public:
    void setOutputFile(string, int);
    void closeOutputFile();
    void searchID(string ID);
    void readFile(string inFile);
    void calcualteDistribution();

protected:
    double calculateMidTerms(double ex1, double ex2);
    double calculateFinal(double ex3);
    double calculateProgs(double p[]);
    double calculateLabs(double p[]);
    string calculateGrade(string s);
};