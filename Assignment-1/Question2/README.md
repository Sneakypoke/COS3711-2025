# Banking Transaction Application

## Overview
A Qt-based GUI application for managing banking transactions with real-time tracking and file storage capabilities. Part of [COS3711 Assignment 1](../../README.md).

## Features
- Real-time date and time display
- Deposit and withdrawal transactions
- Transaction history tracking
- Export transactions to file
- Input validation and error handling

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
- Amount input field for transaction values
- Date and time display with automatic updates
- Transaction buttons:
  - Deposit: Add funds
  - Withdraw: Remove funds
  - To file: Save transaction history

### Transaction Operations
1. Enter amount in the input field
2. Click appropriate action button:
   - "Deposit" for adding funds
   - "Withdraw" for removing funds
3. View transaction in history
4. Click "To file" to save all transactions

### Error Handling
- Invalid input validation (negative numbers, non-numeric values)
- Insufficient funds warning
- File operation status messages

## Lessons Learnt
### Design Patterns
- Implementing the Singleton pattern for transaction management
- Understanding the importance of single responsibility principle
- Managing shared resources across the application

### GUI Development
- Creating responsive user interfaces with Qt Widgets
- Implementing real-time updates with signals and slots
- Designing user-friendly input validation

### Data Management
- Maintaining transaction history in memory
- Implementing file I/O for data persistence
- Handling date and time operations

### Error Handling
- Input validation techniques
- User feedback mechanisms
- Exception handling in GUI applications