#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate  and print a random number between 1 and 100

void generateRandomNumber()
{
  int randomNumber = rand() % 100 + 1; // Generate a number between 1 and 100
  // if I don't add 1, the range will be from 0 to 99
  printf("Generated random number: %d\n", randomNumber);
}

int main()
{
  srand(time(NULL)); // Seed the random number generator
  generateRandomNumber();
  generateRandomNumber();
  generateRandomNumber();
  return 0;
}