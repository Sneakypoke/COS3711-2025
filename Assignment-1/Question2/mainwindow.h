#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLineEdit>
#include <QPushButton>
#include <QLabel>
#include <QTimer>

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);

private slots:
    void onDepositClicked();
    void onWithdrawClicked();
    void onToFileClicked();
    void updateDateTime();

private:
    QLineEdit *amountEdit;
    QPushButton *depositButton;
    QPushButton *withdrawButton;
    QPushButton *toFileButton;
    QLabel *dateLabel;
    QLabel *amountLabel;
    QTimer *timer;
};

#endif // MAINWINDOW_H 