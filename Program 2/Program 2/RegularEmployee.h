#pragma once
#include"HourlyEmployee.h"

class RegularEmployee :public HourlyEmployee
{
private:
	double overtimeHours;
	double getNetIncome();

public:
	RegularEmployee();
	
	void setOvertimeHours(double hours);
	double getOvertimeHours();
	void calculatePay();
	void print();
};