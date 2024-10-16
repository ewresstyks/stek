#include <iostream>
#include <string>
using namespace std;

class Stack {
    char* stackArray;
    int maxSize;
    int top;

public:
    Stack(int size) {
        maxSize = size;
        stackArray = new char[maxSize];
        top = -1;
    }

    ~Stack() {
        delete[] stackArray;
    }

    void push(char value) {
        if (top >= maxSize - 1) {
            cout << "Stack overflow." << endl;
            return;
        }
        stackArray[++top] = value;
    }

    char pop() {
        if (isEmpty()) {
            cout << "Stack underflow." << endl;
            return '\0';
        }
        return stackArray[top--];
    }

    bool isEmpty() const {
        return top == -1;
    }
};

bool checkBrackets(const string& expression) {
    Stack stack(expression.length());

    for (int i = 0; i < expression.length(); i++) {
        char ch = expression[i];

        if (ch == '(' || ch == '{' || ch == '[') {
            stack.push(ch);
        }
        else if (ch == ')' char* stackArraych == ']') {
            if (stack.isEmpty()) {
                cout << "Error: closing bracket without opening at position " << i << endl;
                return false;
            }
            char openBracket = stack.pop();
            if ((ch == ')' && openBracket != '(') ||
                (ch == '}' && openBracket != '{') ||
                (ch == ']' && openBracket != '[')) {
                cout << "Error: mismatched brackets at position " << i << endl;
                return false;
            }
        }
    }

    if (!stack.isEmpty()) {
        cout << "Error: not all brackets are closed." << endl;
        return false;
    }

    return true;
}

int main() {
    string expression;
    cout << "Enter an expression: ";
    getline(cin, expression);

    if (checkBrackets(expression)) {
        cout << "The expression is correct!" << endl;
    }
    else {
        cout << "The expression is incorrect!" << endl;
    }
}