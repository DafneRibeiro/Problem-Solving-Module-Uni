#include <stdio.h>

// a function that takes no parameters and returns no value called printTriangle
void printTriangle()
{
  // set rows to 5 and print 1 * for each row
  int i, j;
  int rows = 5;
  for (i = 1; i <= rows; i++)
  {
    // print spaces before the stars
    for (j = 1; j <= i; j++)
    {
      printf("* ");
    }
    printf("\n"); // Move to the next line after printing stars
  }
}
int main()
{
  // call the function to print the triangle
  printTriangle();
  return 0;
}