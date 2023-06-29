# Question 1

## Introduction
Write a C program that returns fibonacci sequence based on the following arithmetic operations (+, -, *, /) and conditions, using the provided structure.

## Solution explained

The `Node` struct will be used to implement a binary expression tree. This struct has two fields:
- `TypeTag type`: _enum_ indicating the data type of the node. Can be ADD, SUB, MUL, DIV, FIB and INT. The first 5 are operators and the last one is a operand of type _int_.
- `NodeValue value`: _union_ that stores the value of the node. For operator nodes, the member to be used will be `childs`, another struct with two pointers pointing to the operands (`left` and `right` child nodes). On the other hand, the operand nodes will use the member `int_variable`, that stores the operand value into a _int_ variable.

In the binary expression tree, each internal node corresponds to the operator and each leaf node corresponds to the operand value. For example, the proposed expression `fib(5*4-10+6)` has this binary expression tree:

```
          fib
          / \
         -  NULL
        / \
       *   +
      / \ / \
     5  4 10 6
```

Important functions are:
- `makeFunc()`: takes a `TypeTag` as argument and returns a function pointer, that takes as argument two other nodes (left and right child) and returns a pointer to a new `Node`. This new node represents a operation node specified by the type tag (ADD, MUL, SUB, DIV, FIB).
- `makeIntegerNode()`: takes a integer value as argument and returns a pointer to a new `Node` corresponding to the operand. 
- `calc()`: takes a pointer to a `Node`, that corresponds to the root of the expression tree, and returns the result after evaluating the expression recursively.
- `fibonacci()`: calculates the fibonacci of a number using dynamic programming 

The `main()` function uses the functions above to evaluate the expressions proposed by the question. 

## How to run

In this folder run the following commands:
```
make
make run
```

The makefile also has directives to clean the folder (remove binary code) with `make clean` and `make valgrind` to report memory leak using valgrind.
