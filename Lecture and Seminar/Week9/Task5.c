#include <stdio.h>
// Function to calculate the factorial of a number

void calculateFactorial()
{
  int number, factorial = 1;

  printf("Enter a number: ");
  scanf("%d", &number);

  for (int i = 1; i <= number; i++)
  {
    factorial *= i; // Multiply factorial by i for each iteration
  }
  printf("Factorial of %d = %llu\n", number, factorial);
}

int main()
{
  calculateFactorial(); // Call the function to calculate factorial
  return 0;
}