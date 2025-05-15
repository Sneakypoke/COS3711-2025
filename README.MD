# Building and Running the Projects

## Question 1 - Text Analyzer

Navigate to the Question folder:
```bash
cd Assignment-1/Question1
```

Create Build Directory:
```bash
mkdir build
cd build
```

Build using cmake:
```bash
cmake ..
make
```

Run the analyzer (examples):
```bash
# Analyze file1.txt
./Question1 ../file1.txt

# Analyze file2.txt
./Question1 ../file2.txt

# Analyze with specific options
./Question1 -a -b ../file1.txt    # Count capital words and hyphenated words
./Question1 -c -d ../file2.txt    # Count same start/end and non-vowel start words
```

Quick build (all in one):
```bash
mkdir -p build && cd build && cmake .. && make
```