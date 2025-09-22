#include <stdio.h>
#include <ctype.h> // for toupper

int main()
{
  // This program will apply a discount based on the number of tickets >5.
  // I will also ask the user if they want to add additional services like meal packages costing £6.50 each meal package per ticket.

  char rideType;   // 'T' = Thrill, 'W' = Water, 'F' = Family
  char ticketType; // 'S' = Standard, 'F' = Fast Pass
  int numTickets;
  char addMeal; // 'Y' = Yes, 'N' = No
  int ticket_price = 0;
  double total_before = 0;
  double total_after = 0;
  double meal_price = 6.50;
  double discount = 0.0;

  // Getting user input
  printf("Select ride type (T = Thrill, W = Water, F = Family): ");
  scanf(" %c", &rideType);
  rideType = toupper(rideType);

  printf("Select ticket type (S = Standard, F = Fast Pass): ");
  scanf(" %c", &ticketType);
  ticketType = toupper(ticketType);

  printf("Enter number of tickets: ");
  scanf("%d", &numTickets);

  printf("Do you want to add meal packages for £6.50 each? (Y = Yes, N = No): ");
  scanf(" %c", &addMeal);
  addMeal = toupper(addMeal);

  // Using switch statement to calculate ticket prices
  switch (rideType)
  {
  case 'T': // Thrill
    ticket_price = (ticketType == 'S') ? 20 : 30;
    break;
  case 'W': // Water
    ticket_price = (ticketType == 'S') ? 18 : 28;
    break;
  case 'F': // Family
    ticket_price = (ticketType == 'S') ? 15 : 25;
    break;
  default:
    printf("Invalid ride type selected.\n");
    return 1;
  }
  // I now calculate total before discount by multiplying ticket price by number of tickets
  total_before = ticket_price * numTickets;

  // In this section I apply the discount of 15% if more than 5 tickets
  if (numTickets > 5)
  {
    discount = total_before * 0.15; // 15% discount
  }

  // If the user wants meal packages, I add the cost of meal packages to the total after discount
  if (addMeal == 'Y')
  {
    meal_price = meal_price * numTickets; // Total cost of meal packages
  }

  // here is the total after discount and adding meal packages if any
  total_after = (total_before - discount) + meal_price;

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
  printf("Meal Packages Added: %s\n", (addMeal == 'Y') ? "Yes" : "No");

  printf("Total Cost before Discount: £%.2f\n", total_before);
  printf("Discount Applied: £%.2f\n", discount);
  printf("Meal Package Cost: £%.2f\n", meal_price);
  printf("Total Cost after Discount and Meal Packages: £%.2f\n", total_after);
  return 0;
}