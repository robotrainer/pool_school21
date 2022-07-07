#ifndef CALCULATION_H_
#define CALCULATION_H_

typedef struct OPERATIONS {
  double oper;
  struct OPERATIONS *point;
} OPERATIONS;

typedef struct HEAD {
  struct OPERATIONS *point;
} HEAD;

double counter(char *output_str, HEAD *head, double x);
void init(HEAD *head);
void pushing(double sym, HEAD *head);
double pop(HEAD *head);
void add_func_for_graph(char **graph, int height, int width, char *out,
                        HEAD *head);

#endif  // CALCULATION_H_