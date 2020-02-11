#pragma once

#include<iostream>
#include<string>

using namespace std;

class Student
{
private:
    string major;
    int credits;
public:
    Student(string m = "General Studies", int c = 0);
    Student(Student& s);
    ~Student();
    const string getMajor();
    const int getCredits();
    const void getStatus(string& m, int& c);
    void setMajor(string m);
    void setCredits(int c);
    void setStatus(string m, int c);
    string displayStudent();
};