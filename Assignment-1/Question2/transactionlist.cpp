#include "transactionlist.h"
#include <QFile>
#include <QTextStream>
#include <QDebug>

TransactionList& TransactionList::getInstance() {
    static TransactionList instance;
    return instance;
}

void TransactionList::addTransaction(Transaction* transaction) {
    transactions.append(transaction);
    qDebug() << transaction->toString();
}

QList<Transaction*> TransactionList::getTransactions() const {
    return transactions;
}

void TransactionList::writeToFile(const QString& filename) const {
    QFile file(filename);
    if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        QTextStream out(&file);
        for (const auto& transaction : transactions) {
            out << transaction->toString() << "\n";
        }
        file.close();
    }
}

void TransactionList::printToConsole() const {
    for (const auto& transaction : transactions) {
        qDebug() << transaction->toString();
    }
}

TransactionList::~TransactionList() {
    for (auto transaction : transactions) {
        delete transaction;
    }
} 