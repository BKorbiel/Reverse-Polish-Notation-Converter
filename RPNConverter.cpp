#include <iostream>
#include "RPNConverter.h"

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
    }
    return 0;
}

int main(){
    cout<<"Choose:"<<endl;
    cout<<"1 - Convert from RPN to infix notation"<<endl;
    cout<<"2 - Convert from infix notation to RPN"<<endl;
    char choice;
    cin>>choice;
    if (choice=='1') {
        fromRPN();
    } else if (choice=='2') {
        toRPN();
    } else {
        cout<<"Incorrect input"<<endl;
    }
    return 0;
}
