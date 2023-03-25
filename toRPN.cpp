#include "RPNConverter.h"
#include <iostream>
#include <stack>

using namespace std;

void toRPN() {
    stack<string> operatorsStack;
    string input="", result="";
    cout<<"Conversion of an algebraic expression to its equivalent in Reverse Polish Notation."<<endl;
    cout<<"Write your algebraic expression. Each variable and operator should be separated by a single space.\nAt the end of the expression write the word STOP"<<endl;
    cout<<"Your expression: ";
    cin>>input;
    while (input!="STOP") {
        if (input=="(") {
            operatorsStack.push(input);
        } else if (input==")") {
            if (operatorsStack.empty()) {
                cout<<" ERROR! YOU PROBABLY WROTE INCORRECT EXPRESSION "<<endl;
                return;
            }
            string currOperator = operatorsStack.top();
            while (currOperator != "(") {
                result = result + currOperator + " ";
                operatorsStack.pop();
                if (operatorsStack.empty()) {
                    cout<<" ERROR! YOU PROBABLY WROTE INCORRECT EXPRESSION "<<endl;
                    return;
                }
                currOperator = operatorsStack.top();
            }
            operatorsStack.pop();
        } else { //variable or operator
            int operatorPriority = findOperatorPriority(input);

            if (operatorPriority!=0) { //operator
                while (!operatorsStack.empty()) {
                    string currOperator = operatorsStack.top();
                    if (findOperatorPriority(currOperator) >= operatorPriority) {
                        result = result + currOperator + " ";
                    } else {
                        break;
                    }
                    operatorsStack.pop();
                }
                operatorsStack.push(input);

            } else { //variable
                result = result + input + " ";
            }
        }

        cin>>input;

    }
    while (!operatorsStack.empty()) {
        string currOperator = operatorsStack.top();
        result = result + currOperator + " ";
        operatorsStack.pop();
    }
    cout<<"Expression in Reverse Polish Notation: " + result;
}
