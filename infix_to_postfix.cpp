#include<bits/stdc++.h>

using namespace std;

string infix;

int prior(char c) {
    if(c == '^') return 1;
    if(c == '*' || c == '/') return 2;
    if(c == '+' || c == '-') return 3;
}

void solve(string s) {
    stack<char> my_stack;
    string res = "";

    for(int i = 0;i < s.size();i++) {
        char c = s[i];

        if((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9'))
            res = res + c;
        else if(c == '(')
            my_stack.push(c);
        else if(c == ')') {
            while(my_stack.top() != '(') {
                res = res + my_stack.top();
                my_stack.pop();
            }
            my_stack.pop();
        }
        else {
            while(!my_stack.empty() && prior(c) >= prior(my_stack.top())) {
                res = res + my_stack.top();
                my_stack.pop();
            }
            my_stack.push(c);
        }
    }

    while(!my_stack.empty()) {
        res = res + my_stack.top();
        my_stack.pop();
    }

    cout << "The postfix is: " << endl;
    cout << res << endl;
}


int main() {
    cout << "Enter the infix: " << endl;
    cin >> infix;
    solve(infix);

    return 0;
}
/*
1-2^(3^3)-(4+5*6)*7
*/
