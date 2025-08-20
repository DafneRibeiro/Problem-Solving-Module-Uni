#include <stdio.h>
int main()
{
  // this program take input n number and use a loop to calculate the sum of even and odd numbers separately, and then print the results. it has a limit of n terms, where n is the number of terms specified by the user.
  int n, number, even_sum = 0, odd_sum = 0;

  // I used printf to prompt the user for input
  printf("Enter how many numbers: ");
  scanf("%d", &n);

  // I used a for loop to iterate through the numbers from 1 to n
  for (int i = 1; i <= n; i++)
  {
    printf("Enter number %d: ", i);
    scanf("%d", &number);

    // I used an if statement to check if the number is even or odd
    // If the number is even, it is added to the even_sum
    // If the number is odd, it is added to the odd_sum
    if (number % 2 == 0) // Check if the number is even
    {
      even_sum += number; // Add to even sum
    }
    else // If the number is odd
    {
      odd_sum += number; // Add to odd sum
    }
  }

  // I used printf to display the results
  printf("Sum of even numbers from 1 to %d: %d\n", n, even_sum);
  printf("Sum of odd numbers from 1 to %d: %d\n", n, odd_sum);

  return 0;
}