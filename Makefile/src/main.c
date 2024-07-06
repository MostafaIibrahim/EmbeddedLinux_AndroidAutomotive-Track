#include <stdio.h>
#include "calculator.h"

int main() {
    char op;
    int num1, num2;
    double result;

    printf("Enter operation like 3 + 5 : ");
    if (scanf("%d %c %d", &num1, &op, &num2) != 3) {
        printf("Invalid input!\n");
        return 1;
    }

    switch(op) {
        case '+':
            result = add((double)num1, (double)num2);
            break;
        case '-':
            result = subtract((double)num1, (double)num2);
            break;
        case '*':
            result = multiply((double)num1, (double)num2);
            break;
        case '/':
            if (num2 == 0) {
                printf("Error! Division by zero.\n");
                return 1;
            }
            result = divide((double)num1, (double)num2);
            break;
        default:
            printf("Error! Operator is not correct\n");
            return 1;
    }

    printf("%d %c %d = %.2lf\n", num1, op, num2, result);
    return 0;
}
