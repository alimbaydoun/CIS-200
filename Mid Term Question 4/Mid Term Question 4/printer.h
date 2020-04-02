#pragma once
#include"queue.h"
#include<stdlib.h>
#include<time.h>
#include<iostream>

using namespace std;

class PrinterSpooler {
private:
    Queue < int > spooler;
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