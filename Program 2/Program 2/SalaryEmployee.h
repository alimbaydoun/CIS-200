#pragma once
#include"Employee.h"

class SalaryEmployee :public Employee
{
private:
	double annualPay;
	double weeklyPay;
	void setWeeklyPay(double);
	double getGrossSalary();


public:
	SalaryEmployee();
	
	void setAnnualPay(double);
	double getAnnualPay();
	double getWeeklyPay();
	void makeNoise();
	void calculatePay();
	void print();
};