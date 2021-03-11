#include "history.h"
#include <stdio.h>
#include <stdlib.h>


List *init_history(){
  
  List  *list =(List*)malloc(sizeof(List)*1);
  list ->root = (Item*) malloc(sizeof(Item)*1);

  return list;
}

/* Add a history item to the end of the list.
   List* list - the linked list
   char* str - the string to store
*/

void add_history(List *list, char *str){
  
  Item *temp = (Item*)malloc(sizeof(Item)*1);
  temp ->str = str;
  
  Item *ptr = list->root;
  int i =1;

  if(ptr == NULL){
    temp ->id = i;
    ptr = temp;
    return;
  }
    while(ptr != NULL && ptr->next != NULL){
      i++;
      ptr = ptr->next;
    }
    temp->id=i;
    ptr->next = temp;
}

void print_history(List *list){
  Item *temp = list -> root;
  while(temp != NULL){
    printf("%d: %s \n ",temp->id,temp->str);
    temp = temp -> next;
  }
}

void free_history(List *list){
  free(list);
}

/* Retrieve the string stored in the node where Item->id == id.

   List* list - the linked list

   int id - the id of the Item to find */

char *get_history(List *list, int id){
  Item *tmp = list->root;

  while(tmp->id != id){
    tmp=tmp->next;
  }
  return tmp->str;
}

