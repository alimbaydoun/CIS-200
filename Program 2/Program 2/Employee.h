#pragma once
#include<iostream>
#include<string>

using namespace std;

class Employee {
private:
    string firstName;
    string lastName;
    string ssn;
    string empNumber;
    int taxRateCode;

public:
    Employee();

    void setFirstName(string name);
    void setLastName(string name);
    void setSSN(string number);
    void setEmpNumber(string number);
    void setTaxRateCode(int x);

    string getName();
    string getSSN();
    string getEmpNumber();
    double getTaxRateCode();

    virtual void makeNoise();
    virtual void calculatePay() = 0;
    virtual void print() = 0;
};