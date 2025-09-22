#include <stdio.h>
#include <ctype.h> // toupper to handle case-sensitive errors 'y'/'n'

int main()
{
  // In this program the user can repeat "steps -> calories" for many days if the user chooses to, then prints how many days were tracked and the total calories.

  // I initialize the variables
  const double cal_per_step = 0.04; // I kept the same rate as in the previous task
  int steps;                        // steps for the current day
  double dailyCalories;             // calories for the current day
  double totalCalories = 0.0;       // accumulator across all days
  int dayCount = 0;                 // how many days the user entered
  char answer = 'Y';                // loop control: 'Y' to continue, 'N' to stop

  // I use a do-while loop so the first day is always processed once.
  do
  {
    // Initial input for one day
    printf("Enter the number of steps: ");
    scanf("%d", &steps); // %d reads an integer

    // Basic validation: as previous task, convert negative steps to 0
    if (steps < 0)
    {
      printf("Steps cannot be negative. Converting to 0.\n");
      steps = 0;
    }

    // I proceed doing the conversion for the first day
    dailyCalories = steps * cal_per_step; // steps to calories
    totalCalories += dailyCalories;       // accumulate total
    dayCount++;                           // count this day

    // %d prints steps as integer; %.2f prints calories with two decimals
    printf("Calories burned: %.2f calories\n\n", dailyCalories);

    // I ask again another input from the user, this time I ask whether to add another day
    printf("Do you want to enter steps for another day? (y/n): ");
    scanf(" %c", &answer);
    answer = (char)toupper((unsigned char)answer); // accept 'y' or 'Y'

    printf("\n");
  } while (answer == 'Y');

  // After the loop, I print how many days were tracked and the total calories
  printf("You calculated calories over %d day%s, and the total is %.2f calories burned by walking.\n",
         dayCount, (dayCount == 1 ? "" : "s"), totalCalories);

  return 0;
}