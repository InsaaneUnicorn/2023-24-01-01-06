#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>

int playagain = 0;

int main() {
  int playagain = 0;
  do { 
    srand(time(NULL));
    printf("Welcome to Hang Waites! ");
    // Get word to guess
    char wordBank[6][50] = {"Alternating_Current","Access_Control_List","Advanced_Encryption_Standard","All_In_One", "Compact_Disc", "Automatic_Private_Internet_Protocol_Addressing"};
    char answer[128];
    strcpy(answer, wordBank[rand() % 6]);
    //printf("Enter word to guess: ");
    fflush(stdout);
  
    // Set the mask array - mask[i] is true if the
    // character s[i] has been guessed.  The mask
    // must be allocated, and initialized to all false
    int N = strlen(answer);
    int mask[N];
    for (int i=0; i < N; ++i) {
      mask[i] = 0;
    }
  
    // Loop over each round of guessing
    int gameover = 0;
    while (! gameover) {
      // Print word with *s for unguessed letters
      printf("The word is : ");
      for(int j=0; j < N; ++j) {
        if (mask[j]) {
          printf("%c", answer[j]);
        }
        else {
          printf("_");
        }
      }
      printf("\n");
  
      // Get player's next guess
      char guess;
      printf("Letter? ");
      fflush(stdout);
      scanf(" %c", &guess);
  
      // Mark true all mask positions corresponding to guess
      for(int k=0; k < N; ++k) {
        if (answer[k] == guess) {
  	mask[k] = 1;
        }
      }
  
      // Determine whether the player has won!
      gameover = 1;
      for(int m = 0; m < N; ++m) {
        if (!mask[m]) {
          gameover = 0;
          break;
        }
      }
    }
      // Print victory message!
    printf("Victory! The word is \"%s\".\n", answer);	
    char repeat;
    printf("play again? ");
    scanf(" %c", &repeat);
    playagain = (repeat == 'y') ? 1 : 0;
  } while(playagain);
  
  return 0;
}
