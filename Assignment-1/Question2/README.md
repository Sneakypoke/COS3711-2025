# Banking Transaction Application

## Overview
This Qt-based GUI application provides a simple interface for managing banking transactions. Users can perform deposits and withdrawals, with all transactions being tracked and saveable to a file.

## Features
- Real-time date and time display
- Deposit and withdrawal functionality
- Transaction recording
- Export transactions to file
- Input validation for transaction amounts

## Application Structure
The application consists of several key components:

### Main Window (`mainwindow.h`, `mainwindow.cpp`)
- Provides the graphical user interface
- Contains input field for transaction amounts
- Features three action buttons: Deposit, Withdraw, and "To file"
- Displays current date and time with automatic updates

### Transaction Management (`transactionlist.h`)
- Implements the Singleton pattern for managing transactions
- Maintains a list of all transactions
- Provides functionality to save transactions to a file

## Usage
1. **Enter Amount**
   - Type the desired amount in the amount input field

2. **Perform Transaction**
   - Click "Deposit" to add money
   - Click "Withdraw" to remove money
   - Invalid inputs (negative numbers or non-numeric values) will trigger warning messages

3. **Save Transactions**
   - Click "To file" to save all transactions to "transactions.txt"
   - A confirmation message will appear when the file is saved successfully