#include<iostream>
using namespace std;
int main()
{
    int num1, num2;
    char op;
    cout << "Enter two numbers: ";
    cin >> num1 >> num2;
    cout << "Enter an operator (+, -, *, /): ";
    cin >> op;
    switch(op) {
        case '+':
            cout << num1 << " + " << num2 << " = " << num1 + num2;
            break;
        case '-':
            cout << num1 << " - " << num2 << " = " << num1 - num2;
            break;
        case '*':
            cout << num1 << " * " << num2 << " = " << num1 * num2;
            break;
        case '/':
            cout << num1 << " / " << num2 << " = " << num1 / num2;
            break;
        default:
            // If the operator is not one of the specified characters
            cout << "Invalid operator! Please try again.";
            break;
    }
    return 0;
}
