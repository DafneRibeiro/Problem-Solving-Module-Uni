#include <stdio.h>
// in this task i need to define a function to find the maximum of three numbers using if-else statements

int findMax(int a, int b, int c)
{
  int max = a; // this is the max
  if (b > max)
    max = b;
  if (c > max)
    max = c;
  return max;
}

int main()
{
  // initialize variables
  int num1 = 10, num2 = 20, num3 = 15;
  // call function and print results as "The maximum of num1, num2 and num3 is: max"
  printf("The maximum of %d, %d and %d is: %d\n", num1, num2, num3, findMax(num1, num2, num3));
  return 0;
}