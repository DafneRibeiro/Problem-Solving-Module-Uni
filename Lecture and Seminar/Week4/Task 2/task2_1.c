#include <stdio.h>
int main()
{
  int number;
  printf("Enter a number: ");
  scanf("%d", &number);

  for (int i = 1; i <= 10; i++)
  {
    printf("%d * %d = %d\n", number, i, number * i);
  }
}
