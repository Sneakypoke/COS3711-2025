# COS3711 Assignments (2025)

## Overview
This repository contains assignments for COS3711, an advanced programming module at UNISA focusing on C++ and Qt development.

## Project Structure
```
Assignment-1/
├── Question1/  # Text File Analyzer
├── Question2/  # Banking Transaction System
└── Question3/  # Calculator Application
```

## Assignment 1
Contains three questions demonstrating different aspects of C++ and Qt:

### Question 1 - Text Analyzer
- Console application for text file analysis
- Regular expression processing
- Command-line argument handling
- [Details](Assignment-1/Question1/README.md)

### Question 2 - Banking Application
- GUI-based transaction management
- File I/O operations
- Singleton pattern implementation
- [Details](Assignment-1/Question2/README.md)

### Question 3 - Calculator
- GUI calculator with arithmetic operations
- Design patterns (Factory, Singleton)
- Object-oriented principles demonstration
- [Details](Assignment-1/Question3/README.md)

## Requirements
- Qt 5.x or Qt 6.x
- CMake 3.14 or higher
- C++17 compatible compiler
- C++ IDE (Qt Creator recommended)

## Building the Projects

Each question follows the same build process using CMake:

```bash
# Replace X with question number (1, 2, or 3)
cd Assignment-1/QuestionX
mkdir build && cd build
cmake ..
make
```