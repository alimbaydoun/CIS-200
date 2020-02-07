#include<iostream>
#include<string>
#include<iomanip>

using namespace std;

const int numDepts = 2;
const int numStores = 2;
const int numMonths = 12;

//Precondition: none
//Postcondition: none  
//Description: calculate monthly sales and return it
void printMonthlySales(float storeMonthlySales[numStores][numMonths][numDepts], int month)
{
    cout << "Sales for month of " << month << "\n";
    cout << "\t\t Dept#1 \t Dept#2 \t Store Total\n";
    int i, j;
    float deptTotal[numDepts];
    for (i = 0; i < numStores; i++)
    {
        float storeTotal = 0.0;
        float dept_total = 0.0;
        cout << "Store #" << i + 1 << "\t";
        for (j = 0; j < numDepts; j++)
        {
            storeTotal += storeMonthlySales[i][month - 1][j];
            cout << storeMonthlySales[i][month - 1][j] << "\t\t";
            dept_total += storeMonthlySales[j][month - 1][i];

        }
        deptTotal[i] = dept_total;
        cout << storeTotal << "\n";
    }
    cout << "Dept Total\t" << deptTotal[0] << "\t\t" << deptTotal[1] << "\t\t" << deptTotal[0] + deptTotal[1] << "\n";
}

//Precondition:none
//Postcondition:none
//Description: Need a main function to execute the void function with the data inside main
int main()
{
    int month;
    cout << "Please enter a month to print(1-12 or 0 to exit): ";
    cin >> month;
    float storeMonthlySales[numStores][numMonths][numDepts] =
    {
        {
            {1.1,3.1},{1.2,3.2},{1.3,3.3},{1.4,3.4},{1.5,3.5},{1.6,3.6},
            {1.7,3.7},{1.8,3.8},{1.9,3.9},{2.0,4.0},{2.1,4.1},{2.2,4.2}
        },
        {
            {2.1,2.1},{2.2,2.2},{2.3,2.3},{2.4,2.4},{2.5,2.5},{2.6,2.6},
            {2.7,2.7},{2.8,2.8},{2.9,2.9},{3.0,3.0},{3.1,3.1},{3.2,3.2}
        }
    };

    while (month != 0)
    {
        printMonthlySales(storeMonthlySales, month);
        cout << "Please enter a month to print(1-12 or 0 to exit): ";
        cin >> month;
    }

}