#include <iostream>
#include <stack>
#include <cctype>
using namespace std;
int precedence(char c) {
    if (c == '^') {
        return 3;
    } else if (c == '*' || c == '/') {
        return 2;
    } else if (c == '+' || c == '-') {
        return 1;
    }
    return 0;
}

string infixToPostfix(string& ex) {
    stack<char> st;
    string res = "";

    for (int i = 0; i < ex.length(); i++) {
        char ch = ex[i];

        if (isalnum(ch)) {
            res += ch;
        }
        else if (ch == '(') {
            st.push(ch);
        }
        else if (ch == ')') {
            while (!st.empty() && st.top() != '(') {
                res += st.top();
                st.pop();
            }
            if (!st.empty()) {
                st.pop();
            }
        }
        else {
            while (!st.empty() && st.top() != '(' && precedence(st.top()) >= precedence(ch)) {
                res += st.top();
                st.pop();
            }
            st.push(ch);
        }
    }
    while (!st.empty()) {
        res += st.top();
        st.pop();
    }

    return res;
}
void generateTAC(string postfix) {
    stack<string> st;
    int tempCount = 1;

    cout << "\n--- Generated Three-Address Code (TAC) ---" << endl;

    for (int i = 0; i < postfix.length(); i++) {
        char ch = postfix[i];
        if (isalnum(ch)) {
            string operand(1, ch);
            st.push(operand);
        }
        else {
            if (st.size() < 2) {
                cout << "Error: Invalid Expression" << endl;
                return;
            }

            string op2 = st.top(); st.pop();
            string op1 = st.top(); st.pop();

            string tempVar = "t" + to_string(tempCount++);
            cout << tempVar << " = " << op1 << " " << ch << " " << op2 << endl;
            st.push(tempVar);
        }
    }
}
int main() {
    string ex;
    cout << "Enter Infix Expression: ";
    cin >> ex;

    string postfix = infixToPostfix(ex);
    cout << "Postfix Expression: " << postfix << endl;
    generateTAC(postfix);
    return 0;
}
