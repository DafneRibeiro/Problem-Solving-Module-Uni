#include <stdio.h>

int main()
{
  int values[6] = {10, 20, 30, 40, 50, 60};
  printf("Array contents:\n");
  for (int i = 0; i < 6; i++)
  {
    printf("%d\n", values[i]);
  }
}