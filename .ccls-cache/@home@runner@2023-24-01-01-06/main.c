// Hang Waites but in C
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
// WordBank
char wordBank[6][20] = {"mr waites","documentation","python", "it's in the guides", "exit status -1", "segmentation fault"};


int *get_word(int randomIndex){
  char randomString[20];
  for(int i = 0; i <= strlen(wordBank[randomIndex]);i++){
      randomString[i] = wordBank[randomIndex][i];
  }
  printf("%s\n", randomString);
  return randomString;
}

int main(void) { // move this down?
  srand(time(NULL)); 
  int randIndex = (rand() % 5);
  char strIndex = randIndex;  // what is this??
	int playAgain = 1;
  char randomString[20];
  //randomString = get_word(randIndex);

  get_word(randIndex);
  
	while (playAgain) { //move this up?
		printf("Welcome to Hang Waites! :)\n ");
		//printf("%c", *theWord);
    //printf("%s", get_word(randIndex));
		//printf("%s", randomString);
		int lenStr = strlen(randomString); //Get length of string
		for (int i = 0; i < lenStr; i++) {
		  (strcmp(&randomString[i], " ")) ? printf("  ") : printf("_ ");

			//lenStr = lenStr - 1;
		}
    printf("\n");
		playAgain = 0;
	}
  
  return 0;
}




/*
  guys i made pseudo.txt for a reason... USE IT
  No
*/