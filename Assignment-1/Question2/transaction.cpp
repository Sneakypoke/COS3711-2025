#include "transaction.h"

Transaction::Transaction(double amount, const QDateTime& dateTime, TransactionType type)
    : amount(amount), dateTime(dateTime), type(type) {}

double Transaction::getAmount() const {
    return amount;
}

QDateTime Transaction::getDateTime() const {
    return dateTime;
}

TransactionType Transaction::getType() const {
    return type;
}

QString Transaction::toString() const {
    QString typeStr = (type == TransactionType::Deposit) ? "Deposit" : "Withdrawal";
    return QString("[%1] %2: R%3").arg(dateTime.toString("yyyy-MM-dd hh:mm:ss")).arg(typeStr).arg(amount, 0, 'f', 2);
} 