# Qt Calculator Application

## Overview
This Qt-based calculator application demonstrates various Object-Oriented Programming concepts, design patterns, and Qt framework features.

## Features
- Basic arithmetic operations (Addition, Subtraction, Multiplication, Division)
- User-friendly GUI with input validation
- Error handling (division by zero, overflow)
- Clear function to reset inputs and display
- Decimal number support with configurable precision

## Build Steps
```bash
mkdir build
cd build
cmake ..
make
```

## Usage Instructions
1. Enter first number in top input field
2. Enter second number in bottom input field
3. Click operation button (+, -, *, /)
4. Result appears in LCD display
5. Click 'Clear' to reset all fields

## Error Handling
- "Division by zero" when attempting to divide by zero
- "Overflow" when result exceeds display capacity
- "Invalid operation" for unsupported operations

## Implementation Details

### Design Patterns
1. **Singleton Pattern** (OperationFactory)
   - Ensures single instance throughout application
   - Thread-safe initialization
   - Prevents multiple instantiation through private constructor
   - Deleted copy operations for safety

2. **Factory Method Pattern**
   - Centralized object creation in OperationFactory
   - Creates operation objects based on user input
   - Extensible design for adding new operations
   - Returns operations as smart pointers

### Object-Oriented Concepts
1. **Abstract Base Class** (Operation)
   - Defines interface through pure virtual compute() method
   - Enables polymorphic behavior
   - Provides common interface for all operations

2. **Inheritance Hierarchy**
   - Concrete classes: Addition, Subtraction, Multiplication, Division
   - Each implements compute() with override keyword
   - Specialized behavior for each operation