#include<iostream>
#include"printer.h"

using namespace std;

//Precondition:
//Postcondition:
//Description:
void main() {
    cout << "Initiating Printer Spooler" << endl;
   
    PrinterSpooler ps;
    int x = 1000;
    int aTime;
    
    while (x) {
        cout << "Current Time:  " << x-- << endl;
        aTime = ps.getArrivalTime();
        
        if (aTime == 0) {
            ps.generateJob();
            aTime = ps.getArrivalTime();
        }
        
        else
            aTime--;
        ps.processJob();
    }
    system("pause");
}