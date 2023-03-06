#include <iostream>
#include <stack>
#include <vector>

using namespace std;


int findOperatorPriority(string oper) {
    if (oper=="||") {
        return 1;
    } else if (oper=="&&") {
        return 2;
    } else if (oper=="==" || oper=="!=") {
        return 3;
    } else if (oper==">" || oper=="<" || oper==">=" || oper=="<=") {
        return 4;
    } else if (oper=="+" || oper=="-") {
        return 5;
    } else if (oper=="*" || oper=="/" || oper=="%") {
        return 6;
    } else if (oper=="^") {
        return 7;
    } else if (oper=="sqrt") {
        return 8;
    } else if (oper=="max" || oper=="min") {
        return 9;
    }
    return 0;
}

int main()
{

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
                return 0;
            }
            string currOperator = operatorsStack.top();
            while (currOperator!="(") {
                result = result + currOperator + " ";
                operatorsStack.pop();
                if (operatorsStack.empty()) {
                    cout<<" ERROR! YOU PROBABLY WROTE INCORRECT EXPRESSION "<<endl;
                    return 0;
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
    return 0;
}
