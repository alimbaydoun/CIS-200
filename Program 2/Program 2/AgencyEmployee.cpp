#include<iostream>
#include"AgencyEmployee.h"
#include<time.h>

using namespace std;

AgencyEmployee::AgencyEmployee() {
    this -> companyName = "";
}

void AgencyEmployee::setCompanyName(string name) {
    this -> companyName = name;
}

string AgencyEmployee::getCompanyName() {
    return this -> companyName;
}

void AgencyEmployee::makeNoise() {
    string msg[3] = {
      "Right, so there’s three more people we can easily lose.",
      "So what would you say you do here ?",
      "We fixed the glitch."
    };

    srand(time(0));
    int i = rand() % 3;
    cout << msg[i] << endl;
}

void AgencyEmployee::calculatePay() {

    double amount = this -> getHourlyPayRate()* this -> getHoursWorked();
    this -> setAmountEarned(amount);
}

double AgencyEmployee::getNetIncome() {

    return this -> getAmountEarned() - (this -> getAmountEarned()* this -> getTaxRateCode());
}

void AgencyEmployee::print() {

    cout << "Employee Name : " << this -> getName() << endl;
    cout << "Employee SSN : " << this -> getSSN() << endl;
    cout << "Employee Tax Rate : " << this -> getTaxRateCode() << endl;
    cout << "Hourly Pay Rate : " << this -> getHourlyPayRate() << endl;
    cout << "Hours worked : " << this -> getHoursWorked() << endl;
    this -> calculatePay();
    cout << "Gross Income : " << this -> getAmountEarned() << endl;
    cout << "Net Income : " << this -> getNetIncome() << endl;
    cout << "Company to Pay is:" << this -> getCompanyName() << endl;
    cout << "Intercom: ";
    this -> makeNoise();
    cout << endl;
}