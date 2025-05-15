# Calculator Application

## Overview
A Qt-based calculator application demonstrating object-oriented programming concepts and design patterns. Part of [COS3711 Assignment 1](../../README.md).

## Features
- Basic arithmetic operations (Addition, Subtraction, Multiplication, Division)
- User-friendly GUI with input validation
- Error handling (division by zero, overflow)
- Clear function to reset inputs
- Decimal number support with configurable precision

## Requirements
- Qt 5.x or Qt 6.x (Core and Widgets modules)
- CMake 3.14 or higher
- C++17 compatible compiler

## Building
```bash
mkdir build && cd build
cmake ..
make
```

## Usage

### Main Window
- Two input fields for operands
- LCD display for results
- Operation buttons (+, -, *, /)
- Clear button to reset

### Calculator Operations
1. Enter first number in top input
2. Enter second number in bottom input
3. Click operation button
4. View result in LCD display
5. Use Clear to reset all fields

### Error Handling
- Division by zero protection
- Overflow detection and warning
- Invalid operation handling

## Lessons Learnt
### Object-Oriented Design
- Implementing abstract base classes and interfaces
- Understanding polymorphism through operation classes
- Using the override keyword for method safety
- Applying inheritance for specialized behavior

### Design Patterns
- Implementing the Factory Method pattern for operation creation
- Using the Singleton pattern for centralized management
- Understanding pattern combinations and interactions
- Managing object lifecycle with smart pointers

### Modern C++ Features
- Working with smart pointers (std::unique_ptr)
- Understanding move semantics
- Implementing exception-safe code
- Using C++17 features effectively

### Qt GUI Development
- Creating calculator interfaces with Qt Widgets
- Managing user input and display updates
- Implementing responsive error handling
- Using Qt's signal and slot mechanism