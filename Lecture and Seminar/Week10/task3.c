#include <stdio.h>

// this task I need to return the sum of the elements of an array of integers
int sumArray(int arr[], int size)
{
  int sum = 0;
  for (int i = 0; i < size; i++)
  {
    sum += arr[i];
  }
  return sum;
}

int main()
{
  // initialize variables
  int numbers[] = {1, 2, 3, 4, 5, 9, 10};
  int size = sizeof(numbers) / sizeof(numbers[0]); // calculate size of the array
  int total = sumArray(numbers, size);             // call function to get the sum

  printf("The sum of the array elements is: %d\n", total); // print the result

  return 0;
}