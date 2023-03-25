#include "RPNConverter.h"
#include <iostream>
#include <stack>

struct Expression {
    string expression;
    int priority;
};

void fromRPN() {
    stack <Expression> result;
    string input = "";
    cout<<"Converting an expression from Reverse Polish Notation to infix notation."<<endl;
    cout<<"Write your RPN expression. Each variable and operator should be separated by a single space.\nAt the end of the expression write the word STOP"<<endl;
    cout<<"Your expression: ";
    cin>>input;
    while(input != "STOP") {
        int operatorPriority = findOperatorPriority(input);
        if (operatorPriority != 0) { //operator
            if (result.size() < 2) {
                cout<<" ERROR! YOU PROBABLY WROTE INCORRECT EXPRESSION "<<endl;
                return;
            }
            Expression right = result.top();
            result.pop();
            Expression left = result.top();
            result.pop();
            string expr = left.expression+" ";
            if (left.priority < operatorPriority) {
                expr = "( " +  expr + ") ";
            }
            expr += input + " ";
            if (right.priority < operatorPriority) {
                expr += "( " + right.expression + " ) ";
            } else if ((right.priority == operatorPriority) && (input != "+" && input != "*" && operatorPriority>2)) {
                expr += "( " + right.expression + " ) ";
            } else {
                expr += right.expression + " ";
            }
            result.push(Expression({expr, operatorPriority}));
        } else { //variable
            result.push(Expression({input, 20}));
        }
        cin>>input;
    }
    if (result.size() != 1) {
        cout<<" ERROR! YOU PROBABLY WROTE INCORRECT EXPRESSION "<<endl;
        return;
    }
    cout<<"Expression in infix notation: " + result.top().expression;
}
