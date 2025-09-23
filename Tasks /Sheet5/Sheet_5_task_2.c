#include <stdio.h>

int main()
{
  // Temperature Logger (50–59):
  // Adds Option 3 (highest & lowest), keeps menu loop until user exits,
  // and handles invalid menu choices cleanly.

  const int MAX_DAYS = 30;

  int days = 0;           // number of days to record (1..30)
  double temps[MAX_DAYS]; // array holding the readings
  int i;                  // loop index

  // --- Ask how many days, with simple validation (range 1..30) ---
  while (days < 1 || days > MAX_DAYS)
  {
    printf("How many days do you want to record temperatures for (1-30)? ");
    if (scanf("%d", &days) != 1)
    {
      // If a non-number is entered, exit gracefully at this level.
      printf("Invalid input. Exiting.\n");
      return 0;
    }
    if (days < 1 || days > MAX_DAYS)
    {
      printf("Please enter a number between 1 and %d.\n", MAX_DAYS);
    }
  }

  // --- Read one temperature per day ---
  for (i = 0; i < days; i++)
  {
    printf("Enter temperature for Day %d: ", i + 1);
    if (scanf("%lf", &temps[i]) != 1)
    {
      // Keep the program resilient: default bad entries to 0.0 and continue.
      printf("Invalid reading. Setting Day %d to 0.0\n", i + 1);
      temps[i] = 0.0;
    }
  }

  // --- Menu loop: runs until the user chooses 7 (Exit) ---
  int choice = 0;
  do
  {
    printf("\n===== Temperature Logger Menu =====\n");
    printf("1) Display all temperature readings\n");
    printf("2) Calculate overall average temperature\n");
    printf("3) Find highest and lowest temperature\n");
    printf("7) Exit\n");
    printf("Enter your choice: ");
    if (scanf("%d", &choice) != 1)
    {
      printf("Invalid choice. Exiting.\n");
      return 0;
    }

    if (choice == 1)
    {
      // Option 1: list all readings with day labels
      printf("\nAll temperature readings (%d day%s):\n", days, (days == 1 ? "" : "s"));
      for (i = 0; i < days; i++)
      {
        printf("Day %2d: %.2f\n", i + 1, temps[i]); // %.2f keeps output tidy
      }
    }
    else if (choice == 2)
    {
      // Option 2: compute and print the average
      double sum = 0.0;
      for (i = 0; i < days; i++)
        sum += temps[i];
      double avg = sum / days; // days >= 1, safe division
      printf("\nAverage temperature over %d day%s: %.2f\n",
             days, (days == 1 ? "" : "s"), avg);
    }
    else if (choice == 3)
    {
      // Option 3: highest and lowest
      // I initialize both with the first reading to avoid fake sentinel values.
      double highest = temps[0];
      double lowest = temps[0];

      for (i = 1; i < days; i++)
      {
        if (temps[i] > highest)
          highest = temps[i];
        if (temps[i] < lowest)
          lowest = temps[i];
      }

      printf("\nHighest temperature: %.2f\n", highest);
      printf("Lowest temperature:  %.2f\n", lowest);
    }
    else if (choice == 7)
    {
      // Exit option
      printf("Exiting program. Goodbye!\n");
    }
    else
    {
      // Graceful handling of unsupported menu options
      printf("Please choose 1, 2, 3, or 7.\n");
    }

  } while (choice != 7);

  return 0;
}