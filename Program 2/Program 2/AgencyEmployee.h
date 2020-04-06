#pragma once
#include"HourlyEmployee.h"

class AgencyEmployee:public HourlyEmployee
{
private:
	string companyName;
	double getNetIncome();

public:
	AgencyEmployee();
	
	void setCompanyName(string name);
	string getCompanyName();
	void makeNoise();
	void calculatePay();
	void print();
};