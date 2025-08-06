#include <stdio.h>

int main()
{
  int values[6] = {10, 20, 30, 40, 50, 60};
  int index, newValue;

  printf("Array contents:\n");
  for (int i = 0; i < 6; i++)
  {
    printf("%d\n", values[i]);
  }

  printf("Enter the index to modify (0-5): ");
  scanf("%d", &index);

  if (index < 0 || index > 5)
  {
    printf("Invalid index.\n");
    return 1;
  }

  printf("Enter the new value: ");
  scanf("%d", &newValue);

  values[index] = newValue;

  printf("Updated array contents:\n");
  for (int i = 0; i < 6; i++)
  {
    printf("%d\n", values[i]);
  }

  return 0;
}