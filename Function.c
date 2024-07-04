#include <stdio.h>

// Function Prototype Declarations
double add(double x, double y);
double subtract(double x, double y);
double multiply(double x, double y);
double divide(double x, double y);

int main() {
    // Declare variables
    double num1 = 10.0;
    double num2 = 5.0;

    char operation; // To store the operation type

    printf("Enter operation (+,-,*,/): ");
    scanf("%c", &operation); // Read the operation from the user

    // Function Pointer Declaration
    double (*mathOperation)(double, double);

    switch(operation) {
        case '+':
            mathOperation = add;
            break;
        case '-':
            mathOperation = subtract;
            break;
        case '*':
            mathOperation = multiply;
            break;
        case '/':
            if(num2 != 0.0) { // Check to avoid division by zero
                mathOperation = divide;
            } else {
                printf("Error! Division by zero is not allowed.\n");
                return 1; // Exit the program with error code
            }
            break;
        default:
            printf("Invalid operation entered!\n");
            return 1; // Exit the program with error code
    }

    // Perform the selected operation
    double result = mathOperation(num1, num2);
    printf("Result: %.2lf\n", result);

    return 0;
}

// Function Definitions
double add(double x, double y) {
    return x + y;
}

double subtract(double x, double y) {
    return x - y;
}

double multiply(double x, double y) {
    return x * y;
}

double divide(double x, double y) {
    if(y == 0.0) {
        printf("Error! Division by zero is not allowed.\n");
        return 0.0;
    }
    return x / y;
}
