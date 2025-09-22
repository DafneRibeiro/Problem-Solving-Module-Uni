#include <stdio.h>
#include <ctype.h> // toupper for case-insensitive prompts

int main(void)
{
  // In this program, the user can add multiple entries of three types:
  const double cal_per_step = 0.04;  // fixed conversion rate (calories per step)
  const double km_per_step = 0.0008; // distance per step in kilometers

  // Accumulators for the final summary, it increments based on user entries for each type
  long totalSteps = 0;          // only steps added via option 1
  double totalKm = 0.0;         // only distance added via option 3
  double calFromSteps = 0.0;    // calories computed from steps entries
  double calFromDirect = 0.0;   // calories entered directly via option 2
  double calFromDistance = 0.0; // calories estimated from distance entries

  // Loop control variables
  int choice = 0;   // 1=Steps, 2=Calories, 3=Distance
  char again = 'Y'; // 'Y' to add another entry; 'N' to finish

  // I use a do-while so the menu appears at least once
  do
  {
    // Menu display
    printf("Which of these would you like to add to the record?\n");
    printf("1: Steps\n");
    printf("2: Calories\n");
    printf("3: Distance\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    // Conditional handling based on user choice
    if (choice == 1)
    {
      // Option 1: Stepsto Calories using the fixed rate
      long steps;
      printf("\nEnter the number of steps: ");
      scanf("%ld", &steps);

      //
      if (steps < 0)
      {
        printf("Steps cannot be negative. Converting to 0.\n");
        steps = 0;
      }

      // Calculate calories from steps and update accumulators
      double cal = steps * cal_per_step;
      totalSteps += steps;
      calFromSteps += cal;

      printf("Calories burned: %.2f calories\n\n", cal);
    }
    else if (choice == 2)
    {
      // Option 2: Direct Calories
      double cals;
      printf("\nEnter the number of calories burned: ");
      scanf("%lf", &cals);

      if (cals < 0.0)
      {
        printf("Calories cannot be negative. Converting to 0.\n");
        cals = 0.0;
      }

      calFromDirect += cals;

      printf("%.2f calories were added to overall record\n\n", cals);
    }
    else if (choice == 3)
    {
      // Option 3: Distance to Steps to Calories
      double km;
      printf("\nEnter the distance walked (in km): ");
      scanf("%lf", &km);

      if (km < 0.0)
      {
        printf("Distance cannot be negative. Converting to 0.\n");
        km = 0.0;
      }

      // Convert distance to steps using 1 step = 0.0008 km
      double stepsFromKm = km / km_per_step;
      double cal = stepsFromKm * cal_per_step;

      totalKm += km;
      calFromDistance += cal;

      printf("Whilst walking %.2fkm, you have likely burned %.2f calories.\n\n", km, cal);
    }
    else
    {
      // Invalid menu choice to notify and skip to continue prompt
      printf("\nInvalid option. Please choose 1, 2, or 3.\n\n");
    }

    // Ask if the user wants to add another entry
    printf("Do you want to add another entry? (y/n): ");
    scanf(" %c", &again);
    again = (char)toupper((unsigned char)again);
    printf("\n"); // added a blank line for readability

  } while (again == 'Y');

  // Breakdown of all entries and overall calories
  double overallCalories = calFromSteps + calFromDirect + calFromDistance;

  printf("You have entered in total:\n");
  printf("%ld steps (%.2f calories)\n", totalSteps, calFromSteps);
  printf("%.2f calories\n", calFromDirect);
  printf("%.2fkm of distance walked (%.2f calories)\n\n", totalKm, calFromDistance);

  printf("Overall calories burned: %.2f calories\n", overallCalories);

  return 0;
}