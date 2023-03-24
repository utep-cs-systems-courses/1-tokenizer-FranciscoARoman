#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"
#include "history.h"

int main()
{
  List *hist = init_history();
  char field[250];
  char text[250];
  //List *hist = init_history();
  
  printf("Welcome!, ");
  
  while(1){ // change when quit
    printf("What would you like to do?\nt = Tokenize h = History, ! = Specific History, q = Quit\n");
    fgets(field, sizeof(field), stdin);
    
    if(field[0] == 'q') // quits
      break;
    
    if(field[0] == 't'){ // tokenize   (Segmentation fault (core dumped))
      printf("What are we tokenizing today?\n$ ");
      fgets(text, sizeof(text), stdin);
      char **token = tokenize(text);
      print_tokens(token);
      add_history(hist, text);
      printf("\n%sadded sentence to history\n", text);
      free_tokens(token);
    }

    if(field[0] == 'h') // show History
      print_history(hist);

    if(field[0] == '!'){ // (Segmentation fault (core dumped))
      int id = atoi(field + 1); // atoi turns string to int (VERY HELPFUL!)
      char *history = get_history(hist, id);
      char **token = tokenize(history);
      printf("ID: %d\n", id);
      printf("Retrieved: %s\n", history);
      printf("Tokenized History: \n");
      print_tokens(token);
      free_tokens(token);
    }
    printf("\nAnything else while you're still here? ");
  }
  free_history(hist); // don't forget to free this last
  return 0;
}
 
