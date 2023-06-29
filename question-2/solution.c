#include <stdio.h>
#include <stdlib.h>


/*
    Recursive solution
    Time complexity:    O(n**2)
    Space complexity:   O(n)    - max depth of recursion tree  

    Caveats: 
        - calculates the fibonacci value of a number multiple times.
        - this recursion implementation cannot be optimized by tail call optimization
        - Bounded by stack frame limit
*/
int fib1(int n) {
    if (n <= 2)
        return n;

    return fib1(n-1) + fib1(n-2);
}



/*
    Tail recursion fibonacci solution. 
    Maintains an accumulator to store the running sum of Fibonacci values as the function recurses. 
    The last thing we do in this function is to call a single recursive call.
    A tail call optimization can transform this single recursive call into a simple loop.
    Time complexity:    O(n)
    Space complecity:   O(1) (considering with tail recursion optimization)
*/

int fib_tail_recursive(int n, int prev, int acc){
    // base case now returns the accumulator
    if (n <= 2)
        return acc;
    else 
        return fib_tail_recursive(n-1, acc, acc + prev);
}

int fib2(int n){
    if (n <= 2) {
        return n;
    }

    return fib_tail_recursive(n, 1, 2);
}

/*
    Iterative solution using dynamic programming with optimized space:
    Time complexity:    O(n)
    Space complexity:   O(1)

    Best implementation. Linear time and constant space complexity.
*/

int fib3(int n){
    if (n <= 2) 
        return n;

    int F_i;
    int F_i_minus_1 = 2;
    int F_i_minus_2 = 1;

    for (int i = 3; i <= n; i++){
        F_i = F_i_minus_1 + F_i_minus_2;
        F_i_minus_2 = F_i_minus_1;
        F_i_minus_1 = F_i;
    }

    return F_i;
}


int main(void){
    int n;
    printf("Enter the number n to be used to calculate fibonacci: ");
    scanf("%d", &n);

    printf("fib1: %d\n", fib1(n));
    printf("fib2: %d\n", fib2(n));
    printf("fib3: %d\n", fib3(n));

    return 0;
}

