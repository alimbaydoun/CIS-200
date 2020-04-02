//
//  printer.cpp
//  Question#4
//
//  Created by Ahmed Mazloum on 4/1/20.
//  Copyright © 2020 Ahmed Mazloum. All rights reserved.
//

#include "printer.h"

//Pre:none
//Desc:Sets this processor equal to this numberJobsProcessed which is equaled zero
//Post:Sets the PrinterSpooler function
PrinterSpooler::PrinterSpooler()
{

    //this->processor = this->numberJobsProcessed = 0;
    double rand(time(0));
}
//Pre:none
//Desc:Adds two random values one from 1 to 15 and the other from -10 to 10
//Post: Prints out the genrated jobs value
void PrinterSpooler::generateJob()
{
    int t = rand() % 15 + 1;
    int a = rand() % 20 - 10;
    int s = t + a;
    if (s <= 0)
        s = 1;
    spooler.insert(s);
    cout << "Genrated Job:  " << s << endl;
    processor = s;
}
//Pre:none
//Desc:Checks processor and the isempty and prints a messages/increments a value depending on the condition
//Post:Prints a messages/increments a value depending on the condition
void PrinterSpooler::processJob()
{
    if (spooler.isEmpty() != true && processor == 0)
    {
        cout << "Spooler is idle\n";
    }
    else if (processor == 0)
    {
        processor = spooler.front->data;
        cout << "Proccess a new Job:  " << processor << "\n";
        numberJobsProcessed++;
    }
    else
    {
        cout << "Proccess a Job:  " << processor-- << "\n";
        numberJobsProcessed++;
    }
}
//Pre:none
//Desc:Adds two random values one from 1 to 15 and the other from -10 to 10 and checks if the front of the spooler queue is not null and does rand mod 15 - the front data of spooler if its not null
//Post:Returns the value of s
int PrinterSpooler::getArrivalTime()
{
    int t = rand() % 15 + 1;
    int a = rand() % 20 - 10;
    int sum = t + a;

    if (spooler.front != NULL)
        sum = (rand() % 15) - spooler.front->data;
    else
        sum = 0;

    if (sum < 0)
        sum = 0;

    return sum;
}
//Pre:None
//Desc:Returns spooler size value for the getNumJobs
//Post:Returns spooler size value for the getNumJobs
int PrinterSpooler::getNumJobs()
{
    return spooler.size();
}
//Pre:None
//Desc:Returns the numberJobsProcessed value for getFinishedJobs
//Post:Returns the numberJobsProcessed value for getFinishedJobs
int PrinterSpooler::getFinishedJobs()
{
    return numberJobsProcessed;
}

