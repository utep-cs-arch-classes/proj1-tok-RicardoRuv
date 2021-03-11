#include "tokenizer.h"
#include <stdio.h>
#include <stdlib.h>

int space_char(char c){
  if(c == ' ' || c == '\t' || c == '\n')
    return 1;
  return 0;
}

int non_space_char(char c){
  if( c != ' ' && c !='\t' && c !='\n')
    return 1;
  return 0;
}

// * to first non-space char in first word in s
char *word_start(char *str){
  while(space_char(*str) && *str != '\0')
    str++;
  if(*str == '\0')
    return 0;
  return str;

}

// * to for space char after end of word
char *word_end(char *str){
  while(non_space_char(*str))
    str++;
  
  return str;
}
/* Counts the number of space seperated words in the string argument. */
int count_words(char *str){
  int counter = 1;

  while(*str != '\0'){
    if(space_char(*str)){
      counter++;
    }
    str++;
  }
  return counter;
}

/* Returns a freshly allocated new zero-terminated string

   containing <len> chars from <inStr> */

char *copy_str(char *inStr, short len){
  char *copy = (char *) malloc(len+1); // dynamically allocate memory +1 more for the null char.

  size_t  counter;

  for(counter =0; counter < len; counter++) {
    copy[counter]= inStr[counter];
  }
  copy[counter] = '\0';
  return copy;
}

// print the tokens pointed to by toks
void print_tokens(char **toks){
    int i = 0;
    while(toks[i] != 0){
      printf("%s\n", toks[i]);
      i++;
    }
}

void free_tokens(char **toks){
  int i =0;

  while (toks[i] != 0)
    free(toks[i]);
  free(toks);
}

/* Returns a freshly allocated zero-terminated vector of freshly allocated

   space-separated tokens from zero-terminated str.

   For example, tokenize("hello world string") would result in:

     tokens[0] = "hello"

     tokens[1] = "world"

     tokens[2] = "string"

     tokens[3] = 0

*/

char **tokenize(char* str){
  int words = count_words(str);
  char *start;
  char *end;
  int len=0;
  
  char **tokens = (char **) malloc(sizeof(char *) * (words + 1));

  char **ptr = tokens;
  int i=0;
  for(; i < words; i++){
    start = word_start(str);
    end = word_end(start);
    len = end-start;
    
    tokens[i] = copy_str(start,len+1);

    str = word_end(end);
  }
  tokens[i]= '\0';
  return tokens;
}
  
