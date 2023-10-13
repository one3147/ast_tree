#include <stdio.h>
#include <stdlib.h>

#define MAX_VALUE 2100000000


double add(double a, double b);
double subtract(double a, double b);
double multiply(double a, double b);
double divide(double a, double b);
unsigned int and(unsigned int a, unsigned int b);
unsigned int or(unsigned int a, unsigned int b);
unsigned int xor(unsigned int a, unsigned int b);
unsigned int left_shift(unsigned int a, unsigned int b);
unsigned int right_shift(unsigned int a, unsigned int b);

int main(void) {
    double num1, num2, result_d;
    unsigned int num1_i, num2_i, result_i;
    char operator;

    printf("연산자를 입력하세요 (+, -, *, /, &, |, ^, <, >): ");
    scanf(" %c", &operator);

    if (operator == '&' || operator == '|' || operator == '^' || operator == '<' || operator == '>') {
        printf("두 정수를 입력하세요: ");
        scanf("%u %u", &num1_i, &num2_i);
    } else {
        printf("두 숫자를 입력하세요: ");
        scanf("%lf %lf", &num1, &num2);
    }

    if (operator == '+') {
        result_d = add(num1, num2);
        printf("%.2lf + %.2lf = %.2lf\n", num1, num2, result_d);
    } else if (operator == '-') {
        result_d = subtract(num1, num2);
        printf("%.2lf - %.2lf = %.2lf\n", num1, num2, result_d);
    } else if (operator == '*') {
        result_d = multiply(num1, num2);
        printf("%.2lf * %.2lf = %.2lf\n", num1, num2, result_d);
    } else if (operator == '/') {
        if(num2 != 0.0) {
            result_d = divide(num1, num2);
            printf("%.2lf / %.2lf = %.2lf\n", num1, num2, result_d);
        } else {
            printf("0으로 나눌 수 없습니다.\n");
        }
    } else if (operator == '&') {
        result_i = and(num1_i, num2_i);
        printf("%u & %u = %u\n", num1_i, num2_i, result_i);
    } else if (operator == '|') {
        result_i = or(num1_i, num2_i);
        printf("%u | %u = %u\n", num1_i, num2_i, result_i);
    } else if (operator == '^') {
        result_i = xor(num1_i, num2_i);
        printf("%u ^ %u = %u\n", num1_i, num2_i, result_i);
    } else if (operator == '<') {
        result_i = left_shift(num1_i, num2_i);
        printf("%u << %u = %u\n", num1_i, num2_i, result_i);
    } else if (operator == '>') {
        result_i = right_shift(num1_i, num2_i);
        printf("%u >> %u = %u\n", num1_i, num2_i, result_i);
    } else {
        printf("유효하지 않은 연산자입니다.\n");
    }

    return 0;
}

double add(double a, double b) {
    double result = a + b;
    if (result > MAX_VALUE) {
        printf("수가 너무 큽니다.\n");
        exit(EXIT_FAILURE);
    }
    return result;
}

double subtract(double a, double b) {
    double result = a - b;
    if (result > MAX_VALUE) {
        printf("수가 너무 큽니다.\n");
        exit(EXIT_FAILURE);
    }
    return result;
}

double multiply(double a, double b) {
    double result = a * b;
    if (result > MAX_VALUE) {
        printf("수가 너무 큽니다.\n");
        exit(EXIT_FAILURE);
    }
    return result;
}

double divide(double a, double b) {
    if (b != 0.0) {
        double result = a / b;
        if (result > MAX_VALUE) {
            printf("수가 너무 큽니다.\n");
            exit(EXIT_FAILURE);
        }
        return result;
    } else {
        printf("0으로 나눌 수 없습니다.\n");
        return 0.0;
    }
}

unsigned int and(unsigned int a, unsigned int b) {
    unsigned int result = a & b;
    if (result > MAX_VALUE) {
        printf("수가 너무 큽니다.\n");
        exit(EXIT_FAILURE);
    }
    return result;
}

unsigned int or(unsigned int a, unsigned int b) {
    unsigned int result = a | b;
    if (result > MAX_VALUE) {
        printf("수가 너무 큽니다.\n");
        exit(EXIT_FAILURE);
    }
    return result;
}

unsigned int xor(unsigned int a, unsigned int b) {
    unsigned int result = a ^ b;
    if (result > MAX_VALUE) {
        printf("수가 너무 큽니다.\n");
        exit(EXIT_FAILURE);
    }
    return result;
}

unsigned int left_shift(unsigned int a, unsigned int b) {
    unsigned int result = a << b;
    if (result > MAX_VALUE) {
        printf("수가 너무 큽니다.\n");
        exit(EXIT_FAILURE);
    }
    return result;
}

unsigned int right_shift(unsigned int a, unsigned int b) {
    unsigned int result = a >> b;
    if (result > MAX_VALUE) {
        printf("수가 너무 큽니다.\n");
        exit(EXIT_FAILURE);
    }
    return result;
}
