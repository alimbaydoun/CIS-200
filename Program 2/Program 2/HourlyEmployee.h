#pragma once
#include"Employee.h"

class HourlyEmployee:public Employee
{
private:
	double hourlyPayRate;
	double hoursWorked;
	double amountEarned;

public:
	HourlyEmployee();
	
	void setHourlyPayRate(double rate);
	void setHoursWorked(double hours);
	void setAmountEarned(double amount);

	double getHourlyPayRate();
	double getHoursWorked();
	double getAmountEarned();
};