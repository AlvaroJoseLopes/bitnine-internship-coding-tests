# Question 2

## Introduction
Implement fibonacci in 3 different ways.

## Solution explained

Chosen implementations:
- Standard recursive solution;
- Tail recursion fibonacci solution;
- Iterative solution using dynamic programming with optimized space.  

The `main()` function uses the implementations above to calculate the fibonacci of a number provided as input. 


### Solution 1: Standard recursive solution 
Uses a recursive function `fib1()` to calculate the fibonacci of a number.

- Time complexity: $O(n^2)$
- Space complexity: $O(n)$
  
Advantages:
- Intuitive implementation (similar to the fibonacci mathematical definition).
  
Disadvantages:
- Calculates the fibonacci value of a number multiple times;
- Bounded by stack frame limit;
- Cannot be optimized by tail call optimization.

### Solution 2: Tail recursive fibonacci

Tail recursion fibonacci solution `fib3()`. Uses a helper function, `fib_tail_recursive()`, which maintains an accumulator to store the running sum of Fibonacci values as the function recurses. Instead of storing intermediate results in the call stack, the accumulator is updated with the sum of the previous two Fibonacci numbers, and the function then calls itself recursively, passing the updated accumulator and the previous value as parameter.

The last thing that is done in this function is to call a single recursive call. If the compiler supports tail call optimization, the final recursive call can be optimized into a simple loop. This optimization reduces the memory overhead typically associated with recursive function calls and can significantly improve the performance of the algorithm. 

- Time complexity: $O(n)$
- Space complexity: $O(1)$, with tail call optimization. $O(n)$, otherwise.

Advantages:
- Improved standard recursive solution time complexity.
- Can signicantly reduce the space complexity with tail call optimization.
  
Disadvantages:
- Tail call optimization depends on compiler support.
- Requires maintaining an accumulator and recursive call in a specific manner, reducing readability.

### Solution 3: Iterative using DP with optimized space

Uses a iterative function `fib3()` that stores only the two previous fibonacci values (DP memoization). 

- Time complexity: $O(n)$
- Space complexity: $O(1)$
  
Advantages:
- Improved time complexity compared to standard recursive solution;
- Efficient memory usage;
- Doesn't depends on tail call optimization. 
- **Best implementation**.

Disadvantages:
- Requires additional variables and loop constructs, which can make the code less intuitive (reduced readability).

## How to run

In this folder run the following commands:
```
make
make run
```

The makefile also has directives to clean the folder (remove binary code) with `make clean` and `make valgrind` to report memory leak using valgrind.
