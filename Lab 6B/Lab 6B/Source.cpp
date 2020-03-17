#include<iostream>
#include<string>

using namespace std;

void stringReverse(string &s, int i = 0)
{
	int n = s.length();
	
	for (i = 0; i < n / 2; i++)
	{
		swap(s.at(i), s.at(n - i - 1));
	}
}

void main()
{
	string s;
	string n;

	cout << "Please enter a string to be reversed: ";
	cin >> s;

	n += s;

	stringReverse(s, 0);
	
	cout << "The reverse of " << n << " is " << s;
}