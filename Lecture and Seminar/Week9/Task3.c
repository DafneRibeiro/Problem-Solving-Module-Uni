#include <stdio.h>

// Function to check if a number is even or odd
void checkEvenOdd()
{
  int number;
  printf("Enter a number: ");
  scanf("%d", &number);

  if (number % 2 == 0)
  {
    printf("The number %d is even.\n", number);
  }
  else
  {
    printf("The number %d is odd.\n", number);
  }
}

int main()
{
  checkEvenOdd(); // Call the function to check even or odd
  return 0;
}