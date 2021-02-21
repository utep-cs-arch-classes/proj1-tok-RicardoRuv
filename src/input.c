#include <stdio.h>
#include "tokenizer.h"
#define LIMIT 100


int main(){

  /* int input;
  input = getchar();

  int r = space_char(input);

  printf("%d\n",r);
  */

  char arrayC[LIMIT];
  int i=0;


  for(char singleChar; (singleChar = getchar()) != '\n' && i < LIMIT - 1; i++){
    arrayC [i] = singleChar;
  }
  char *pointer = word_start(arrayC);
  printf("This is the first char: %c\n", *pointer);

  char *endPointer = word_end(arrayC);
  
  printf("This is the last char: %c\n", *endPointer);

  int numOfWords = count_words(arrayC);
  printf("Total words: %i\n", numOfWords);
}
