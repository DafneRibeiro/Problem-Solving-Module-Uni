#include <stdio.h>
int main()
{
  int state = 1;
  int age;
  float fare;

  while (state == 1)
  {
    printf("Enter your age: ");
    int ageInput = scanf("%d", &age);

    // verify age is valid
    if (ageInput != 1 || age < 0)
    {
      printf("Invalid age. Please enter a valid age.\n");
      continue;
    }

    // rules for fare
    if (age < 5)
    {
      fare = 0.0;
      printf("Your fare is: %.2f\n", fare);
    }
    else if (age >= 65)
    {
      fare = 1.0;
      printf("Your fare is: %.2f\n", fare);
    }
    else
    {
      fare = 2.5;
      printf("Your fare is: %.2f\n", fare);
    }

    // ask if the user wants to continue
    printf("Do you want to continue? (1 for yes, 0 for no): ");
    scanf("%d", &state);
    if (state != 1 && state != 0)
    {
      printf("Invalid input. Exiting the program.\n");
      break;
    }

    printf("\n");
  }
  printf("Thank you. Goodbye!\n");
}