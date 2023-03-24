#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"

// return true if char is whitespace, false otherwise. T = 1
int space_char(char c)
{
  if (c == ' ' || c == '\t')
    return 1;
  return 0;
}

// return true if not a whitespace
int non_space_char(char c)
{
  if (space_char(c) == 1)
    return 0;
  return 1;
}

// return pointer to first char of word
char *word_start(char *str)
{
  while (*str != '\0') // not null
    {
      if (non_space_char(*str) == 1)
	return str;
      str += 1;
    }
  return 0;
}

// returns a pointer to last char in str
char *word_terminator(char *word)
{
  while (non_space_char(*word))
    word++;
  return word;
}

// returns # of words in str
int count_words(char *str)
{
  int count = 0;
  while (*str != '\0')
    {
      str = word_start(str);
      str = word_terminator(str);
      count++;
    }
  return count;
}

// returns pointer to a copy of str of given length
char *copy_str(char *inStr, short len)
{
  char *newCopy = malloc((len + 1) * sizeof(char));
  int i = 0; // define first or else error
  for (i = 0; i < len; i++)
    newCopy[i] = inStr[i];
  newCopy[i] = '\0';
  return newCopy;
}

char **tokenize(char *str)
{
  int size = count_words(str);
  char **tokens = (char**)malloc((size + 1) * sizeof(char*));
  int i = 0;
  for (i = 0; i < size; i++) { // create copy while you iterate
    char* temp = word_start(str);
    str = word_terminator(temp);
    tokens[i] = copy_str(temp, str - temp);
  }
  tokens[i] = '\0'; // could null work?
  return tokens;
}

void print_tokens(char **tokens)
{
  for (int i = 0; tokens[i] != 0; i++)
    printf("\n%s", tokens[i]);
}

void free_tokens(char **tokens)
{
  for (int i = 0; tokens[i] != 0; i++)
    free(tokens[i]);
  free(tokens);
}
