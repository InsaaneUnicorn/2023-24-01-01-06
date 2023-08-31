#include <stdio.h>
#include <stdbool.h>

void stew(){
  printf("Stew 'follow me on twitter' Shirley\n");
}

bool isInList(int element, int array[]){
  for (int i = 0; i<=(sizeof(array)/sizeof(array[0])); i++){
    if (element == array[i]){
      return true;
      break;
    }
  }
  return false;
}