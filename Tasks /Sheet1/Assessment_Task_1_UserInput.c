#include <stdio.h>
int main()
{
  // This program takes input from the user for each subject, and based on weekly study goals, compares the hours spent with the goals and prints whether the goals were met or not.

  // I initialized the variables for the hours spent on each subject
  int math_hours;
  int programming_hours;
  int networking_hours;

  // I initialized the variables for the weekly study goals
  int study_goal = 45; // Total study goal

  // I understand that the study goal is not required in the task instructions to be input by the user, so I set it as a constant value, but it can be modified if needed.

  // I used printf to prompt the user for input
  printf("Enter hours spent on Math: ");
  scanf("%d", &math_hours);
  printf("Enter hours spent on Programming: ");
  scanf("%d", &programming_hours);
  printf("Enter hours spent on Networking: ");
  scanf("%d", &networking_hours);

  // I used if statements to check if the goals were met
  int total_hours = math_hours + programming_hours + networking_hours;

  printf("Total weekly study hours: %d\n", total_hours);

  if (total_hours >= study_goal)
  {
    printf("Congratulations! You have met your weekly study goal of %d hours.\n", study_goal);
  }
  else
  {
    printf("You did not meet your weekly study goal. You studied a total of %d hours, which is less than the goal of %d hours.\n", total_hours, study_goal);
  }
}
