#include "calculation.h"

#include <math.h>
#include <stdlib.h>
#include <string.h>

#include "draw.h"

double counter(char *output_str, HEAD *head, double x) {
  int n = strlen(output_str);
  double num1, num2;
  for (int i = 0; i < n; ++i) {
    if (output_str[i] == 'x') {
      pushing(x, head);
    } else if (output_str[i] >= '0' && output_str[i] <= '9') {
      pushing((output_str[i] - '0'), head);
    } else if (output_str[i] == '+') {
      num2 = pop(head);
      num1 = pop(head);
      pushing(num1 + num2, head);
    } else if (output_str[i] == '-') {
      num2 = pop(head);
      num1 = pop(head);
      pushing(num1 - num2, head);
    } else if (output_str[i] == '*') {
      num2 = pop(head);
      num1 = pop(head);
      pushing(num1 * num2, head);
    } else if (output_str[i] == '/') {
      num2 = pop(head);
      num1 = pop(head);
      if (num2 != 0)
        pushing(num1 / num2, head);
      else
        pushing(1000, head);
    } else if (output_str[i] == '^') {
      num2 = pop(head);
      num1 = pop(head);
      pushing(pow(num1, num2), head);
    } else if (output_str[i] == 's') {
      num1 = pop(head);
      pushing(sin(num1), head);
    } else if (output_str[i] == 'c') {
      num1 = pop(head);
      pushing(cos(num1), head);
    } else if (output_str[i] == 't') {
      num1 = pop(head);
      pushing(tan(num1), head);
    } else if (output_str[i] == 'g') {
      num1 = pop(head);
      pushing(1 / tan(num1), head);
    } else if (output_str[i] == 'q') {
      num1 = pop(head);
      pushing(sqrt(num1), head);
    } else if (output_str[i] == 'l') {
      num1 = pop(head);
      pushing(log(num1), head);
    }
  }
  return pop(head);
}

void init(HEAD *head) { head->point = NULL; }

void pushing(double sym, HEAD *head) {
  OPERATIONS *tmp;
  tmp = head->point;
  OPERATIONS *new = (OPERATIONS *)malloc(sizeof(OPERATIONS));
  new->oper = sym;
  new->point = tmp;
  head->point = new;
}

double pop(HEAD *head) {
  double x;
  OPERATIONS *tmp = head->point;
  x = head->point->oper;
  head->point = head->point->point;
  free(tmp);
  return x;
}

void add_func_for_graph(char **graph, int height, int width, char *out,
                        HEAD *head) {
  for (int y = 0; y < height; y++) {
    for (int x = 0; x < width; x++) {
      int y = 25;
      if (x != 0) y = round(12 + 12 * counter(out, head, (M_PI * x) / 20));
      if (y > 0 && y < 25) graph[y][x] = STAR;
    }
  }
}
