#pragma once

#include<iostream>
#include<string>
#include<iomanip>
#include"Header.h"
using namespace std;

const int numDepts = 2;
const int numStores = 2;
const int numMonths = 12;

void printMonthlySales(float storeMonthlySales[numStores][numMonths][numDepts], string month)
{
	int mon;

	if (month == "January")
		mon = 1;
	else if (month == "Februrary")
		mon = 2;
	else if (month == "March")
		mon = 3;
	else if (month == "April")
		mon = 4;
	else if (month == "May")
		mon = 5;
	else if (month == "June")
		mon = 6;
	else if (month == "July")
		mon = 7;
	else if (month == "August")
		mon = 8;
	else if (month == "September")
		mon = 9;
	else if (month == "October")
		mon = 10;
	else if (month == "November")
		mon = 11;
	else
		mon = 12;

	float rowValueSum, colValueSum[numDepts] = { 0 }, totalOverallSales = 0;

	cout << left << setw(13) << " ";
	for (int i = 0; i < numDepts; i++)
	{
		cout << "Dept " << left << setw(13) << i + 1;
	}
	cout << "Store Total" << endl;
	for (int i = 0; i < numStores; i++)
	{
		rowValueSum = 0;

		cout << "Store " << left << setw(6) << i + 1;
		for (int j = 0; j < numDepts; j++)
		{
			cout << left << setw(18) << month;
			rowValueSum += storeMonthlySales[i][mon - 1][j];
			colValueSum[j] += storeMonthlySales[i][mon - 1][j];
		}
		cout << rowValueSum << endl;
	}
	cout << "Dept Total ";
	for (int i = 0; i < numDepts; i++)
	{
		cout << left << setw(18) << colValueSum[i];
		totalOverallSales += colValueSum[i];
	}
	cout << totalOverallSales << endl;
}