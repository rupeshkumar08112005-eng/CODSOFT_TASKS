#include <iostream>
using namespace std;

int main() {
    double firstNumber, secondNumber;
    char operation;

    cout << "====================================\n";
    cout << "          SIMPLE CALCULATOR\n";
    cout << "====================================\n";

    cout << "Enter the first number: ";
    if (!(cin >> firstNumber)) {
        cout << "Invalid number.\n";
        return 1;
    }

    cout << "Enter an operator (+, -, *, /): ";
    cin >> operation;

    cout << "Enter the second number: ";
    if (!(cin >> secondNumber)) {
        cout << "Invalid number.\n";
        return 1;
    }

    switch (operation) {
        case '+':
            cout << "Result: " << firstNumber + secondNumber << "\n";
            break;
        case '-':
            cout << "Result: " << firstNumber - secondNumber << "\n";
            break;
        case '*':
            cout << "Result: " << firstNumber * secondNumber << "\n";
            break;
        case '/':
            if (secondNumber == 0) {
                cout << "Error: Division by zero is not allowed.\n";
            } else {
                cout << "Result: " << firstNumber / secondNumber << "\n";
            }
            break;
        default:
            cout << "Invalid operator. Please use +, -, * or /.\n";
    }

    return 0;
}
