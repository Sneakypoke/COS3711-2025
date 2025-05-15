# Text File Analyzer

## Overview
A console application that analyzes text files using regular expressions to find specific word patterns. Part of [COS3711 Assignment 1](../../README.md).

## Features
- Count words longer than 4 letters that start with a capital letter
- Count hyphenated words
- Count words that start and end with the same letter
- Count words not starting with a vowel

## Requirements
- Qt 5.x or Qt 6.x (Core module)
- CMake 3.14 or higher
- C++17 compatible compiler

## Building
```bash
mkdir build && cd build
cmake ..
make
```

## Usage

### Command Format
```bash
./Question1 [options] file1 [file2 ...]
```

### Options
- `-a` : Count words longer than 4 letters that start with a capital
- `-b` : Count hyphenated words
- `-c` : Count words that start and end with the same letter
- `-d` : Count words not starting with a vowel

Options can be used separately (`-a -b`) or combined (`-ab`).

### Examples
```bash
# Analyze single file with all options
./Question1 -abcd input.txt

# Analyze multiple files with specific options
./Question1 -a -b file1.txt file2.txt

# Analyze file with combined options
./Question1 -ac document.txt
```

## Lessons Learnt
### Regular Expressions
- Understanding and implementing Qt's regular expression engine
- Pattern matching for different word characteristics
- Efficient text analysis techniques

### Command Line Interface
- Implementing command-line argument parsing with QCommandLineParser
- Handling multiple input files and command options
- Creating user-friendly CLI interfaces

### File Operations
- File I/O handling using QFile and QTextStream
- Error handling for file operations
- Processing multiple files sequentially

### Qt Core Concepts
- Using Qt's core non-GUI features
- Working with Qt string handling
- Understanding Qt's container classes