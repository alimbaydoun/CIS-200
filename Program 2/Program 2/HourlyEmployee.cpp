#include<iostream>
#include"HourlyEmployee.h"

using namespace std;

void HourlyEmployee::setAmountEarned(double amount) {
	this->amountEarned = amount;
}


double HourlyEmployee::getHoursWorked() {
	return this->hoursWorked;
}

double HourlyEmployee::getHourlyPayRate() {
	return this->hourlyPayRate;
}

double HourlyEmployee::getAmountEarned() {

	return this->amountEarned;
}

HourlyEmployee::HourlyEmployee() {
	this->hoursWorked = 0;
	this->hourlyPayRate = 0;
	this->amountEarned = 0;
}

void HourlyEmployee::setHoursWorked(double hours) {
	if (hours > 40 || hours < 0) {
		cout << "The maximum amout of hours earned is 40." << endl;
		cout << "Error" << endl;
		exit(-1);
	}
	this->hoursWorked = hours;
}

void HourlyEmployee::setHourlyPayRate(double rate) {

	if (rate > 100 || rate < 15) {
		cout << "All employees must have a hourly pay rate between $15 to $100." << endl;
		cout << "Error" << endl;
		exit(-1);
	}
	this->hourlyPayRate = rate;
}
