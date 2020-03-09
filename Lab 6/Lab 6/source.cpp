#include<iostream>
#include<string>

using namespace std;

template <class T> int maxFunction(T A, int n)
{
	int Max = A[0];
	int index;
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
	string arr4[5] = { "x-wing", "b-wing", "y-wing", "z-wing", "tie-fighter"};

	cout << "Max of arr1: " << maxFunction(arr1, 7) << endl;
	cout << "Max of arr2: " << maxFunction(arr2, 6) << endl;
	cout << "Max of arr3: " << maxFunction(arr3, 10) << endl;
	cout << "Max of arr4: " << maxFunction(arr4, 5) << endl;


	system("pause");
}