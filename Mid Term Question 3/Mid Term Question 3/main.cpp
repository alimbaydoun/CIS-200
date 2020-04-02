#include <iostream>
#include <iomanip>
#include<string>
#include"stack.h"
#include"Header.h"


using namespace std;
void execute(string str, Stack<double>& s)
{
    double num1, num2;
    Operator o;
    string word = "";
    for (auto x : str)
    {
        if (x == ' ' || x == '\t')
        {
            //cout << word << endl;
            if (word != "-" && word != "+" && word != "/" && word != "*")
                s.push(atof(word.c_str()));
            else if (o.isOperationVaild((word.c_str())[0]))
            {
                num1 = s.Top();
                s.pop();
                num2 = s.Top();
                s.pop();
                s.push(o.OperationFunction(num1, num2, (word.c_str())[0]));
            }
            word = "";
        }
        else if (x != '\n')
        {
            word = word + x;
        }
    }
    if (!s.isEmpty())
        cout << fixed << showpoint << setprecision(5) << (s.pop()) << endl;

}

int main()
{

    string expression;
    Stack<double> s;




    while (true)
    {
        cout << "Type in a postfix exexpressionssion(ex: 1 3 + =) or stop to stop: " << endl;
        getline(cin, expression);

        if (expression.compare("stop") == 0 || expression.compare("Stop") == 0) {
            return 0;
        }
        execute(expression, s);
    }
}