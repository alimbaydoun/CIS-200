#pragma once
#include<iostream>

using namespace std;

class Operator {
private:
    char ch;
    double num1;
    double num2;
    char num;

public:
    bool isOperationVaild(char ch) {
        if (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '%') {
            return true;
        }
        else {
            return false;
        }
    };
    double OperationFunction(double num1, double num2, char num) {
        float result = 0.0;

        switch (num) {
        case '+':
            result = num1 + num2;
            break;
        case '-':
            result = num2 - num1;
            break;
        case '*':
            result = num1 * num2;
            break;
        case '/':
            result = num2 / num1;
            break;
        case '%':
            result = (int)num2 % (int)num1;
            break;
        }
        return result;
    };
};