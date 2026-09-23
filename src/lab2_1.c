#include <stdio.h>

/*
    Task:
    Write a function `int sum_to_n(int n)` that computes
    the sum of all integers from 1 up to n using a for loop.

    In main():
      - Ask user for a positive integer n
      - If n < 1, print an error
      - Otherwise, call sum_to_n and print the result
*/

int sum_to_n(int n){
    //initial sum variable to store the result
    int sum = 0;
    for(int i = 1; i <= n; i++){
        //add each number from 1 to n to the sum
        sum += i;
    }
    //return the final sum
    return sum;
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
    int n = read_int("Enter a positive integer n: ");

    // TODO: validate input, call function, and print result

    if (n < 1) {
        printf("Error: Please enter a positive N.\n");   
        return 1;
    }
    else {
        //otherwise, calculate the sum of numbers from 1 to n and print the result
        int result = sum_to_n(n);
        printf("The sum of numbers from 1 to %d is: %d\n", n, result);
    }
    return 0;
}

