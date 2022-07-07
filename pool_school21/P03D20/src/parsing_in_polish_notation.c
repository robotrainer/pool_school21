#include <stdio.h>

#include "mystack.h"

void parsing_in_polish_notation(struct st *operations, char *input_str,
                                char *output_str) {
  int point;
  point = 0;
  for (int i = 0; input_str[i] != '\0'; i++) {
    if (input_str[i] == ')') {
      while ((operations->c) != '(') output_str[point++] = delete (&operations);
      delete (&operations);
    }
    if ((input_str[i] >= '0' && input_str[i] <= '9') || input_str[i] == 'x')
      output_str[point++] = input_str[i];
    if (input_str[i] == 's' && input_str[i + 1] == 'i' &&
        input_str[i + 2] == 'n') {
      if (operations == NULL) {
        operations = push(operations, 's');
      } else if (priority(operations->c) < priority('s'))
        operations = push(operations, 's');
      else {
        while ((operations != NULL) &&
               (priority(operations->c) >= priority('s')))
          output_str[point++] = delete (&operations);
        operations = push(operations, 's');
      }
      i += 3;
    }
    if (input_str[i] == 'c' && input_str[i + 1] == 'o' &&
        input_str[i + 2] == 's') {
      if (operations == NULL)
        operations = push(operations, 'c');
      else if (priority(operations->c) < priority('c'))
        operations = push(operations, 'c');
      else {
        while ((operations != NULL) &&
               (priority(operations->c) >= priority('c')))
          output_str[point++] = delete (&operations);
        operations = push(operations, 'c');
      }
      i += 3;
    }
    if (input_str[i] == 't' && input_str[i + 1] == 'g') {
      if (operations == NULL)
        operations = push(operations, 't');
      else if (priority(operations->c) < priority('t'))
        operations = push(operations, 't');
      else {
        while ((operations != NULL) &&
               (priority(operations->c) >= priority('t')))
          output_str[point++] = delete (&operations);
        operations = push(operations, 't');
      }
      i += 2;
    }
    if (input_str[i] == 'c' && input_str[i + 1] == 't' &&
        input_str[i + 2] == 'g') {
      if (operations == NULL)
        operations = push(operations, 'g');
      else if (priority(operations->c) < priority('g'))
        operations = push(operations, 'g');
      else {
        while ((operations != NULL) &&
               (priority(operations->c) >= priority('g')))
          output_str[point++] = delete (&operations);
        operations = push(operations, 'g');
      }
      i += 3;
    }
    if (input_str[i] == 's' && input_str[i + 1] == 'q' &&
        input_str[i + 2] == 'r' && input_str[i + 3] == 't') {
      if (operations == NULL)
        operations = push(operations, 'q');
      else if (priority(operations->c) < priority('q'))
        operations = push(operations, 'q');
      else {
        while ((operations != NULL) &&
               (priority(operations->c) >= priority('q')))
          output_str[point++] = delete (&operations);
        operations = push(operations, 'q');
      }
      i += 4;
    }
    if (input_str[i] == 'l' && input_str[i + 1] == 'n') {
      if (operations == NULL)
        operations = push(operations, 'l');
      else if (priority(operations->c) < priority('l'))
        operations = push(operations, 'l');
      else {
        while ((operations != NULL) &&
               (priority(operations->c) >= priority('l')))
          output_str[point++] = delete (&operations);
        operations = push(operations, 'l');
      }
      i += 2;
    }
    if (input_str[i] == '(') operations = push(operations, '(');
    if (input_str[i] == '+' || input_str[i] == '-' || input_str[i] == '/' ||
        input_str[i] == '*') {
      if (operations == NULL)
        operations = push(operations, input_str[i]);
      else if (priority(operations->c) < priority(input_str[i]))
        operations = push(operations, input_str[i]);
      else {
        while ((operations != NULL) &&
               (priority(operations->c) >= priority(input_str[i])))
          output_str[point++] = delete (&operations);
        operations = push(operations, input_str[i]);
      }
    }
  }

  while (operations != NULL) output_str[point++] = delete (&operations);
  output_str[point] = '\0';
}