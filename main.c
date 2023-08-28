//we need to make a 'guesses left' variable like the secret number game
// also we could have an array containing the ascii art- the guessesLeft variable could link to that
 
// remember to copy and paste the file path in regular quotes after "#include". 
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include "People/Terran/terran.h"
#include "People/Stew/stew.h"
#include "People/Landon/Landon.h"
#include "People/Jesse/jesse.h"
#include "People/Vincent/vincent.h"
#include "People/Tad/Tad.h"
#include "People/Johnathon/Johnathon.h"
#include "People/Laurae/laurae.h"
#include "People/Kade/Kade.h"
#include "People/Trey/Trey.h"
#include "People/Carlee/Carlee.h"
#include "People/Gabe/Gabe.h"
#include "People/Kaeden/kaeden.h"
#include "People/Aikan/Aikan.h"

/*  help us we beg of you 
your .c file should look like this 
  #include <stdio.h>
  
  void stew(){
    printf("Stew\n");
  }


your .h file should look like this

  void stew();

*/

int main() {

	// everyone's header file
  tadnamesay(); // pBrintVinceruhnt();(); - the tragic result of too many people typing
  Kade();
  stew();
  bruh();
	printVincent();
  sayTrame();
  Aikan();
	LizardFeet();


	
  int playAgain = 0;
	do{
  int remainingGuesses = 6;
  srand(time(NULL));
  printf("Welcome to Hang Waites!\n Whitespaces are underscores btw");
  // Get word to guess
  char wordBank[6][20] = {"mr_waites","documentation","python", "its_in_the_guides", "exit_status_-1", "segmentation_fault"};
  char answer[128];
  strcpy(answer, wordBank[rand() % 6]);

  // Set the mask array - mask[i] is true if the
  // character s[i] has been guessed.  
  int N = strlen(answer); // allocate array for user guess
  int mask[N]; // array of user guess
  for (int i=0; i < N; ++i) {
    mask[i] = 0;
  }

  // Loop over each round of guessing
  int gameover = 0;
  while (! gameover) {
    // Print word with *s for unguessed letters
    printf("\nThe word is : ");
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
    playAgain = (repeat == 'y') ? 1 : 0;
	} while(playAgain);

  return 0;
}