
#include <iostream>

// Function prototypes
double add(double num1, double num2);
double subtract(double num1, double num2);
double multiply(double num1, double num2);
double divide(double num1, double num2);

int main() {
    double num1, num2;
    int choice;

    // Display menu
    std::cout << "Simple Calculator\n";
    std::cout << "1. Addition\n";
    std::cout << "2. Subtraction\n";
    std::cout << "3. Multiplication\n";
    std::cout << "4. Division\n";
    std::cout << "Enter your choice (1-4): ";
    std::cin >> choice;

    // Input numbers
    std::cout << "Enter first number: ";
    std::cin >> num1;
    std::cout << "Enter second number: ";
    std::cin >> num2;

    // Perform operation
    switch (choice) {
        case 1:
            std::cout << "Result: " << add(num1, num2) << std::endl;
            break;
        case 2:
            std::cout << "Result: " << subtract(num1, num2) << std::endl;
            break;
        case 3:
            std::cout << "Result: " << multiply(num1, num2) << std::endl;
            break;
        case 4:
            if (num2 != 0)
                std::cout << "Result: " << divide(num1, num2) << std::endl;
            else
                std::cout << "Error: Division by zero!" << std::endl;
            break;
        default:
            std::cout << "Invalid choice!" << std::endl;
    }

    return 0;
}

// Function definitions
double add(double num1, double num2) {
    return num1 + num2;
}

double subtract(double num1, double num2) {
    return num1 - num2;
}

double multiply(double num1, double num2) {
    return num1 * num2;
}

double divide(double num1, double num2) {
    return num1 / num2;
}
