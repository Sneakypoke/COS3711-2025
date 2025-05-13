#include "mainwindow.h"
#include "operationfactory.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QMessageBox>
#include <QWidget>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent) {
    QWidget *centralWidget = new QWidget(this);
    setCentralWidget(centralWidget);

    QVBoxLayout *mainLayout = new QVBoxLayout(centralWidget);

    // Input fields
    input1 = new QDoubleSpinBox(this);
    input2 = new QDoubleSpinBox(this);
    input1->setRange(-999999.99, 999999.99);
    input2->setRange(-999999.99, 999999.99);
    input1->setDecimals(2);
    input2->setDecimals(2);

    // Display
    display = new QLCDNumber(this);
    display->setDigitCount(10);
    display->setMode(QLCDNumber::Dec);
    display->setSegmentStyle(QLCDNumber::Flat);

    // Operation buttons
    QHBoxLayout *buttonLayout = new QHBoxLayout();
    addButton = new QPushButton("+", this);
    subtractButton = new QPushButton("-", this);
    multiplyButton = new QPushButton("*", this);
    divideButton = new QPushButton("/", this);
    clearButton = new QPushButton("Clear", this);

    buttonLayout->addWidget(addButton);
    buttonLayout->addWidget(subtractButton);
    buttonLayout->addWidget(multiplyButton);
    buttonLayout->addWidget(divideButton);
    buttonLayout->addWidget(clearButton);

    // Add widgets to main layout
    mainLayout->addWidget(input1);
    mainLayout->addWidget(input2);
    mainLayout->addWidget(display);
    mainLayout->addLayout(buttonLayout);

    // Connect signals and slots
    connect(addButton, &QPushButton::clicked, this, &MainWindow::onOperationClicked);
    connect(subtractButton, &QPushButton::clicked, this, &MainWindow::onOperationClicked);
    connect(multiplyButton, &QPushButton::clicked, this, &MainWindow::onOperationClicked);
    connect(divideButton, &QPushButton::clicked, this, &MainWindow::onOperationClicked);
    connect(clearButton, &QPushButton::clicked, this, &MainWindow::onClearClicked);

    // Set window properties
    setWindowTitle("Calculator");
    resize(300, 200);
}

void MainWindow::onOperationClicked() {
    QPushButton *button = qobject_cast<QPushButton*>(sender());
    if (!button) return;

    try {
        auto operation = OperationFactory::getInstance().createOperation(button->text());
        double result = operation->compute(input1->value(), input2->value());
        
        // Check for overflow
        if (result > 999999.99 || result < -999999.99) {
            QMessageBox::warning(this, "Overflow", "Result exceeds display limit");
            display->display(0);
        } else {
            display->display(result);
        }
    } catch (const std::runtime_error& e) {
        QMessageBox::warning(this, "Error", e.what());
        display->display(0);
    }
}

void MainWindow::onClearClicked() {
    input1->setValue(0);
    input2->setValue(0);
    display->display(0);
} 