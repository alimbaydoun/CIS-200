#include<iostream>
#include"SalaryEmployee.h"
#include<time.h>

using namespace std;

SalaryEmployee::SalaryEmployee() {

    this -> annualPay = 0;
    this -> weeklyPay = 0;
}

//Pre-condition: 
//Post-condition: 
//Description: 
void SalaryEmployee::calculatePay() {

    this -> setWeeklyPay(this -> getAnnualPay() / 52.0);
}

double SalaryEmployee::getGrossSalary() {

    double gross = this -> getAnnualPay() - (this -> getAnnualPay()* this -> getTaxRateCode());
    return gross;
}

//Pre-condition: 
//Post-condition: 
//Description: 
void SalaryEmployee::makeNoise() {

    string msg[3] = {
      "This is a test.",
      "Testing...",
      "Currently testing..."
    };

    srand(time(0));
    int i = rand() % 3;
    cout << msg[i] << endl;
}

//Pre-condition: 
//Post-condition: 
//Description: 
void SalaryEmployee::setAnnualPay(double pay) {
    if (pay < 0) {
        cout << "Error" << endl;
        exit(-1);
    }

    this -> annualPay = pay;
}

//Pre-condition: 
//Post-condition: 
//Description: 
void SalaryEmployee::setWeeklyPay(double weekly_pay) {

    this -> weeklyPay = weekly_pay;
}

double SalaryEmployee::getAnnualPay() {
    return this -> annualPay;
}

double SalaryEmployee::getWeeklyPay() {
    return this -> weeklyPay;
}

//Pre-condition: 
//Post-condition: 
//Description: 
void SalaryEmployee::print() {

    cout << "Employee Name : " << this -> getName() << endl;
    cout << "Employee SSN : " << this -> getSSN() << endl;
    cout << "Employee Tax Rate : " << this -> getTaxRateCode() << endl;
    cout << "Annual Gross Salary is : " << this -> getAnnualPay() << endl;
    cout << "Annual Net Salary is : " << this -> getGrossSalary() << endl;
    this -> calculatePay();
    cout << "Weekly Salary is : " << this -> getWeeklyPay() << endl;
    cout << "Intercom: ";
    this -> makeNoise();
    cout << endl;
}