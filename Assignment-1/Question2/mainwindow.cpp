#include "mainwindow.h"
#include "transactionlist.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QWidget>
#include <QDateTime>
#include <QMessageBox>
#include <QTimer>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent) {
    QWidget *centralWidget = new QWidget(this);
    setCentralWidget(centralWidget);

    QVBoxLayout *layout = new QVBoxLayout(centralWidget);

    QHBoxLayout *dateLayout = new QHBoxLayout();
    QLabel *dateLabelText = new QLabel("Date:", this);
    dateLabel = new QLabel(QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss"), this);
    dateLayout->addWidget(dateLabelText);
    dateLayout->addWidget(dateLabel);
    layout->addLayout(dateLayout);

    QHBoxLayout *amountLayout = new QHBoxLayout();
    amountLabel = new QLabel("Amount:", this);
    amountEdit = new QLineEdit(this);
    amountEdit->setPlaceholderText("Enter amount");
    amountLayout->addWidget(amountLabel);
    amountLayout->addWidget(amountEdit);
    layout->addLayout(amountLayout);

    QHBoxLayout *buttonLayout = new QHBoxLayout();
    depositButton = new QPushButton("Deposit", this);
    withdrawButton = new QPushButton("Withdraw", this);
    toFileButton = new QPushButton("To file", this);

    buttonLayout->addWidget(depositButton);
    buttonLayout->addWidget(withdrawButton);
    buttonLayout->addWidget(toFileButton);
    layout->addLayout(buttonLayout);

    connect(depositButton, &QPushButton::clicked, this, &MainWindow::onDepositClicked);
    connect(withdrawButton, &QPushButton::clicked, this, &MainWindow::onWithdrawClicked);
    connect(toFileButton, &QPushButton::clicked, this, &MainWindow::onToFileClicked);

    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &MainWindow::updateDateTime);
    timer->start(1000); // Update every second
}

void MainWindow::updateDateTime() {
    dateLabel->setText(QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss"));
}

void MainWindow::onDepositClicked() {
    bool ok;
    double amount = amountEdit->text().toDouble(&ok);
    if (ok && amount > 0) {
        Transaction *transaction = new Transaction(amount, QDateTime::currentDateTime(), TransactionType::Deposit);
        TransactionList::getInstance().addTransaction(transaction);
        amountEdit->clear();
    } else {
        QMessageBox::warning(this, "Invalid Input", "Please enter a valid amount.");
    }
}

void MainWindow::onWithdrawClicked() {
    bool ok;
    double amount = amountEdit->text().toDouble(&ok);
    if (ok && amount > 0) {
        Transaction *transaction = new Transaction(amount, QDateTime::currentDateTime(), TransactionType::Withdrawal);
        TransactionList::getInstance().addTransaction(transaction);
        amountEdit->clear();
    } else {
        QMessageBox::warning(this, "Invalid Input", "Please enter a valid amount.");
    }
}

void MainWindow::onToFileClicked() {
    TransactionList::getInstance().writeToFile("transactions.txt");
    QMessageBox::information(this, "Success", "Transactions written to file.");
} 