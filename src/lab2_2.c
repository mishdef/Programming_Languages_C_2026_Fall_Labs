#include <stdio.h>

/*
    Task:
    Write a function `long long factorial(int n)` that computes n!
    using a loop (not recursion).

    In main():
      - Ask user for an integer n
      - If n is negative, print an error and exit
      - Otherwise, call factorial and print the result
*/

//using long long to handle larger factorials (prevents crash for larger numbers)
long long factorial(int n){
    long long fact = 1;
    // calculate factorial of n using a loop
    for (int i = 1; i <= n; i++) {
        fact *= i;
    }
    return fact;
}

//function to read an integer from user input with a prompt
//DRY principle
int read_int(char* prompt) {
    int n;
    printf("%s", prompt);
    scanf("%d", &n);
    return n;
}

int main(void) {
    //read integer from user input
    int n = read_int("Enter a non-negative integer n: ");

    // TODO: validate input, call function, print result
    // check if the input is a positive integer (as in requirement)
    if (n < 0) {
        printf("Error: Please enter a positive N \n");   
        return 1;
    }
    else {
        //otherwise, calculate the factorial of n and print the result
        long long result = factorial(n);
        printf("The factorial of %d is: %lld\n", n, result);
    }
    return 0;
}
