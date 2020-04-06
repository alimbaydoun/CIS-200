#include<iostream>
#include"Employee.h"
#include<time.h>

using namespace std;

Employee::Employee()
{
	this->firstName = "";
	this->lastName = "";
	this->taxRateCode = -1;
	this->ssn = "XXX-XX-XXXX";
	this->empNumber = "XXX-L";
}

void Employee::setTaxRateCode(int x)
{
	if (x >= 1 && x <= 3) {
		this->taxRateCode = x;
	}
	else {
		cout << "Try again, code must be between 1 - 3" << endl;
		exit(-1);
	}
}

void Employee::setFirstName(string name) {
	this->firstName = name;
}

void Employee::setLastName(string name) {
	this->lastName = name;
}

void Employee::setSSN(string num) {

	if (num.size() != 11) {
		cout << "Incorrect Format, try again." << endl;
		this->ssn = "XXX-XX-XXXX";
		cout << "Error" << endl;
		exit(-1);

	}
	for (int x = 0; x < 11; x++)
	{

		if (x == 3 || x == 6) {
			if (num[x] != '-') {
				cout << "Incorrect Format, try again." << endl;
				this->ssn = "XXX-XX-XXXX";
				cout << "Error" << endl;
				exit(-1);
			}
			else
			{
				this->ssn[x] = '-';
			}
		}
		else if (num[x] >= '0' && num[x] <= '9')
		{
			this->ssn[x] = num[x];
		}
		else {
			cout << "Incorrect Format, try again." << endl;
			this->ssn = "XXX-XX-XXXX";
			cout << "Error" << endl;
			exit(-1);
		}
	}

}

void Employee::setEmpNumber(string num)
{

	if (num.size() != 5) {
		cout << "Incorrect Format, try again." << endl;
		this->empNumber = "XXX-L";
		cout << "Error" << endl;
		exit(-1);

		return;
	}
	for (int x = 0; x < 3; x++) {

		if (x == 3) {
			if (num[x] != '-') {
				cout << "Incorrect Format, try again." << endl;
				this->empNumber = "XXX-L";
				cout << "Error" << endl;
				exit(-1);

				return;
			}
			else
			{
				this->empNumber[x] = '-';
			}
		}
		else if (num[x] >= '0' && num[x] <= '9')
		{
			this->empNumber[x] = num[x];
		}
		else {
			cout << "Incorrect Format, try again." << endl;
			this->empNumber = "XXX-L";
			cout << "Error" << endl;
			exit(-1);
		}
	}
}

void Employee::makeNoise()
{
	string msg[3] = { "This is a test.","Testing...","Currently testing..." };

	srand(time(0));
	int x = rand() % 3;
	cout << msg[x] << endl;
}

string Employee::getName() {
	string name = this->firstName + " " + this->lastName;
	return name;
}

string Employee::getSSN() {
	string mask = "XXX-XX-XXXX";

	for (int x = 7; x < 11; x++) {
		mask[x] = this->ssn[x];
	}
	return mask;
}

string Employee::getEmpNumber() {

	string s(this->empNumber);
	return s;
}

double Employee::getTaxRateCode() {

	double rate;
	switch (this->taxRateCode)
	{
	case 1:
		rate = 0.25;
		break;
	case 2:
		rate = 0.20;
		break;
	case 3:
		rate = 0.15;
		break;
	default:
		rate = -1;
		break;
	}
	return rate;
}