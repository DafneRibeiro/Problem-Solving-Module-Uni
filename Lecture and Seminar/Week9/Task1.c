#include <stdio.h>

// This task is to print a fibonacci sequence.

// Declare a function to print the fibonacci sequence that returns nothing and takes no parameters.
void printFibonacci()
{
  int n1 = 0, n2 = 1, nextTerm, i;
  int terms = 10; // Number of terms in the Fibonacci sequence
  printf("Fibonacci sequence:\n");
  for (i = 0; i <= terms; ++i)
  {
    printf("%d ", n1);
    nextTerm = n1 + n2; // Calculate the next term
    n1 = n2;            // Update n1 to the next term
    n2 = nextTerm;      // Update n2 to the next term
  }
  printf("\n");
}

int main()
{
  printFibonacci(); // Call the function to print the Fibonacci sequence
  return 0;         // Return 0 to indicate successful execution
}