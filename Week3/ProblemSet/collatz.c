#include <stdio.h>

int collatz(int n);
int sum = 0;

int main (void){
    // Get a number from the user
    int n;
    printf("Enter a number: ");
    scanf("%d", &n);

    if (collatz(n) == 1){
        printf("Number returned to 1 in %i steps.\n", sum);
    }
}

// Recursive function
int collatz(int n){
    // Base case
    if (n==1)
    {
        return 1;
    }

    sum++;

    // Recursive cases
    if (n % 2 == 0){
        collatz(n / 2);
    }
    else if (n % 2 == 1){
        collatz(3 * n + 1);
    }
    else {
        printf("Error processing!\n");
    }       
}