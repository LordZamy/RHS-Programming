#include<iostream>
#include<cstdio>
#include<stack>
#include<string>

using namespace std;

int T;
// uses a stack to store and obtain last used operator
stack<char> ops;

int main() {
    scanf("%d", &T);

    for(int i = 0; i < T; i++) {
        string S, result = "";

        cin >> S;

        for(int j = 0; j < S.length(); j++) {
            // do nothing if current character is a start bracket
            if(S[j] == '(') continue;

            // if current character is an operator, then push onto stack
            if(S[j] == '+' || S[j] == '-' || S[j] == '*' || S[j] == '/' || S[j] == '^') {
                ops.push(S[j]);
                continue;
            }

            // if current character is an end bracket, then append operator from top of stack to result string
            if(S[j] == ')') {
                result += ops.top();
                ops.pop();
                continue;
            }

            // if current character is a variable, then append to result string
            result += S[j];
        }

        cout << result << "\n";
    }

    return 0;
}
