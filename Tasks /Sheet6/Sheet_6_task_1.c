#include <stdio.h>

int main()
{
  // Playlist Organizer (40–49)
  // - Store 8 songs in any order (no sorting required)
  // - Loop prints current song and the first song (index 0)

  char playlist[8][50] = {
      "Slayer - Angel of Death",
      "Type O Negative - Black No.1",
      "Alice in Chains - Rooster",
      "Black Sabbath - War Pigs",
      "Slayer - Raining Blood",
      "Type O Negative - Christian Woman",
      "Alice in Chains - Man in the Box",
      "Black Sabbath - Paranoid"};

  for (int i = 0; i < 8; i++)
  {
    printf("Current Song: \"%s\" | First Song: \"%s\"\n", playlist[i], playlist[0]);
  }

  return 0;
}