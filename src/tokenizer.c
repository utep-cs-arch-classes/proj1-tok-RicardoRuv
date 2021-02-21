#include "tokenizer.h"
#include <stdio.h>

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
  
  return --str;
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
