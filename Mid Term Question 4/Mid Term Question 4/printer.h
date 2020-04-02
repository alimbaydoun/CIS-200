#pragma once
#include "Queue.h"
#include <stdlib.h>
#include <time.h>
#include <iostream>
using namespace std;
class PrinterSpooler
{
    Queue<int> spooler;
    int processor;
    int numberJobsProcessed;
public:
    PrinterSpooler();
    void generateJob();
    void processJob();
    int getArrivalTime();
    int getNumJobs();
    int getFinishedJobs();
};