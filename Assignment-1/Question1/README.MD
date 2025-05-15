# Question 1 - Text File Analyzer

A console application that analyzes text files using regular expressions to find specific word patterns.

## Features

- Count words longer than 4 letters that start with a capital letter
- Count hyphenated words
- Count words that start and end with the same letter
- Count words not starting with a vowel

## Building the Project

Navigate to the project directory:
```bash
cd Assignment-1/Question1
```

Create and enter build directory:
```bash
mkdir build
cd build
```

Build the project:
```bash
cmake ..
make
```

Quick build (all in one):
```bash
mkdir -p build && cd build && cmake .. && make
```

## Usage Examples

1. Run without parameters (uses default files):
```bash
./count
```

2. Analyze a single file:
```bash
./count file1.txt
```

3. Analyze multiple files:
```bash
./count file1.txt fileTwo.txt
```

4. Use separate flags:
```bash
./count -a -b file1.txt fileTwo.txt
```

5. Use combined flags:
```bash
./count -ab -c file1.txt
```

## Flag Options

- `-a` : Count words longer than 4 letters that start with a capital
- `-b` : Count hyphenated words
- `-c` : Count words that start and end with the same letter
- `-d` : Count words not starting with a vowel

Flags can be used separately (`-a -b`) or combined (`-ab`). 