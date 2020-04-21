#include <iostream>
using namespace std;
int find(double arr[], int size, double target) {

	bool Notfound = true;
	for (int i = 0; i < size; i++) {
		if (arr[i] == target) {
			return i;
			Notfound = false;
		}
	}

	if (Notfound) {
		throw "Index not found, Exception Thrown!\n";
	}

	return -1;
}


int main() {

	double arr[5] = { 1.9,2.2,6.1,4.2,2.3 };

	try {
		int index = find(arr, 5, 0.2);
		cout << "Index is : " << index << endl;
	}
	catch (const char* msg) {
		cerr << msg << endl;
	}


	system("pause");
	return 0;
}