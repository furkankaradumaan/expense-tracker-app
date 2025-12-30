#include "InputValidator.h"
#include <iostream>
using namespace std;

string InputValidator::getString(const string& prompt) {
    string input;
    cout << prompt;
    getline(cin, input);
    return input;
}

int InputValidator::getInt(const string& prompt) {
    while (true) {
        string input = getString(prompt);
        try {
            return stoi(input);
        } catch (...) { // catches all exceptions
            cout << "Invalid input. Please enter a valid integer.\n";
        }
    }
}

double InputValidator::getDouble(const string& prompt) {
    while (true) {
        string input = getString(prompt);
        try {
            return stod(input);
        } catch (...) {
            cout << "Invalid input. Please enter a decimal number.\n";
        }
    }
}

string InputValidator::getDate(const string& prompt) {
    while (true) {
        string input = getString(prompt);
        // Simple validation for DD/MM/YYYY length and delimiters
	// Just checks the format, doesn't check is the date is a valid date.
        if (input.length() == 10 && input[2] == '/' && input[5] == '/') {
            return input;
        }
        cout << "Invalid format. Please use DD/MM/YYYY.\n";
    }
}
