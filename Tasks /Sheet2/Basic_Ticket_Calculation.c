#include <stdio.h>

int main()
{
  // This program creates a park ticket calculator that calculates the total based on user selection. In this section, I will only create the variables to store.

  // I initialized the variables for the tickets
  char ride_type = 'F';   // T for Thrill, W fot Water and F for Family
  int ticket_price = 0;   // This will be calculated based on the ride type and ticket type
  char ticket_type = 'S'; // S for Standard and F for Fast Pass

  // To test the program, as it is not interactive, I will set the ride type and ticket type directly in the code and run the program to see the output.

  // Here I use a switch statement to determine the ticket price based on the ride type and ticket type
  switch (ride_type)
  {
  case 'T': // Thrill Ride
    if (ticket_type == 'S')
    {
      ticket_price = 20;
    }
    else
      ticket_price = 30;
    break;
  case 'W': // Water Ride
    if (ticket_type == 'S')
    {
      ticket_price = 18;
    }
    else
      ticket_price = 28;
    break;
  case 'F': // Family Ride
    if (ticket_type == 'S')
    {
      ticket_price = 15;
    }
    else
      ticket_price = 25;
    break;
  default:
    printf("Invalid ride type selected.\n");
    return 1; // Exit the program with an error code
  }
  // Finally, I print the ticket price, showing ride type and ticket type
  printf("Ride Type: ");
  if (ride_type == 'T')
    printf("Thrill Ride\n");
  else if (ride_type == 'W')
    printf("Water Ride\n");
  else
    printf("Family Ride\n");

  printf("Ticket Type: ");
  if (ticket_type == 'S')
    printf("Standard\n");
  else
    printf("Fast Pass\n");

  printf("Total Ticket Price: $%d.00 \n", ticket_price);

  return 0;
}
