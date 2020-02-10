#include<iostream>
#include<string>
#include<fstream>
#include<iomanip>
#include"Student.h"

using namespace std;

Student::Student(string m, int c) {
    this->major = m;
    this->credits = c;
    cout << "Constructor has been called! \n";
}

Student::Student(Student& s) {
    this->major = s.major;
    this->credits = s.credits;
}

Student::~Student() {
    cout << "Destructor called for " << this->major << " major! \n";
    this->major = "None";
    this->credits = -1;
}

const string Student::getMajor() {
    return this->major;
}

const int Student::getCredits() {
    return this->credits;
}

const void Student::getStatus(string& m, int& c) {
    m = this->major;
    c = this->credits;
}

void Student::setMajor(string m) {
    this->major = m;
}

int main()
{







	return 0;
}