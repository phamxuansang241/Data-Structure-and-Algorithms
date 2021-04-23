#include<bits/stdc++.h>

using namespace std;

string postfix;

int my_pow(int x, int y) {
    if(y == 0) return 1;
    if(y == 1) return x;

    int res = my_pow(x, y/2);
    res = res*res;

    if(y%2) res = res*x;

    return res;
}
int do_operator(char c, int fi, int se) {
    if(c == '+') return fi+se;
    if(c == '-') return fi-se;
    if(c == '*') return fi*se;
    if(c == '/') return fi/se;
    if(c == '^')
        return my_pow(fi, se);
}

void solve(string s) {
    stack<int> my_stack;

    for(int i = 0;i < s.size();i++) {
        char c = s[i];

        if(c >= '0' && c <= '9')
            my_stack.push(int(c-'0'));
        else {
            int se = my_stack.top();
            my_stack.pop();

            int fi = my_stack.top();
            my_stack.pop();

            int temp = do_operator(c, fi, se);
            my_stack.push(temp);
        }
    }
    cout << "Answer: " << my_stack.top();
}

int main() {
    cout << "Enter the postfix: " << endl;
    cin >> postfix;
    solve(postfix);
    return 0;
}
/*
1233^^-456*+7*-
*/
