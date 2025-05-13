#ifndef OPERATION_H
#define OPERATION_H

class Operation {
public:
    virtual ~Operation() = default;
    virtual double compute(double a, double b) = 0;
};

class Addition : public Operation {
public:
    double compute(double a, double b) override;
};

class Subtraction : public Operation {
public:
    double compute(double a, double b) override;
};

class Multiplication : public Operation {
public:
    double compute(double a, double b) override;
};

class Division : public Operation {
public:
    double compute(double a, double b) override;
};

#endif // OPERATION_H 