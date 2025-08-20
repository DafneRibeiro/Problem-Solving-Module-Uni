#include <stdio.h>
int main()
{
  // Marks between 40-49

  // this program calculates the total hours spent on different subjects and prints the results

  // I initialed the variables for the hours spent on each subject
  int math_hours;
  int programming_hours;
  int networking_hours;

  // and assigned them values
  math_hours = 10;
  programming_hours = 30;
  networking_hours = 25;

  int total_hours = math_hours + programming_hours + networking_hours;

  // I used printf to display the total weekly hours
  printf("Total weekly study hours: %d\n", total_hours);
}
