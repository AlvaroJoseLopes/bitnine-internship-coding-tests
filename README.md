# Bitnine Internship - Coding tests

This repo contains my solution for the coding tests proposed by Apache AGE Internship Program (Brazil).
The questions are available in this [pdf](Bitnine_Apache_AGE_2023_Internship_Program_Brazil.pdf).


# Solutions summary 

I chose the questions 1 and 2 (backend). 

The solutions are placed in their respective folders with a *README.md* explaining the solution in more details:
- `question1/`
- `question2/`

## How to run

First of all, make sure to have [*gcc*](https://gcc.gnu.org/) compiler installed.

Proceed to the directory of the solution.
```bash
cd question-1/
# or 
cd question-2/
```

**Compile** the code with the following command:
```bash
make
```

**Run** the binary code with the following command:
```bash
make run
```

## Question 1

**Objective**: Write a function that returns fibonacci sequence based on the following arithmetic operations (+, -, *, /) and conditions, using the provided structure.

**Solution summary**: The struct provided will be used to implement a binary expression tree. Each internal node corresponds to the operator and each leaf node corresponds to the operand value. 

For the expression `fib(5*4-10+6)` the corresponding binary expression tree would be:

```
          fib
          / \
         -  NULL
        / \
       *   +
      / \ / \
     5  4 10 6
```

The fibonacci function was implemented using Dynamic Programming.

## Question 2

**Objective:** Implement fibonacci in 3 different ways.

**Solution summary**: Chosen implementations:
- Standard recursive solution;
- Tail recursion fibonacci solution;
- Iterative solution using dynamic programming with optimized space. 