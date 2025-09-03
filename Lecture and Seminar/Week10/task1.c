#include <stdio.h>

// this task I need to define a function to calculateInterest(principal, rate, time): compute simple interest using the formula
// simple interest = (principal * rate * time) / 100
// return the computed interest

float calculateInterest(float principal, float rate, float time)
{
  return (principal * rate * time) / 100;
}

int main()
{
  // initialize variables
  float principal1 = 1000, rate1 = 5, time1 = 2;
  float principal2 = 1500, rate2 = 4.5, time2 = 3;

  // call function and print results as "Simple interest 1"
  float interest1 = calculateInterest(principal1, rate1, time1);
  float interest2 = calculateInterest(principal2, rate2, time2);

  printf("Simple interest 1: %.2f\n", interest1);
  printf("Simple interest 2: %.2f\n", interest2);

  // I can do it like this, calling the function and printing in the same line but this is not as clear or following the instructions on the task

  printf("Simple interest 1: %.2f\n", calculateInterest(principal1, rate1, time1));
  printf("Simple interest 2: %.2f\n", calculateInterest(principal2, rate2, time2));

  return 0;
}