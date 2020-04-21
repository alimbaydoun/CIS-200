#include <iostream>
#include <fstream>
using namespace std;
int GCDRecursive(int n1, int n2)
{
	if (n2 != 0)
		return GCDRecursive(n2, n1 % n2);
	else
		return n1;
}

void GCDFile() {
	ifstream infile;
	ofstream outfile;
	int gcd_val;
	int n1, n2;
	infile.open("input.dat");
	outfile.open("output.dat");
	while (!infile.eof()) {
		infile >> n1;
		infile >> n2;
		gcd_val = GCDRecursive(n1, n2);
		outfile << gcd_val << endl;
	}
	infile.close();
	outfile.close();
}

int GCDIterative(int n1, int n2) {
	int i, gcd;
	for (i = 1; i <= n1 && i <= n2; ++i)
	{
		// Checks if i is factor of both integers
		if (n1 % i == 0 && n2 % i == 0)
			gcd = i;
	}

	return gcd;
}
int main() {
	int calculated_Gcd = 0;
	calculated_Gcd = GCDRecursive(135, 42);
	cout << calculated_Gcd << endl;
	calculated_Gcd = GCDRecursive(27, 99);
	cout << calculated_Gcd << endl;
	calculated_Gcd = GCDIterative(135, 42);
	cout << calculated_Gcd << endl;
	calculated_Gcd = GCDIterative(27, 99);
	cout << calculated_Gcd << endl;
	GCDFile();

	system("pause");
	return 0;
}