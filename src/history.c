#include "history.h"
#include <stdio.h>
#include <stdlib.h>


List *init_history(){
  
 List  *list = malloc(sizeof(List)*1);
 list->root = (Item*)malloc(sizeof(Item));


  return list;
}

/* Add a history item to the end of the list.
   List* list - the linked list
   char* str - the string to store
*/

void add_history(List *list, char *str){
  
  Item *temp = list->root;
  List *ptr;
}


void print_history(List *list){

  Item *temp = list -> root;

  while(temp -> next != NULL){
    printf("%s\n id: token: ",temp->id, temp -> str);
    temp = temp -> next;
  }
}
