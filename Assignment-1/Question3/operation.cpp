#include "operation.h"
#include <stdexcept>

double Addition::compute(double a, double b) {
    return a + b;
}

double Subtraction::compute(double a, double b) {
    return a - b;
}

double Multiplication::compute(double a, double b) {
    return a * b;
}

double Division::compute(double a, double b) {
    if (b == 0.0) {
        throw std::runtime_error("Division by zero");
    }
    return a / b;
} 