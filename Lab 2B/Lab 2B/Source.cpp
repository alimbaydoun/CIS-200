#include<iostream>
#include<string>
#include<iomanip>
using namespace std;

const int numDepts = 2;
const int numStores = 2;
const int numMonths = 12;

void printMonthlySales(float(*storeMonthlySales)[numMonths][numDepts], int m) {
	float sumStore[numStores];
	float sumDept[numDepts]; 
	float total = 0.0;
	for (int i = 0; i < numStores; i++) {
		for (int j = 0; j < numDepts; j++) {
			cout << "Total sales by store " << i + 1 << " in department " << j + 1 << " is " << storeMonthlySales[i][m - 1][j] << endl;
			sumStore[i] += storeMonthlySales[i][m - 1][j];
			sumDept[j] += storeMonthlySales[i][m - 1][j];
			total += storeMonthlySales[i][m - 1][j];
		}
	}
	for (int i = 0; i < numStores; i++) {
		cout << "Total Sales by store " << i + 1 << " is " << sumStore[i] << endl;
	}
	for (int i = 0; i < numDepts; i++) {
		cout << "Total Sales in Department " << i + 1 << " is " << sumDept[i] << endl;
	}
	cout << "Overall Sales in the month is " << total << endl;
}

int main() {

	float storeMonthlySales[numStores][numMonths][numDepts] =
	{
		{
			{1.1, 3.1}, {1.2, 3.2}, {1.3, 3.3}, {1.4, 3.4}, {1.5, 3.5}, {1.6, 3.6},
			{1.7, 3.7}, {1.8, 3.8}, {1.9, 3.9}, {2.0, 4.0}, {2.1, 4.1}, {2.2, 4.2}
		},
		{
		  {2.1, 2.1}, {2.2, 2.2}, {2.3, 2.3}, {2.4, 2.4}, {2.5, 2.5}, {2.6, 2.6},
		  {2.7, 2.7}, {2.8, 2.8}, {2.9, 2.9}, {3.0, 3.0}, {3.1, 3.1}, {3.2, 3.2}
		}
	};
	while (1) {
		int m;
		cout << "Please enter a month to print (1-12 or 0 to exit): ";
		cin >> m;
		if (m == 0) break;
		if (m > 12) {
			cout << "Invalid input";
			continue;
		}
		printMonthlySales(storeMonthlySales, m);
	}
}