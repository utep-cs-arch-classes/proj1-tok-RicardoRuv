#include <stdio.h>
#include "tokenizer.h"
#include "history.h"
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
  printf("  Testing tokenizer.c methods:\n");
  
  char *pointer = word_start(arrayC);
  printf("This is the first char: %c\n", *pointer);

  char *endPointer = word_end(arrayC);
  
  printf("This is the last char: %c\n", *endPointer);

  int numOfWords = count_words(arrayC);
  printf("Total words: %i\n", numOfWords);

  char *clone =copy_str(arrayC,5);
  printf("copyStr: %s\n",clone);

  char *str = "hey there tom my name is tom";

  printf("  Testing tokenizer on string given \n");
  char *ptr = arrayC;
  char **tokens = tokenize(ptr);
  print_tokens(tokens);

  printf(" Testing history:\n");

  char r[LIMIT]= "Hello tom my name is tom";
  char u[LIMIT]= "This is my third string";
  char  *s2=r;
  char *s3 =u;
  List *li = init_history();
  add_history(li,ptr);
  add_history(li,s2);
  add_history(li,s3);
  print_history(li);

  printf("  Testing get history: id:2\n");
  char *v = get_history(li,2);
  printf("%s\n ",v);

  
  printf("  Testing free history:\n");
  free_history(li);
  print_history(li);

}
