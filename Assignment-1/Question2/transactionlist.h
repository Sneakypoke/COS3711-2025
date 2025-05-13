#ifndef TRANSACTIONLIST_H
#define TRANSACTIONLIST_H

#include <QList>
#include "transaction.h"

class TransactionList {
public:
    static TransactionList& getInstance();
    void addTransaction(Transaction* transaction);
    QList<Transaction*> getTransactions() const;
    void writeToFile(const QString& filename) const;
    void printToConsole() const;

private:
    TransactionList() = default;
    ~TransactionList();
    TransactionList(const TransactionList&) = delete;
    TransactionList& operator=(const TransactionList&) = delete;
    QList<Transaction*> transactions;
};

#endif // TRANSACTIONLIST_H 