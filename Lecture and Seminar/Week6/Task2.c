#include <stdio.h>
int main()
{
  // this program will ask the user input for an integer and check if the number is multiple of 3.

  // I initialized the variable for the number to be checked
  int number;

  // I used printf to prompt the user for input
  printf("Enter a number: ");
  scanf("%d", &number);

  // I used if statement to check if the number is a multiple of 3
  if (number % 3 == 0)
  {
    printf("The number %d is a multiple of 3.\n", number);
  }
  else
  {
    printf("The number %d is not a multiple of 3.\n", number);
  }
}