#include <iostream>
#include"grade.h"

using namespace std;

int main()
{
	Grader g;
	string path = "";

	while (path != "stop")
	{
		cout << "Enter a name of class file to read or stop to end: ";
		cin >> path;
		if (path != "stop") {
			g.readFile(path);
		}
	}
	path = "";
	while (path != "stop")
	{
		cout << "Enter ID to find and print record or stop to end: ";
		cin >> path;
		if (path != "stop") {
			g.searchID(path);
		}
	}
}