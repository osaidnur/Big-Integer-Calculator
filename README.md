# Big Integer Calculator 🧮

A C program that performs arithmetic operations on arbitrarily large integers using doubly linked lists. This implementation can handle numbers far exceeding the limits of standard integer data types.

## 📋 Table of Contents

- [✨ Features](#-features)
- [🔧 How It Works](#-how-it-works)
- [🚀 Installation](#-installation)
- [📖 Usage](#-usage)
- [📁 File Structure](#-file-structure)
- [🔍 Implementation Details](#-implementation-details)
- [📊 Examples](#-examples)
- [👨‍💻 Author](#-author)

## ✨ Features

- **Arbitrary Precision**: Handle integers of unlimited size (limited only by available memory)
- **Four Basic Operations**: Addition, Subtraction, Multiplication, and Division
- **Sign Handling**: Support for both positive and negative numbers
- **File I/O**: Read input from file and write results to output file
- **Interactive Menu**: User-friendly command-line interface
- **Memory Management**: Efficient memory allocation and deallocation
- **Error Handling**: Input validation and error checking

## 🔧 How It Works

The calculator uses **doubly linked lists** to store large integers digit by digit. Each node contains:
- A single digit (0-9)
- Pointer to the next node
- Pointer to the previous node

This data structure allows for:
- Dynamic memory allocation
- Efficient digit-by-digit operations
- Support for numbers of any length

### Key Algorithms

1. **Addition**: Implements carry propagation from right to left
2. **Subtraction**: Uses 9's complement method for efficient calculation
3. **Multiplication**: Grade-school multiplication with carry handling
4. **Division**: Long division algorithm with repeated subtraction

## 🚀 Installation & Running

### Prerequisites
- GCC compiler or any C compiler
- Windows/Linux/macOS operating system

### Quick Start
1. **Compile the program:**
   ```bash
   gcc -o calculator P1_1210733_OsaidNur_1.c
   ```

2. **Run the program:**
   ```bash
   ./calculator
   ```
   
   On Windows:
   ```cmd
   calculator.exe
   ```

> **Note:** The repository includes a sample `input.txt` file with test numbers. You can modify it or create your own with large integers separated by spaces or newlines.

## 📖 Usage

### Input File Format
The `input.txt` file is already included in the repository with sample numbers. You can modify it or add your own large integers separated by spaces or newlines:
```
123456789012345678901234567890
987654321098765432109876543210
555
777
```

### Interactive Menu
1. The program displays all numbers from the input file
2. Choose two numbers (A and B) by entering their positions
3. Select an operation:
   - `1`: Addition (A + B)
   - `2`: Subtraction (A - B)
   - `3`: Multiplication (A × B)
   - `4`: Division (A ÷ B) - returns quotient and remainder
   - `5`: Choose different numbers
   - `6`: Exit

### Output
Results are saved to `output.txt` and displayed on the console.

## 📁 File Structure

```
Big-Integer-Calculator/
├── P1_1210733_OsaidNur_1.c    # Main source code
├── README.md                   # Project documentation
├── project 1.pdf              # Project specifications
├── input.txt                  # Sample input file with test numbers
└── output.txt                 # Output file (generated after running)
```

## 🔍 Implementation Details

### Data Structure
```c
struct node {
    int data;        // Single digit (0-9)
    Node next;       // Pointer to next node
    Node prev;       // Pointer to previous node
};
```

### Core Functions

| Function | Description |
|----------|-------------|
| `new_Node()` | Creates a new node |
| `insert_First()` | Inserts at the beginning |
| `insert_Last()` | Inserts at the end |
| `add()` | Performs addition |
| `subtract()` | Performs subtraction |
| `multiply()` | Performs multiplication |
| `divide()` | Performs division |
| `filter()` | Removes leading zeros |
| `reverse()` | Reverses the linked list |

### Sign Representation
- Positive numbers: Stored as-is
- Negative numbers: First node contains `-3` as a flag

## 📊 Examples

### Example 1: Addition
```
Input: 
A = 123456789
B = 987654321

Output:
Sum = 1111111110
```

### Example 2: Large Number Multiplication
```
Input:
A = 999999999999999999999999999999
B = 888888888888888888888888888888

Output:
Mul = 888888888888888888888888888888111111111111111111111111111112
```

### Example 3: Division with Remainder
```
Input:
A = 123456789
B = 123

Output:
Quotient: 1003723
Remainder: 60
```
---

## 👨‍💻 Author

**Osaid Nur**

