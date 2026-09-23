#include <stdio.h>

/*
    Task:
    Write a function `int is_prime(int n)` that returns 1 if n is prime,
    0 otherwise.

    In main():
      - Ask user for an integer n (>= 2)
      - If invalid, print an error
      - Otherwise, print all prime numbers up to n
*/

int is_prime(int n){
    //check if n is less than 2, if so return false (not prime)
    if (n < 2) {
        return 0;
    }
    //check for factors from 2 to the square root of n
    for (int i = 2; i * i <= n; i++) {
        //if n is divisible by any number in this range, it's not prime
        if (n % i == 0) {
            return 0;
        }
    }
    //if no factors were found, n is prime
    return 1;
}

//function to read an integer from user input with a prompt
//DRY principle
int read_int(char* prompt) {
    int n;
    printf("%s", prompt);
    scanf("%d", &n);
    return n;
}

void print_primes(int n) {
    printf("Prime numbers up to %d:\n", n);
    for (int i = 2; i <= n; i++) {
        if (is_prime(i)) {
            printf("%d ", i);
        }
    }
    printf("\n");
}

int main(void) {
    //read integer from user input
    int n = read_int("Enter an integer n (>= 2): ");

    // TODO: validate input and print all primes up to n

    // check if the input is a positive integer greater than 2 (as in requirement)
    if (n < 2) {
        printf("Error: Please enter number greater than 2.\n");   
        return 1;
    }
    else {
        print_primes(n);
    }
    return 0;
}