#include <iostream>
#include <stack>
using namespace std;

bool check(string arr) {
    stack<char> s;

    for (int i = 0; i < arr.size(); i++) {
        char ch = arr[i];

        if (ch == '(' || ch == '+' || ch == '-' || ch == '/' || ch == '*') {
            s.push(ch);
        } else if (ch == ')') {
            bool hasOperator = false;
            while (!s.empty() && s.top() != '(') {
                char top = s.top();
                if (top == '+' || top == '-' || top == '/' || top == '*') {
                    hasOperator = true;
                }
                s.pop();
            }
            if (!s.empty() && s.top() == '(') {
                s.pop(); 
            }
            if (!hasOperator) {
                return true; 
            }
        }
    }
    return false;
}

int main() {
    string str = "(a+b)";
    if (check(str)) {
        cout << "Redundant brackets";
    } else {
        cout << "No redundant brackets";
    }

    return 0;
}
