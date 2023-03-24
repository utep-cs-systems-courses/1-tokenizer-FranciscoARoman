#include <stdio.h>
#include <stdlib.h>
#include "history.h"
#include "tokenizer.h"

// init linked list
List *init_history()
{
  List *hist = malloc(sizeof(List));
  hist->root = malloc(sizeof(Item));
  return hist;
}

void add_history(List *list, char *str)
{
  int num = 1;
  Item *current = list->root;
  while (current->next) // iterate through
    {
      current = current->next;
      num++;
    }
  current->next = malloc(sizeof(Item)); // fill data
  current->next->id = num;
  current->next->str = str;
}

char *get_history(List *list, int id)
{
  Item *current = list->root;
  while (current){
    if (current->id == id){
      return current->str;
    }
    current = current->next;
  }
}

void print_history(List *list)
{
  Item *current = list->root;
  while (current != NULL)
    {
      printf("%d. %s", current->id, current->str);
      current = current->next;
    }
}

void free_history(List *list) // probably copy mostly out of print_history
{
  Item *current = list->root;
  while (current != NULL)
    {
      free(current);
      current = current->next;
    }
  return;
}
