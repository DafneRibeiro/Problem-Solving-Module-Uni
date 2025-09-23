#include <stdio.h>
#include <string.h> // strcmp, strcpy

// Helper: print playlist in one line, quoted and comma-separated
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
  // Task 6 (50–59): single pass that can move the alphabetically earliest title to index 0.
  // No output during the loop. Print BEFORE and AFTER only.

  // Any starting order is fine for this step.
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

  // Print BEFORE (required)
  print_playlist(playlist, count, "Before single pass: ");

  // --- Single pass: compare each title to index 0; swap if earlier alphabetically ---
  // Nothing is printed inside this loop (per requirements).
  for (int i = 1; i < count; i++)
  {
    if (strcmp(playlist[i], playlist[0]) < 0)
    {
      // Swap playlist[i] with playlist[0]
      char temp[50];
      strcpy(temp, playlist[i]);
      strcpy(playlist[i], playlist[0]);
      strcpy(playlist[0], temp);
    }
  }

  // Print AFTER (required)
  print_playlist(playlist, count, "After single pass:  ");

  return 0;
}