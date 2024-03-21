# The Knapsack Problem

The Knapsack Problem is a well-known optimization problem in computer science. It involves a knapsack with a fixed capacity and a set of items, each with a specified weight and value. The challenge is to determine the most valuable combination of items that can fit within the knapsack's capacity.

This repository contains a C++ implementation designed to solve the Knapsack Problem using dynamic programming. 

## Input Format

The program expects an input file provided as a command line argument. The input file should be structured as follows:

- The first line contains two integers: the total capacity of the knapsack and the number of items.
- Each subsequent line lists a pair of integers representing the value and weight of each item, respectively.

### Example Input File
```
5 4
500 4
400 2
300 1
450 3
```

## Compilation and Execution

To run this program, you will need to compile the C++ code and execute the resulting executable, passing the path to your input file as a command line argument.
First, ensure you have a C++ compiler (like `g++`) installed on your system. Compile the source code using the following command:

```bash
g++ -o knapsack_solver knapsack.cpp
```

Then execute the program with the following command, replacing `<input_file>` with the path to the desired knapsack configuration:

```
./knapsack_solver <input_file>
```
