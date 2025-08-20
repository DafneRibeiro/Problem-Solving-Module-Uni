#include <stdio.h>

int main()
{
  // This program creates a park ticket calculator that calculates the total based on user selection. In this section, I will only create the variables to store.

  // I initialized the variables for the tickets
  char ride_type = 'T';   // T for Thrill, W fot Water and F for Family
  int ticket_price = 0;   // This will be calculated based on the ride type and ticket type
  char ticket_type = 'S'; // S for Standard and F for Fast Pass

  // Here I will calculate the price based on the choice of ride and type of ticket. Here I will hardcode the prices as requested (fixed values).
  if (ride_type == 'T')
  {
    if (ticket_type == 'S')
      ticket_price = 50; // Standard
    else
      ticket_price = 70; // Fast Pass
  }
  else if (ride_type == 'W')
  {
    if (ticket_type == 'S')
      ticket_price = 40; // Standard
    else
      ticket_price = 60; // Fast Pass
  }
  else if (ride_type == 'F')
  {
    if (ticket_type == 'S')
      ticket_price = 30; // Standard
    else
      ticket_price = 50; // Fast Pass
  }
  return 0;
}