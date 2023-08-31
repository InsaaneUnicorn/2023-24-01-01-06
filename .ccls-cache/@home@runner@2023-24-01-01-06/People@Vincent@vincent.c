#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void editWords(list) {
	
}

void showMainMenu() {
	int menuLoop = 1;
	int innerLoop = 1;
	char startStr[] = "start";
	char editStr[] = "edit";
	int counter = 0;
	
	printf("Welcome to the menu!\n");
	while (menuLoop == 1) {
		printf("Start\nEdit\n");
		while (innerLoop == 1){ 
			char *userInput = malloc(16*sizeof(char));
			printf("root@hangwaites:~$: ");
			scanf("%s", userInput);	
			for (int i = 0; i < strlen(userInput); i++) {
				char r = tolower(userInput[i]);
				userInput[i] = r;
			}
			counter = 0;
			for (int i =0; i < strlen(userInput); i++) {
				if (startStr[i] == userInput[i]) {
					counter = counter + 1;
				}
				else if (editStr[i] == userInput[i]) {
					counter = counter + 1;
				}
			}
			if (counter == 5) {
				printf("\nstart success\n");
			}
			else if (counter == 4) {
				printf("\nedit success\n");
				editWords();
			}
			else {
					printf("Invalid input");
				}
		
			/* if ((strstr("start", userInput)) > 0) {
				printf("\nsuccess\n"); 
			}
			else if ((strstr("edit", userInput)) > 0) {
				printf("\nedit menuing success\n");
			}
			else {
				printf("Successfully failed");
			} */
			free(userInput);
			innerLoop = 0;
			menuLoop = 0;
		}
		
		
	}
	//Things that describe = properties. 
}

