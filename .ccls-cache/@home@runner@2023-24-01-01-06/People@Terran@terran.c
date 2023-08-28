#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>

int playagain = 0;

int better() {
  int playagain = 0;
  do { 
    char repeat;
    printf("play again? ");
    scanf(" %c", &repeat);
    playagain = (repeat == 'y') ? 1 : 0;
  } while(playagain);
  
  return 0;
}
