#ifndef OPERATIONFACTORY_H
#define OPERATIONFACTORY_H

#include <QString>
#include <memory>
#include "operation.h"

class OperationFactory {
public:
    static OperationFactory& getInstance();
    std::unique_ptr<Operation> createOperation(const QString& op) const;

private:
    OperationFactory() = default;
    ~OperationFactory() = default;
    OperationFactory(const OperationFactory&) = delete;
    OperationFactory& operator=(const OperationFactory&) = delete;
};

#endif // OPERATIONFACTORY_H 