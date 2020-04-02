#include"printer.h"

PrinterSpooler::PrinterSpooler() {   
    double rand(time(0));
}

//Precondition:
//Postcondition:
//Description:
void PrinterSpooler::generateJob() {
    int n = rand() % 15 + 1;
    int x = rand() % 20 - 10;
    int t = n + x;
    if (t <= 0)
        t = 1;
    spooler.insert(t);
    cout << "Genrated Job:  " << t << endl;
    processor = t;
}

//Precondition:
//Postcondition:
//Description:
void PrinterSpooler::processJob() {
    if (spooler.isEmpty() != true && processor == 0) {
        cout << "Spooler is idle\n";
    }
    else if (processor == 0) {
        processor = spooler.front -> data;
        cout << "Proccess a new Job:  " << processor << endl;
        numberJobsProcessed++;
    }
    else {
        cout << "Proccess a Job:  " << processor-- << endl;
        numberJobsProcessed++;
    }
}

//Precondition:
//Postcondition:
//Description:
int PrinterSpooler::getArrivalTime() {
    int n = rand() % 15 + 1;
    int x = rand() % 20 - 10;
    int sum = n + x;

    if (spooler.front != NULL)
        sum = (rand() % 15) - spooler.front -> data;
    else
        sum = 0;

    if (sum < 0)
        sum = 0;

    return sum;
}

//Precondition:
//Postcondition:
//Description:
int PrinterSpooler::getNumJobs() {
    return spooler.size();
}

//Precondition:
//Postcondition:
//Description:
int PrinterSpooler::getFinishedJobs() {
    return numberJobsProcessed;
}