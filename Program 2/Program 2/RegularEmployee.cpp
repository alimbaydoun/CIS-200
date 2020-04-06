#include<iostream>
#include"RegularEmployee.h"

using namespace std;

RegularEmployee::RegularEmployee() {

	this->overtimeHours = 0;
}
void RegularEmployee::setOvertimeHours(double hours) {
	if (this->getHoursWorked() == 40) {
		cout << "You have already fulfilled 40 hours" << endl;
		cout << "Error" << endl;
		exit(-1);
	}

	if (hours > 20) {
		cout << "You cannot work more than 20 hours of overtime" << endl;
		cout << "Error" << endl;
		exit(-1);
	}

	if (hours < 0) {
		cout << "You cannot have less than 0 hours" << endl;
		cout << "Error" << endl;
		exit(-1);
	}

	this->overtimeHours = hours;
}


double RegularEmployee::getOvertimeHours() {

	return this->overtimeHours;
}


void RegularEmployee::calculatePay() {

	double amount = (this->getHoursWorked() * this->getHourlyPayRate()) + (this->getOvertimeHours() * (this->getHourlyPayRate() * 1.5));
	this->setAmountEarned(amount);
}


double RegularEmployee::getNetIncome() {


	return this->getAmountEarned() - (this->getAmountEarned() * this->getTaxRateCode());
}

void RegularEmployee::print() {

	cout << "Employee Name : " << this->getName() << endl;
	cout << "Employee SSN : " << this->getSSN() << endl;
	cout << "Employee Tax Rate : " << this->getTaxRateCode() << endl;
	cout << "Hourly Pay Rate : " << this->getHourlyPayRate() << endl;
	cout << "Hours worked : " << this->getHoursWorked() << endl;
	cout << "Overtime Hours Worked : " << this->getOvertimeHours() << endl;
	this->calculatePay();
	cout << "Gross Income : " << this->getAmountEarned() << endl;
	cout << "Net Income : " << this->getNetIncome() << endl;
	cout << "Intercom: "; this->makeNoise(); cout << endl;
}