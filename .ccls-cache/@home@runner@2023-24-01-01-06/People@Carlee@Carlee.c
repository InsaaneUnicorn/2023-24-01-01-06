#include <stdio.h>
void Carlee() { printf("Carlee\n"); }

void Which_Hangman(int stage) {
  switch (stage) {
  case 1:
    printf("  +---+\n  |   |\n      |\n      |\n      |\n      |\n=========\n");
    break;

  case 2:
    printf("  +---+\n  |   |\n  O   |\n      |\n      |\n      |\n=========\n");
    break;

  case 3:
    printf("  +---+\n  |   |\n  O   |\n  |   |\n      |\n      |\n=========\n");
    break;

  case 4:
    printf("  +---+\n  |   |\n  O   |\n /|   |\n      |\n      |\n=========\n");
    break;

  case 5:
    printf(
        "  +---+\n  |   |\n  O   |\n /|\\  |\n      |\n      |\n=========\n");
    break;

  case 6:
    printf(
        "  +---+\n  |   |\n  O   |\n /|\\  |\n /    |\n      |\n=========\n");
    break;

  case 7:
    printf("  +---+\n\n  |   |\n  O   |\n /|\\  |\n / \\  |\n      "
           "|\n=========\n");
    break;

  default:
    printf("Invalid Stage");
  }
}

char Check_Guess(char *answer) {
  char solve;
  char finalGuess;
  printf("Would you like to solve? ");
  scanf("%c", &solve);
  if (solve == 'y') {
    // takes the phrase
    printf("The phrase is... ");
    scanf("%c", &finalGuess);

    // checks it
    if (finalGuess == *answer) {
      return 0;
    } else {
      return -1;
    }
  } else {
    char guess;
    printf("Letter? ");
    guess = getchar();
    return guess;
  }
  return 100;
}
