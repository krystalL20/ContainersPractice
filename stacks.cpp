#include <iostream>
#include <set>
#include <stack>
#include <string>
#include <vector>

using namespace std;

enum TokenType {
    OPERATOR,
    OPERAND,
};

set<string> VALID_OPS{"+", "-", "*", "/"};

TokenType tokenType(string s) {
    if ((VALID_OPS.count(s.substr(0, 1)) != 0)) {
        return OPERATOR;
    } else {
        return OPERAND;
    }
}

double apply(string op, double v1, double v2) {
    if (op == "+")
        return (v1 + v2);
    if (op == "-")
        return (v1 - v2);
    if (op == "*")
        return (v1 * v2);
    if (op == "/")
        return (v1 / v2);
    return 0.0; // Just to avoid no-return warning
}

vector<string> tokenize(string expression) {
    vector<string> result;
    int tokenStart = 0;
    int i = 0;
    while (i < expression.size()) {
        if (expression.substr(i, 1) == " ") {
            result.push_back(expression.substr(tokenStart, i - tokenStart));
            tokenStart = i + 1;
        }
        i++;
    }
    return result;
}

double eval(string expression) {

    double result = 0;
    stack<double> eStack;
    vector<string> tokens  = tokenize(expression);
    for (string nextToken : tokens) {
        switch (tokenType(nextToken)) {
            case OPERAND:
                eStack.push(stod(nextToken));
                break;
            case OPERATOR:
                double op2 = eStack.top();
                eStack.pop();
                double op1  = eStack.top();
                eStack.pop();
                eStack.push(apply(nextToken,op1,op2));\
                break;
        }
    }
    result = eStack.top();
    eStack.pop();
    return result;

}

int main() {

    string expression = "5.0 3.0 + 2.0 * 2.0 * 7 - 2 * ";

    cout << "5.0 3.0 + 2.0 * 2.0 * 7 - 2 *  -> " << eval(expression) << endl;

}
