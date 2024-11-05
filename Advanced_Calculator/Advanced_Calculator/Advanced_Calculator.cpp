#include <iostream>
#include <cmath>        // For advanced operations like sqrt, sin, cos, tan
#include <limits>       // For input validation
#include <cstdlib>      // For std::exit (to quit the program)

using namespace std;

// calculate factorial
long long factorial(int n) {
    if (n < 0) {
        throw invalid_argument("Factorial is not defined for negative numbers.");
    }
    long long result = 1;
    for (int i = 1; i <= n; ++i) {
        result *= i;
    }
    return result;
}

// basic operations (addition, subtraction, multiplication, division)
double basicOperation(double num1, double num2, char op) {
    switch (op) {
    case '+':
        return num1 + num2;
    case '-':
        return num1 - num2;
    case '*':
        return num1 * num2;
    case '/':
        if (num2 == 0) {
            throw runtime_error("Error! Division by zero.");
        }
        return num1 / num2;
    default:
        throw invalid_argument("Invalid operator.");
    }
}

// trigonometric operations
double trigonometricOperation(double num, char op) {
    switch (op) {
    case 's': // Sine
        return sin(num);
    case 'c': // Cosine
        return cos(num);
    case 't': // Tangent
        if (cos(num) == 0) {
            throw runtime_error("Error! Tangent undefined at this angle.");
        }
        return tan(num);
    default:
        throw invalid_argument("Invalid trigonometric operator.");
    }
}

// square root
double squareRoot(double num) {
    if (num < 0) {
        throw runtime_error("Error! Square root of a negative number is not allowed.");
    }
    return sqrt(num);
}

// input validation for numbers
double getNumberInput() {
    double number;
    while (true) {
        cout << "Enter a number: ";
        cin >> number;
        if (cin.fail()) {
            cin.clear(); // clear the error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // discard invalid input
            cout << "Invalid input! Please enter a valid number." << endl;
        }
        else {
            return number;
        }
    }
}

// display the menu
void displayMenu() {
    cout << "\n--- Simple Calculator with Advanced Operations ---\n";
    cout << "1. Basic Operations (+, -, *, /)\n";
    cout << "2. Square Root\n";
    cout << "3. Factorial\n";
    cout << "4. Trigonometric Functions (sin, cos, tan)\n";
    cout << "5. Exit\n";
}

int main() {
    while (true) {
        displayMenu();
        int choice;
        cout << "Enter your choice (1-5): ";
        cin >> choice;

        try {
            switch (choice) {
            case 1: {
                double num1 = getNumberInput();
                double num2 = getNumberInput();
                char op;
                cout << "Enter operator (+, -, *, /): ";
                cin >> op;
                double result = basicOperation(num1, num2, op);
                cout << "Result: " << result << endl;
                break;
            }
            case 2: {
                double num = getNumberInput();
                double result = squareRoot(num);
                cout << "Square Root: " << result << endl;
                break;
            }
            case 3: {
                int num;
                cout << "Enter an integer for factorial: ";
                cin >> num;
                long long result = factorial(num);
                cout << "Factorial: " << result << endl;
                break;
            }
            case 4: {
                double num = getNumberInput();
                char op;
                cout << "Enter trigonometric operation (s for sin, c for cos, t for tan): ";
                cin >> op;
                double result = trigonometricOperation(num, op);
                cout << "Result: " << result << endl;
                break;
            }
            case 5:
                cout << "Exiting the program. Goodbye!" << endl;
                return 0;
            default:
                cout << "Invalid choice. Please select a valid option." << endl;
            }
        }
        catch (const exception& e) {
            cout << "Error: " << e.what() << endl;
        }
    }

    return 0;
}
