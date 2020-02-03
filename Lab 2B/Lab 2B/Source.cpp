#include<iostream>
#include<string>
#include<iomanip>
#include"Header.h"
using namespace std;

int main()
{
	string month;
	char option;
	
	float storeMonthlySales[numStores][numMonths][numDepts] =
	{
		1.1, 1.2, 1.3, 1.4, 1.5, 1.6, 1.7, 1.8, 1.9, 2.0, 2.1, 2.2,
		2.1, 2.2, 2.3, 2.4, 2.5, 2.6, 2.7, 2.8, 2.9, 3.0, 3.1, 3.2,
		3.1, 3.2, 3.3, 3.4, 3.5, 3.6, 3.7, 3.8, 3.9, 4.0, 4.1, 4.2,
		2.1, 2.2, 2.3, 2.4, 2.5, 2.6, 2.7, 2.8, 2.9, 3.0, 3.1, 3.2
	};
	
	do
	{
		cout << "Please enter a month to print (1-12): ";
		cin >> month;
		printMonthlySales(storeMonthlySales, month);
		cin.ignore(256, ' ');
		cout << "Do you want to enter another value? (y or n): ";
		cin >> option;
		while (option !='y' && option !='n')
		{
			cout << "Enter y or n: ";
			cin >> option;
		}
	} while (option != 'n');
	
	return 0;
}