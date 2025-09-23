#include <stdio.h>

int main(void)
{
  // This task is a calendar for a chosen month of 2025.
  // User inputs are the same as previous one, month (1 to 12) and starting weekday (1=Mon to 7=Sun).
  // this program now uses the REAL number of days for 2025 and counts Saturdays/Sundays.

  // Month names 1 to 12
  const char *month_names[12] = {
      "January",
      "February",
      "March",
      "April",
      "May",
      "June",
      "July",
      "August",
      "September",
      "October",
      "November",
      "December"};

  // Real month lengths for 2025 (I checked it is NOT a leap year)
  const int month_days[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

  // Variables for user input
  int month = 0;
  int start_weekday = 0;

  // User Input with basic validation asking again until is invalid
  while (month < 1 || month > 12)
  {
    printf("Enter month number (1-12): ");
    if (scanf("%d", &month) != 1)
      return 0; // early exit on non-numeric input
    if (month < 1 || month > 12)
    {
      printf("Invalid month. Please enter a value from 1 to 12.\n");
    }
  }

  while (start_weekday < 1 || start_weekday > 7)
  {
    printf("Enter starting weekday (1=Mon, 2=Tue, 3=Wed, 4=Thu, 5=Fri, 6=Sat, 7=Sun): ");
    if (scanf("%d", &start_weekday) != 1)
      return 0;
    if (start_weekday < 1 || start_weekday > 7)
    {
      printf("Invalid weekday. Please enter a value from 1 to 7.\n");
    }
  }

  // Number of days for this month in 2025 calculated from month_days array
  int days_in_month = month_days[month - 1];

  // Custom calendar header
  printf("\n+----------------------------------+\n");
  printf("|        %s 2025 Calendar          |\n", month_names[month - 1]);
  printf("+----------------------------------+\n");

  // Weekday header to match 1to 7 mapping
  printf(" Mon Tue Wed Thu Fri Sat Sun\n");

  // Initial padding: spaces before day 1 so it lands under start_weekday
  for (int i = 1; i < start_weekday; i++)
  {
    printf("    "); // 4 spaces align with "%3d " used below
  }

  // Weekend counters
  int saturday_count = 0;
  int sunday_count = 0;

  // Print days and count Saturdays/Sundays in the month
  for (int day = 1; day <= days_in_month; day++)
  {
    // Print the day number right-aligned in width 3
    printf("%3d ", day);

    // Weekday of this 'day' in range 1..7
    int weekday = ((start_weekday - 1) + (day - 1)) % 7 + 1;

    // Count weekends
    if (weekday == 6)
      saturday_count++;
    if (weekday == 7)
      sunday_count++;

    // After Sunday, break line
    if (weekday == 7)
      printf("\n");
  }
  printf("\n");

  // Print a Weekend summary for the month
  printf("Saturdays in %s 2025: %d\n", month_names[month - 1], saturday_count);
  printf("Sundays in %s 2025:   %d\n", month_names[month - 1], sunday_count);

  return 0;
}