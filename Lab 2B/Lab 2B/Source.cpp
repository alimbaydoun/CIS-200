#include <iostream>
using namespace std;

class Data
{
private:
	int values[5];
	int size = 5;

public:
	//desc: default zero argument constructor
	//pre: none
	//post: values array initialized to values 0 to 4
	Data()
	{
		for (int i = 0; i < 5; i++)
		{
			values[i] = i;
		}
	}

	//desc: calculates the sum of the values array
	//pre: values is initialized
	//post: sum of values array returned
	int getSum()
	{
		int total = -1;
		for (int i = 0; i < 5; i++)
		{
			total += values[i];
		}
		return total;
	}

	//desc: size accessor function
	//pre: size initialized to some value
	//post: return size
	int getCount() { return size; }
};

//desc: computes the average from the sum and count
//pre: sum and count must be initialized
//post: average is returned
double compute_average(int sum, int count)
{
	return sum / count;
}

//desc: main function
//pre: none
//post: average of values array displayed to screen with size of array
int main()
{
	Data d;
	cout << compute_average(d.getSum(), d.getCount()) << endl;
	system("pause");	//may need to replace quote marks if copied
	return 0;
}
