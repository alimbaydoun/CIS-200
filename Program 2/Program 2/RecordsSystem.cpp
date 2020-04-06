#include<iostream>
#include<vector>
#include<string>
#include"Employee.h"
#include"SalaryEmployee.h"
#include"RegularEmployee.h"
#include"AgencyEmployee.h"

using namespace std;

vector < Employee* > emps;
vector < int > t;

//Pre-condition: 
//Post-condition: 
//Description: 
void salaryEmpInput() {

    SalaryEmployee* emp = new SalaryEmployee();
    double annualSalary;
    string firstName, lastName, ssn, empNumber;
    int taxCode;

    cout << "Enter Employee First Name: ";
    cin >> firstName;
    emp -> setFirstName(firstName);
    cout << "Enter Employee Last Name: ";
    cin >> lastName;
    emp -> setLastName(lastName);

    cout << "Enter Employee SSN: ";
    cin >> ssn;
    emp -> setSSN(ssn);
    cout << "Enter Employee Tax Rate: ";
    cin >> taxCode;
    emp -> setTaxRateCode(taxCode);
    cout << "Enter Annual Salary: ";
    cin >> annualSalary;
    emp -> setAnnualPay(annualSalary);
    emps.push_back(emp);
}

//Pre-condition: 
//Post-condition: 
//Description: 
void regularEmpInput() {

    RegularEmployee* emp = new RegularEmployee();
    double payRate, hours, overtime;
    string firstName, lastName, ssn, empNumber;
    int taxCode;

    cout << "Enter Employee First Name: ";
    cin >> firstName;
    emp -> setFirstName(firstName);
    cout << "Enter Employee Last Name: ";
    cin >> lastName;
    emp -> setLastName(lastName);

    cout << "Enter Employee SSN: ";
    cin >> ssn;
    emp -> setSSN(ssn);
    cout << "Enter Employee Tax Rate: ";
    cin >> taxCode;
    emp -> setTaxRateCode(taxCode);
    cout << "Enter Payrate: ";
    cin >> payRate;
    emp -> setHourlyPayRate(payRate);
    cout << "Enter the hours worked: ";
    cin >> hours;
    emp -> setHoursWorked(hours);
    cout << "Enter overtime hours worked: ";
    cin >> overtime;
    emp -> setOvertimeHours(overtime);

    emps.push_back(emp);
}

//Pre-condition: 
//Post-condition: 
//Description: 
void agencyEmpInput() {

    AgencyEmployee* emp = new AgencyEmployee();
    double payRate, hours;
    string firstName, lastName, ssn, empNumber, companyName;
    int taxCode;

    cout << "Enter Employee First Name: ";
    cin >> firstName;
    emp -> setFirstName(firstName);
    cout << "Enter Employee Last Name: ";
    cin >> lastName;
    emp -> setLastName(lastName);

    cout << "Enter Employee SSN: ";
    cin >> ssn;
    emp -> setSSN(ssn);
    cout << "Enter Employee Tax Rate: ";
    cin >> taxCode;
    emp -> setTaxRateCode(taxCode);
    cout << "Enter Payrate: ";
    cin >> payRate;
    emp -> setHourlyPayRate(payRate);
    cout << "Enter the hours worked: ";
    cin >> hours;
    emp -> setHoursWorked(hours);
    cout << "Enter the company name: ";
    cin >> companyName;
    emp -> setCompanyName(companyName);

    emps.push_back(emp);
}

//Pre-condition: 
//Post-condition: 
//Description: 
void print() {
    cout << "Employee Details: " << endl;
    for (int i = 0; i < emps.size(); i++) {
        cout << endl;
        emps[i] -> print();
    }
    cout << endl;
}

//Pre-condition: 
//Post-condition: 
//Description: 
void menu() {
    while (true) {

        int choice;
        cout << "Which type of Employee do you want to create: " << endl;
        cout << "	1)Salary" << endl;
        cout << "	2)Regular" << endl;
        cout << "	3)Agency" << endl;
        cout << "	4)Print Details" << endl;
        cout << "	5)End" << endl;

        cout << "Enter a number: ";
        cin >> choice;
        switch (choice) {
        case 1:
            salaryEmpInput();
            break;
        case 2:
            regularEmpInput();
            break;
        case 3:
            agencyEmpInput();
            break;
        case 4:
            print();
            break;
        case 5:
            return;
        default:
            cout << "Error" << endl;
        }
    }
}

//Pre-condition: 
//Post-condition: 
//Description: 
void main() {

    menu();
    
    system("pause");
}