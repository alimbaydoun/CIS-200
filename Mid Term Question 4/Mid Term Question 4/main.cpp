#include "printer.h"
#include <iostream>
using namespace std;
//Pre:None
//Desc:Prints the starting printer spooler and current time
//Post:Prints the starting printer spooler and current time
int main() {
    cout << "Starting Printer Spooler\n";
    PrinterSpooler ps;
    int c = 1000;
    int aTime;
    while (c)
    {
        cout << "Current Time:  " << c-- << "\n";
        aTime = ps.getArrivalTime();
        if (aTime == 0)
        {
            ps.generateJob();
            aTime = ps.getArrivalTime();
        }
        else
            aTime--;
        ps.processJob();
    }
    return 0;

}