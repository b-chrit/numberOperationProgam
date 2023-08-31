# Mathpipe: Simple Number Operations Program

## Overview
Mathpipe is a program that performs various simple operations on input numbers. It reads a jagged array from standard input and applies requested operations on each row, printing the result to standard output. Errors are reported to stderr.

## Usage
```bash
gcc -Wall aggregate.c singular.c mathpipe.c -o mathpipe
cat sample.txt | ./mathpipe <operation> [options]
```

## Operations
Mathpipe supports the following operations:
- `COUNT`: Prints the number of elements in a given array.
- `MIN`: Prints the minimum value in a given array.
- `MAX`: Prints the maximum value in a given array.
- `SUM`: Prints the sum of values in a given array.
- `AVG`: Prints the average value of elements in a given array.
- `PAVG`: Prints the pseudo-average (avg of min and max) of elements in a given array.
- `PRINT`: Prints the numbers in the array.
- `FILTER`: Prints numbers passing a filter criteria.
- `SHIFT`: Adds a value to each element of the array.

## Compilation
Compile the program using:
```bash
gcc -Wall aggregate.c singular.c mathpipe.c -o mathpipe
```

