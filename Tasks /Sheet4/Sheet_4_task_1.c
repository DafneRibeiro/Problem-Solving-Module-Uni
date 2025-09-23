#include <stdio.h>

int main(void)
{
  // This task is a simple Calendar Printer for a single month of 2025 not a real calendar.
  //  User chooses the month (1–12) and the starting weekday (1 = Mon to 7 = Sun).
  //  A fixed month length of 30 days is used for simplicity.

  // Month names for display;
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

  const int days_in_month = 30; // fixed month legnth

  // Variables for user input
  int month;
  int start_weekday; // starting weekday 1=Mon, 7=Sun

  // ask user for month number from 1 to 12 and store in month variable
  printf("Enter month number (1-12): ");
  scanf("%d", &month);

  // Validate month number to be between 1 and 12
  if (month < 1)
  {
    printf("Month must be between 1 and 12. Adjusting to 1 (January).\n");
    month = 1;
  }
  else if (month > 12)
  {
    printf("Month must be between 1 and 12. Adjusting to 12 (December).\n");
    month = 12;
  }

  // Ask user for starting weekday number from 1 to 7 and store in start_weekday variable
  printf("Enter starting weekday (1=Mon, 2=Tue, 3=Wed, 4=Thu, 5=Fri, 6=Sat, 7=Sun): ");
  scanf("%d", &start_weekday);

  // Validate weekday to be between 1 and 7
  if (start_weekday < 1)
  {
    printf("Weekday must be 1..7. Adjusting to 1 (Monday).\n");
    start_weekday = 1;
  }
  else if (start_weekday > 7)
  {
    printf("Weekday must be 1..7. Adjusting to 7 (Sunday).\n");
    start_weekday = 7;
  }

  // I tried to make the calendar look nice with a border and centered month name
  printf("\n+----------------------------------+\n");
  printf("|        %s 2025 Calendar          |\n", month_names[month - 1]);
  printf("+----------------------------------+\n");

  // Weekday header matches 1..7 Monday to Sunday
  printf(" Mon Tue Wed Thu Fri Sat Sun\n");

  // print leading spaces for the first week before the 1st day
  for (int i = 1; i < start_weekday; i++)
  {
    printf("    ");
  }

  // Print the days of the month
  for (int day = 1; day <= days_in_month; day++)
  {
    printf("%3d ", day);

    // Compute the column of this day relative to Monday (1 to 7).
    // When it hits Sunday (column 7), go to a new line.
    int column = ((start_weekday - 1) + day) % 7;
    if (column == 0)
    {
      printf("\n");
    }
  }
  printf("\n");

  return 0;
}