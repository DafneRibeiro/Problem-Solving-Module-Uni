#include <stdio.h>

int main()
{
  // Fixed-size array with a sentinel
  // Collect temps one-by-one; user can stop early by entering the sentinel.
  // Menu:
  //   1) Display all readings
  //   2) Overall average
  //   3) Highest & lowest
  //   4) Count days above / below-or-equal to a threshold
  //   5) Weekly averages
  //   7) Exit

  const int max_days = 50;
  const double sentinel = -50.0; // sentinel marker making out of realistic range

  double temps[max_days];
  int i;

  // i initialize the array with sentinel to mark empty slots
  for (i = 0; i < max_days; i++)
    temps[i] = sentinel;

  // Asked for user input: collect temperatures one by one up to max_days or until sentinel typed
  printf("Enter daily temperatures one by one (up to %d days).\n", max_days);
  printf("Type %.0f to finish early.\n\n", sentinel);

  int count = 0; // how many active readings we actually have
  while (count < max_days)
  {
    double value;
    printf("Enter temperature for Day %d (or %.0f to stop): ", count + 1, sentinel);

    if (scanf("%lf", &value) != 1)
    {
      // If a non-number is entered it stops
      printf("Invalid input detected. Stopping entry.\n");
      break;
    }

    if (value == sentinel)
    {
      // User chose to finish early
      break;
    }

    temps[count] = value; // store the reading
    count++;
  }

  // Safety: if user entered nothing (count == 0), shows menu but with message
  if (count == 0)
  {
    printf("\nNo readings were entered. You can still open the menu; summaries will reflect zero data.\n");
  }

  // Menu loop
  int choice = 0;
  do
  {
    printf("\n===== Temperature Logger Menu =====\n");
    printf("1) Display all temperature readings\n");
    printf("2) Calculate overall average temperature\n");
    printf("3) Find highest and lowest temperature\n");
    printf("4) Count days above/below a threshold\n");
    printf("5) Weekly average temperature (7 entries per week)\n");
    printf("7) Exit\n");
    printf("Enter your choice: ");

    if (scanf("%d", &choice) != 1)
    {
      printf("Invalid choice. Exiting.\n");
      return 0;
    }

    if (choice == 1)
    {
      // Option 1: display all active readings
      if (count == 0)
      {
        printf("\nNo data to display.\n");
      }
      else
      {
        printf("\nAll temperature readings (%d day%s):\n", count, (count == 1 ? "" : "s"));
        for (i = 0; i < count; i++)
        {
          printf("Day %2d: %.2f\n", i + 1, temps[i]);
        }
      }
    }
    else if (choice == 2)
    {
      // Option 2: overall average
      if (count == 0)
      {
        printf("\nCannot compute average: no readings.\n");
      }
      else
      {
        double sum = 0.0;
        for (i = 0; i < count; i++)
          sum += temps[i];
        double avg = sum / count;
        printf("\nAverage temperature over %d day%s: %.2f\n",
               count, (count == 1 ? "" : "s"), avg);
      }
    }
    else if (choice == 3)
    {
      // Option 3: highest and lowest
      if (count == 0)
      {
        printf("\nCannot compute min/max: no readings.\n");
      }
      else
      {
        double highest = temps[0];
        double lowest = temps[0];
        for (i = 1; i < count; i++)
        {
          if (temps[i] > highest)
            highest = temps[i];
          if (temps[i] < lowest)
            lowest = temps[i];
        }
        printf("\nHighest temperature: %.2f\n", highest);
        printf("Lowest temperature:  %.2f\n", lowest);
      }
    }
    else if (choice == 4)
    {
      // Option 4: threshold counts
      if (count == 0)
      {
        printf("\nNo data to compare against a threshold.\n");
      }
      else
      {
        double threshold;
        printf("\nEnter threshold temperature: ");
        if (scanf("%lf", &threshold) != 1)
        {
          printf("Invalid threshold.\n");
        }
        else
        {
          int above = 0, below_or_equal = 0;
          for (i = 0; i < count; i++)
          {
            if (temps[i] > threshold)
              above++;
            else
              below_or_equal++;
          }
          printf("Days above threshold (%.2f): %d\n", threshold, above);
          printf("Days at or below threshold:   %d\n", below_or_equal);
        }
      }
    }
    else if (choice == 5)
    {
      // Option 5: weekly averages
      if (count == 0)
      {
        printf("\nNo data to compute weekly averages.\n");
      }
      else
      {
        int week = 1;
        int idx = 0;
        printf("\nWeekly averages (7 entries per week):\n");
        while (idx < count)
        {
          int remaining = count - idx;
          int take = (remaining >= 7) ? 7 : remaining;

          double sum = 0.0;
          for (i = 0; i < take; i++)
            sum += temps[idx + i];
          double avg = sum / take;

          if (take == 7)
          {
            printf("Week %d: %.2f\n", week, avg);
          }
          else
          {
            // final partial week
            printf("Week %d (partial, %d day%s): %.2f\n",
                   week, take, (take == 1 ? "" : "s"), avg);
          }

          idx += take;
          week += 1;
        }
      }
    }
    else if (choice == 7)
    {
      printf("Exiting program. Goodbye!\n");
    }
    else
    {
      // Handle invalid menu choices
      printf("Please choose 1, 2, 3, 4, 5, or 7.\n");
    }

  } while (choice != 7);

  return 0;
}