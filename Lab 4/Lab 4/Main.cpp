#include<iostream>
#include<vector>
#include<string>
#include"Vector.h"
using namespace std;

int main()
{

	//REQUIRED CODE
	Vector a, b(3), c(3);

	a.print();  // outputs []
	b.print();  // outputs [ 0 0 0 ]
	c.set(0, -1);// output error message
	c.set(1, 0);
	c.set(2, 1);
	c.set(3, 2);
	c.set(4, 3);// outputs error message 
	c.print();  // outputs [ 1 2 3 ]

	Vector d(c);
	d.print();  // outputs [ 1 2 3 ]

	d.set(0, 1);
	d.print();  // outputs [ 1 0 3 ]
	c.print();  // outputs [ 1 2 3 ]   proves deep copy

	system("pause");
	return 0;
}