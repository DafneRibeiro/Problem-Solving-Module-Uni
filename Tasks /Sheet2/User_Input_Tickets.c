#include <stdio.h>
#include <ctype.h>

// I was researching how to get user input in C and found that the scanf function is used for this purpose. I also learned that it's important to validate the input to ensure it matches the expected format. So I decided to use toupper to convert any lowercase input to uppercase, making the input case-insensitive. This makes the program more user-friendly.

int main()
{
  // This program is an extend of the previous one, where I now ask the user to select the type of ride, ticket, and the number of tickets. Then using a switch statement I will calculate the cost of one ticket and multiply it by the number of tickets to get the total cost. And finally, I will print the total cost to the user.

  char rideType;   // 'T' = Thrill, 'W' = Water, 'F' = Family
  char ticketType; // 'S' = Standard, 'F' = Fast Pass
  int numTickets;
  int ticket_price = 0; // Price of one ticket
  int total_cost = 0;   // ticket_price * numTickets

  // Getting user input
  printf("Select ride type (T = Thrill, W = Water, F = Family): ");
  scanf(" %c", &rideType);
  rideType = toupper(rideType); // Convert to uppercase

  printf("Select ticket type (S = Standard, F = Fast Pass): ");
  scanf(" %c", &ticketType);
  ticketType = toupper(ticketType); // Convert to uppercase

  printf("Enter number of tickets: ");
  scanf("%d", &numTickets);

  // Then I calculate ticket price based on ride type and ticket type for one ticket
  switch (rideType)
  {
  case 'T': // Thrill
    if (ticketType == 'S')
      ticket_price = 20;
    else
      ticket_price = 30; // Fast Pass
    break;
  case 'W': // Water
    if (ticketType == 'S')
      ticket_price = 18;
    else
      ticket_price = 28; // Fast Pass
    break;
  case 'F': // Family
    if (ticketType == 'S')
      ticket_price = 15;
    else
      ticket_price = 25; // Fast Pass
    break;
  default:
    printf("Invalid ride type selected.\n");
    return 1; // Exit the program with an error code
    // this is important just in case the user inputs an invalid value
  }

  // Then I calculate the total cost of the tickets
  total_cost = ticket_price * numTickets;

  // Print total cost
  printf("\nRide Type: ");
  if (rideType == 'T')
    printf("Thrill\n");
  else if (rideType == 'W')
    printf("Water\n");
  else if (rideType == 'F')
    printf("Family\n");

  printf("Ticket Type: ");
  if (ticketType == 'S')
    printf("Standard\n");
  else if (ticketType == 'F')
    printf("Fast Pass\n");

  printf("Number of Tickets: %d\n", numTickets);
  printf("Total Cost: $%d\n", total_cost);
  return 0;
}