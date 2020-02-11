/*
Name: Ali Baydoun
Date: 2/3/2020
File: Lab 3
Purpose: To create a program that represents students according to their major and credit hours
*/

//Librarys
#include "Student.h"
#include <vector>

/*
Precondition: None
Postcondition: Calls displayStudent function and inputs from the data collected
*/
int main() {
    Student s1("Computer Science");
    cout << s1.displayStudent();

    vector<Student> students(5);
    for (int i = 0; i < 5; i++) {
        cout << "Enter Details of student " + to_string(i + 1) << endl;
        Student s;
        int credits;
        string major;

        cout << "\nEnter Major: ";
        cin >> major;

        cout << "\nEnter credits: ";
        cin >> credits;

        if (credits <= 0) {
            cout << "Credits cannot be less than 1\n";
            return 1;
        }

        s.setMajor(major);
        s.setCredits(credits);

        students[i] = s;
    }

    for (int i = 0; i < 5; i++) {
        cout << students[i].displayStudent();
    }

    return 0;
}