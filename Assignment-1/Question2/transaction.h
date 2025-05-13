#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <QString>
#include <QDateTime>

enum class TransactionType { Deposit, Withdrawal };

class Transaction {
public:
    Transaction(double amount, const QDateTime& dateTime, TransactionType type);
    double getAmount() const;
    QDateTime getDateTime() const;
    TransactionType getType() const;
    QString toString() const;

private:
    double amount;
    QDateTime dateTime;
    TransactionType type;
};

#endif // TRANSACTION_H 