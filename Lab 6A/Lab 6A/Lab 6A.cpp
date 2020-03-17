#include<iostream>
#include<string>

using namespace std;

class NullException {

};

class NegativeException {

};

template <class T> T maxFunc(const T* A, int n)
{
	if (n == 0)
	{
		throw NullException();
		return 0;
	}
	if (n < 0)
	{
		throw NegativeException();
		return 0;
	}

	T Max = A[0];
	int index = 0;
	while (index < n)
	{
		if (A[index] > Max)
		{
			Max = A[index];
		}
		index++;
	}
	return Max;
}

void main()
{
	int arr1[7] = { 7, 21, 1, 3, 15, 8, 19 };
	double arr2[6] = { 3.14, 4.15, 10.11, 3.2, 7.11, 8.05 };
	char arr3[10] = { 'A', '5', 'D', 'b', 'y', 'Z', 'E', 't', '7', 'v' };
	string arr4[5] = { "x-wing", "b-wing", "y-wing", "z-wing", "tie-fighter" };

	cout << "Max of arr1: " << maxFunc(arr1, 7) << endl;
	cout << "Max of arr2: " << maxFunc(arr2, 6) << endl;
	cout << "Max of arr3: " << maxFunc(arr3, 10) << endl;
	cout << "Max of arr4: " << maxFunc(arr4, 5) << endl;

	try
	{
		cout << "Max of arr1: " << maxFunc(arr1, 0) << endl;
	}

	catch (NullException)
	{
		cout << "Array size cannot be 0!" << endl;
	}

	catch (NegativeException)
	{
		cout << "Array Size cannot be < 0!" << endl;
	}

	system("pause");
}