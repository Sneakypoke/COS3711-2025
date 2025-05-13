#include "operationfactory.h"

OperationFactory& OperationFactory::getInstance() {
    static OperationFactory instance;
    return instance;
}

std::unique_ptr<Operation> OperationFactory::createOperation(const QString& op) const {
    if (op == "+") {
        return std::make_unique<Addition>();
    } else if (op == "-") {
        return std::make_unique<Subtraction>();
    } else if (op == "*") {
        return std::make_unique<Multiplication>();
    } else if (op == "/") {
        return std::make_unique<Division>();
    }
    throw std::runtime_error("Invalid operation");
} 