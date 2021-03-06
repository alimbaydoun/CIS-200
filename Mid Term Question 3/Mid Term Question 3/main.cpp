#include<iostream>
#include<iomanip>
#include<string>
#include"stack.h"
#include"Header.h"

using namespace std;

//Precondition:
//Postcondition:
//Description:
void execute(string str, Stack < double >& s) {
    double num1, num2;
   
    Operator o;
    string word = "";
   
    for (auto n : str) {
        if (n == ' ' || n == '\t') {
            if (word != "-" && word != "+" && word != "/" && word != "*")
                s.push(atof(word.c_str()));
            else if (o.isOperationVaild((word.c_str())[0])) {
                num1 = s.Top();
                s.pop();
                num2 = s.Top();
                s.pop();
                s.push(o.OperationFunction(num1, num2, (word.c_str())[0]));
            }
            word = "";
        }
        else if (n != '\n') {
            word = word + n;
        }
    }
    if (!s.isEmpty())
        cout << fixed << showpoint << setprecision(5) << (s.pop()) << endl;
}

//Precondition:
//Postcondition:
//Description:
int main() {
    string expression;
    Stack < double > t;

    while (true) {
        cout << "Please type in a postfix expression (ex: + = 3 1) or stop: " << endl;
        getline(cin, expression);

        if (expression.compare("stop") == 0 || expression.compare("Stop") == 0) {
            return 0;
        }
        execute(expression, t);
    }
    return 0;
}