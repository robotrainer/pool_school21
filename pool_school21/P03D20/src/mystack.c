#include "mystack.h"

#include <stdio.h>
#include <stdlib.h>

char delete (struct st **HEAD) {
  struct st *upper;
  char symbol;
  if (*HEAD == NULL) return '\0';
  upper = *HEAD;
  symbol = upper->c;
  *HEAD = upper->next;
  free(upper);
  return symbol;
}

struct st *push(struct st *HEAD, char symbol) {
  struct st *upper;
  if ((upper = malloc(sizeof(struct st))) == NULL) {
    puts("no memory");
    exit(-1);
  }
  upper->c = symbol;
  upper->next = HEAD;
  return upper;
}

int priority(char symbol) {
  switch (symbol) {
    case 'c':
    case 's':
    case 't':
    case 'g':
    case 'q':
    case 'l':
      return 4;
    case '*':
    case '/':
      return 3;

    case '-':
    case '+':
      return 2;

    case '(':
      return 1;
  }
  return 0;
}