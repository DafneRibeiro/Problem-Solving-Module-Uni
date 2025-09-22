#include <stdio.h>

int main()
{
  // This program converts the number of steps for one day into calories burned.
  // The specification allows any rate between 0.04 and 0.06 calories per step.
  // I chose 0.04 to match the example given (5000 steps -> 200 calories).

  // I initialize the variables:
  int steps;                        // store steps as integer, since we don’t count half-steps
  const double cal_per_step = 0.04; // fixed conversion rate (calories per step)
  double calories_burned;           // result in calories, can include decimals

  // I then ask for user Input and read the number of steps:
  printf("Enter the number of steps to be converted: ");
  scanf("%d", &steps); // use %d to read an integer

  // Thinking ahead I placed a Small validation:
  // If the user enters a negative number, I convert it to 0, just to avoid invalid results.
  if (steps < 0)
  {
    printf("Steps cannot be negative. Converting to 0.\n");
    steps = 0;
  }

  // I then can proceed with the calculation, Multiplying the steps by the fixed conversion rate (I chose 0.04 as I stated before).
  calories_burned = steps * cal_per_step;

  // Output formatting:
  // Using %.2f to show two decimal places for calories burned.
  printf("Steps: %d\n", steps);
  printf("Calories burned: %.2f calories\n", calories_burned);

  return 0;
}