#include <stdio.h>
int main()
{
  // This program takes the input for 2 consecutive weeks od study, calculates and print the total study hours for each week, and checks if the study goals were met for both weeks. Compare the total hours of both weeks and print wether study time increased, decreased or remained the same.

  // I initialized the variables for the hours spent on each subject for week 1 and week 2.

  int math_hours_week1, programming_hours_week1, networking_hours_week1;
  int math_hours_week2, programming_hours_week2, networking_hours_week2;

  // I initialized the variables for the weekly study goals
  int study_goal = 40; // Total study goal

  // I used printf to prompt the user for input for week 1
  printf("Enter hours spent on Math for Week 1: ");
  scanf("%d", &math_hours_week1);
  printf("Enter hours spent on Programming for Week 1: ");
  scanf("%d", &programming_hours_week1);
  printf("Enter hours spent on Networking for Week 1: ");
  scanf("%d", &networking_hours_week1);

  // Now I ask the user for input for week 2
  printf("Enter hours spent on Math for Week 2: ");
  scanf("%d", &math_hours_week2);
  printf("Enter hours spent on Programming for Week 2: ");
  scanf("%d", &programming_hours_week2);
  printf("Enter hours spent on Networking for Week 2: ");
  scanf("%d", &networking_hours_week2);

  // I calculate the total hours for week 1 and week 2

  int total_hours_week1 = math_hours_week1 + programming_hours_week1 + networking_hours_week1;
  int total_hours_week2 = math_hours_week2 + programming_hours_week2 + networking_hours_week2;

  // I used printf to display the total weekly hours for both weeks
  printf("Total weekly study hours for Week 1: %d\n", total_hours_week1);
  printf("Total weekly study hours for Week 2: %d\n", total_hours_week2);

  // I used if statements to check if the goals were met for both weeks
  if (total_hours_week1 >= study_goal)
  {
    printf("Congratulations! You have met your weekly study goal of %d hours for Week 1.\n", study_goal);
  }
  else
  {
    printf("You did not meet your weekly study goal for Week 1. You studied a total of %d hours, which is less than the goal of %d hours.\n", total_hours_week1, study_goal);
  }

  if (total_hours_week2 >= study_goal)
  {
    printf("Congratulations! You have met your weekly study goal of %d hours for Week 2.\n", study_goal);
  }
  else
  {
    printf("You did not meet your weekly study goal for Week 2. You studied a total of %d hours, which is less than the goal of %d hours.\n", total_hours_week2, study_goal);
  }

  // I compare the total hours of both weeks and print whether study time increased, decreased or remained the same
  if (total_hours_week2 > total_hours_week1)
  {
    printf("Your study time increased from Week 1 to Week 2.\n");
  }
  else if (total_hours_week2 < total_hours_week1)
  {
    printf("Your study time decreased from Week 1 to Week 2.\n");
  }
  else
  {
    printf("Your study time remained the same from Week 1 to Week 2.\n");
  }
}
