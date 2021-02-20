#include "tokenizer.h"

int space_char(char c){
  // true if c is a tab or space, and not zero
  if(c == ' ' || c == '\t' || c == '\n')
    return 1;
  return 0;
}

/* Return true (non-zero) if c is a non-whitespace

   character (not space, tab, or newline).

   Zero terminators are not printable (therefore false) */

int non_space_char(char c){
  if(c != ' ' && c != '\t' && c != '\n'){
    return 1;
  return 0;

}


