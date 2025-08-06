#include <stdio.h>

int main()
{

  // This program takes a number from the user and prints the corresponding day of the week.
  // I initialized the variable for the day of the week
  int day;
  // I used printf to prompt the user for input
  printf("Enter a number (1-7): ");
  scanf("%d", &day);

  // I used a switch statement to determine the day of the week based on the input
  // Each case corresponds to a day of the week, with 1 being Sunday and 7 being Saturday
  // I used printf to display the corresponding day of the week
  // I used a default case to handle invalid input
  // I used break statements to exit each case after executing the corresponding code
  // I used return 0 to indicate successful completion of the program
  // I used comments to explain each step of the program
  switch (day)
  {
  case 1:
    printf("Sunday\n");
    break;
  case 2:
    printf("Monday\n");
    break;
  case 3:
    printf("Tuesday\n");
    break;
  case 4:
    printf("Wednesday\n");
    break;
  case 5:
    printf("Thursday\n");
    break;
  case 6:
    printf("Friday\n");
    break;
  case 7:
    printf("Saturday\n");
    break;
  default:
    printf("Invalid input. Please enter a number between 1 and 7.\n");
    break;
  }

  return 0;
}