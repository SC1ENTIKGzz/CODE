#include <iostream>
#include <stack>
#include <string>
using namespace std ;

bool isValidLatex(const string& s) {
    stack<char> stack;
    for (char c : s) {
        if (c == '{' || c == '(' || c == '[') {
            stack.push(c);
        } else if (c == '}' || c == ')' || c == ']') {
            if (stack.empty()) {
                return false; 
            }
            char top = stack.top();
            stack.pop();
            if ((c == '}' && top != '{') || (c == ')' && top != '(') || (c == ']' && top != '[')) {
                return false; 
            }
        }
    }
    return stack.empty(); 
}

int main() {
    string s;
    getline(cin, s);

    if (isValidLatex(s)) {
        cout << 1 << endl;
    } else {
        cout << 0 << endl;
    }

    return 0;
}
