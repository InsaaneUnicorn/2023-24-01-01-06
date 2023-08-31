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
#include "People/Wesley/wesley.h"
#include <stdbool.h>



int main() {
	showMainMenu();	
  int playAgain = 1;
	 
    do{
      int remainingGuesses = 6;
      srand (time (NULL));
      printf ("Welcome to HangWaites! (H.A.N.G.W.A.I.T.E.S. - Hilarious Antics of Nervous Guests Waiting And Imagining The Endless Scenarios)\nWhitespaces are underscores btw\n");
      Which_Hangman(1);
				
      // Get word to guess
      FILE *fp;
      fp = fopen("wordbank.txt", "r+");
      
      
      int lines = 0;
      char buf[8];
      char *contents;
      while (fgets(buf, sizeof buf, fp) != NULL) {
        strcpy(contents, buf);
      }
      printf("%s", contents);
    /*
char ** data = malloc(lines * sizeof(char *));
      
        if (data) {
      
          // allocate memory for each data
          for (int i = 0; i < lines; i++) {
            data[i] = malloc(strlen(line) * sizeof(char) + 1);
        }
        
        token = strtok(NULL, " ");
    */

      char *token = strtok(contents, "\n");
        
      while(token) {
        lines++;
        token = strtok(NULL, "\n");
      }
      printf("%d", lines);
      fclose(fp);
  
     
     
		  char wordBank[16][36] = {"operating_system", "hardware", "software", "firmware", "application_programs", "user", "graphical_user_interface", "shell","kernel", "PC", "driver", "open_source","commercial","real_time_operating_system", "bios","giffgaff"}; 
			/* char *wordBank =  malloc(4*sizeof(char)); This is breaking the code*/
      char answer[1];
      strcpy(answer, wordBank[rand() % 28]);

        
      
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
            printf("*");
          }
        }
        printf("\n");


        
        // Get player's next guess

        char guess = Check_Guess(*answer);   // strcmp to compare strings
        //printf("%c",guess);
        // Mark true all mask positions corresponding to guess
        for(int k=0; k < N; ++k) {
          if (answer[k] == guess) {
    	       mask[k] = 1; 
          }
        }

        
        /*if(isInList(guess, ANTI_GOOGLE)){
          gameover = 1;
        }*/
        
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