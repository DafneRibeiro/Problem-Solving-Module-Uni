#include <stdio.h>
int main()
{
  int number;
  int sum = 0;

  printf("Enter a positive integer: ");
  scanf("%d", &number);

  for (int i = 1; i <= number; i++)
  {
    sum += i;
  }

  printf("The sum of natural numbers from 1 to %d is %d\n", number, sum);

  return 0;
}
