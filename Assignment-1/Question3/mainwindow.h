#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDoubleSpinBox>
#include <QPushButton>
#include <QLCDNumber>

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);

private slots:
    void onOperationClicked();
    void onClearClicked();

private:
    QDoubleSpinBox *input1;
    QDoubleSpinBox *input2;
    QLCDNumber *display;
    QPushButton *addButton;
    QPushButton *subtractButton;
    QPushButton *multiplyButton;
    QPushButton *divideButton;
    QPushButton *clearButton;
};

#endif // MAINWINDOW_H 