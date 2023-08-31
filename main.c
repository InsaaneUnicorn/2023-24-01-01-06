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


char ANTI_GOOGLE[206][1000] = {
"Google Chrome","Google Account","YouTube","Gmail","Google Play","Google Search","Google AdSense","Pixel Phone","Google Maps","Google Cloud","Google Ads","Google Photos","Google For Families","Google Fi Wireless","Google Nest","Google Pay","Google Store","Google Drive","Google Shopping","Google Accessibility","Blogger","Finance","Google Earth","Google Maps","Gmail","Picasa","Toolbar","Google Search","Google Calendar","Google Docs Editors","Books","Google Groups","YouTube","Trends","Android","Sites","Google Chrome","ChromeOS","ChromiumOS","Fuscia","GLinux","Google Gulp","Cardboard Plastic","Tango","Gerrit","Google Drive","Google Voice","Google Translate","Chromebook","Google TV","Google Play","My Maps","Chrome Web Store","Travel","Google Fiber","Nexus","Ads","Nik Collection","Chromecast","Snapseed","Google Keep","Starbucks WiFi","Google Fi Wireless","Waze","Wear OS by Google","Google Fit","YouTube For Families","Google Store","Chromecast built-in","Google Photos","Android Auto","Android TV","Google For Families","Google Camera","Gcam","Google Wifi","Waymo","Local Guides","YouTube Music","YouTube Studio App Help Center","Google Cardboard","Google Duo","Datally","Google Nest","YouTube TV","Google Clips","Pixel Phone","Opinion Rewards","Daydream","Google Assistant","Files by Google","CS First","Google Chat","Pixelbook","Messages","Reserve with Google","Phone app","Gboard","Contacts","Google One","Google Tasks","Google News","Google Accessibility","Science Journal","Google Shopping","Stadia","Google Pay","Google Food Ordering","Google Kids Space","User Security","Google Workspace Individual","Google Pixel Watch","Google Wallet","AR","Google Pixel Tablet","Google Ads Editor","Google Workspace Admin","Books","Search Console","Programmable Search Engine","Publisher Center","Ad Grants","Google Workspace","Google Ads","Google Cloud","Studio","Google AdSense","Authorized Buyers","Maps Content Partners","Google Merchant Center","Google Ad Manager","Analytics","Currents","Transit Partners","Global Market Finder","Google for Nonprofits","Search Ads 360","Chrome Enterprise and Education","Google AdMob","Google Vault","Google Business Profile","Hotel Center","Display & Video 360","Campaign Manager 360","Google Domains","Google Pay Merchant","Google Cloud Platform Console","Google Arts & Culture Platform","Android Enterprise","Cloud Search","Google Marketing Platform","Cardboard Manufacturer","Card Issuer","Google Meet","Jamboard","Google Pay for Online Business","Local Services","Work Insights","Comparison Shopping Services Center","Elastifile","CEWA","AppSheet","Ads Creative Studio","Orion Wifi","Play Console","GDG","Google Web Designer","Cast Developer","reCAPTCHA","Payments center","Payment Processor","Chromium","Sundar","Susan","Bard","Launcher3","Google Glass","Rick","Mountain View","Googleplex","Gbike","Lollipop","Oreo","Nougat","Marshmallow","Kitkat","Honeycomb","Jellybean","Cupcake","Pie","Ice Cream Sandwich","Gingerbread","Froyo","Eclair","Petit Four","Red Velvet Cake","Quince Tart","Snow Cone","Upside Down Cake","Vanilla Ice Cream","Charlie's Cafe","Shorline","Ampitheater","I/O","stack overflow"
}; // add google colors & their hex values



int main() {
	showMainMenu();	
  int playAgain = 1;
	 
    do{
      int remainingGuesses = 6;
      srand (time (NULL));
      printf (" Welcome to HangWaites! (H.A.N.G.W.A.I.T.E.S. - Hilarious Antics of Nervous Guests Waiting And Imagining The Endless Scenarios)\nWhitespaces are underscores btw\n");
      Which_Hangman(1);
				
      // Get word to guess
      FILE *fp;
      fp = fopen("wordbank.txt", "r+");
      
      
      int lines = 10;
      char buf[8];
      char contents[ = fgets(buf, sizeof buf, fp);
      
        
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
        token = strtok(NULL, " ");
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

        
        if(isInList(guess, ANTI_GOOGLE)){
          gameover = 1;
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