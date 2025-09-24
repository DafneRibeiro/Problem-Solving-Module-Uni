#include <stdio.h>
#include <string.h> // strcmp, strcpy

// print playlist in one line with quotes
void print_playlist(char playlist[][50], int n, const char *label)
{
  printf("%s", label);
  for (int i = 0; i < n; i++)
  {
    printf("%s\"%s\"", (i == 0 ? "" : ", "), playlist[i]);
  }
  printf("\n");
}

int main(void)
{
  // Sort playlist alphabetically with nested loops.
  //  Bands: Slayer, Type O Negative, Alice in Chains, Black Sabbath.

  char playlist[8][50] = {
      "Slayer - Raining Blood",
      "Type O Negative - Christian Woman",
      "Black Sabbath - War Pigs",
      "Alice in Chains - Man in the Box",
      "Type O Negative - Black No.1",
      "Black Sabbath - Paranoid",
      "Slayer - Angel of Death",
      "Alice in Chains - Rooster"};

  const int count = 8;

  // Print before sorting
  print_playlist(playlist, count, "Before sorting: ");

  // Selection sort implementation
  for (int i = 0; i < count - 1; i++)
  {
    int minIndex = i;
    for (int j = i + 1; j < count; j++)
    {
      if (strcmp(playlist[j], playlist[minIndex]) < 0)
      {
        minIndex = j; // found earlier alphabetically
      }
    }

    // Swap if minIndex has changed
    if (minIndex != i)
    {
      char temp[50];
      strcpy(temp, playlist[i]);
      strcpy(playlist[i], playlist[minIndex]);
      strcpy(playlist[minIndex], temp);
    }
  }

  // Print after sorting
  print_playlist(playlist, count, "After sorting:  ");

  return 0;
}