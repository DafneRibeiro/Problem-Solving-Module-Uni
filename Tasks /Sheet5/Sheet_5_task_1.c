#include <stdio.h>

int main()
{
  // Temperature Logger (40–49):
  // - Ask how many days (1..30)
  // - Read one temperature per day into an array
  // - Menu:
  //   1) Display all temperature readings
  //   2) Calculate and display overall average temperature
  //   7) Exit

  const int MAX_DAYS = 30;

  int days = 0;           // how many days we will record (1..30)
  double temps[MAX_DAYS]; // array to store the readings
  int i;                  // loop index (reused below)

  // --- Ask for number of days with validation ---
  while (days < 1 || days > MAX_DAYS)
  {
    printf("How many days do you want to record temperatures for (1-30)? ");
    if (scanf("%d", &days) != 1)
    {
      // If a non-numeric is entered, we stop gracefully.
      // (For simplicity at this level; later we could flush input and retry.)
      printf("Invalid input. Exiting.\n");
      return 0;
    }
    if (days < 1 || days > MAX_DAYS)
    {
      printf("Please enter a number between 1 and %d.\n", MAX_DAYS);
    }
  }

  // --- Read temperatures for each day ---
  for (i = 0; i < days; i++)
  {
    printf("Enter temperature for Day %d: ", i + 1);
    // I store temperatures as double to keep decimals (e.g., 21.75)
    if (scanf("%lf", &temps[i]) != 1)
    {
      printf("Invalid reading. Setting Day %d to 0.0\n", i + 1);
      temps[i] = 0.0;
    }
  }

  // --- Menu loop (options 1, 2, 7) ---
  int choice = 0;
  do
  {
    printf("\n===== Temperature Logger Menu =====\n");
    printf("1) Display all temperature readings\n");
    printf("2) Calculate overall average temperature\n");
    printf("7) Exit\n");
    printf("Enter your choice: ");
    if (scanf("%d", &choice) != 1)
    {
      printf("Invalid choice. Exiting.\n");
      return 0;
    }

    if (choice == 1)
    {
      // Option 1: list all readings with Day labels
      printf("\nAll temperature readings (%d day%s):\n", days, (days == 1 ? "" : "s"));
      for (i = 0; i < days; i++)
      {
        // %.2f shows two decimal places
        printf("Day %2d: %.2f\n", i + 1, temps[i]);
      }
    }
    else if (choice == 2)
    {
      // Option 2: compute and print the average across all recorded days
      double sum = 0.0;
      for (i = 0; i < days; i++)
      {
        sum += temps[i];
      }
      double avg = sum / days; // days is in [1..30], so no divide-by-zero here
      printf("\nAverage temperature over %d day%s: %.2f\n", days, (days == 1 ? "" : "s"), avg);
    }
    else if (choice == 7)
    {
      // Exit option
      printf("Exiting program. Goodbye!\n");
    }
    else
    {
      // Basic validation for the menu
      printf("Please choose 1, 2, or 7.\n");
    }

  } while (choice != 7);

  return 0;
}