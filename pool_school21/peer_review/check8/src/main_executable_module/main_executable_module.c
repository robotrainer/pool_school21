#include <stdio.h>
#include <stdlib.h>

#include "../data_libs/data_io.h"
#include "../data_libs/data_stat.h"
#include "../data_module/data_process.h"
#include "../yet_another_decision_module/decision.h"

int main() {
  double *data;
  int n;
  char trigger;
  if (scanf("%d%c", &n, &trigger) == 2 && trigger == '\n' && n != 0) {
    // Don`t forget to allocate memory !
    data = (double *)malloc(n * sizeof(double));

    printf("LOAD DATA...\n");
    input(data, n);

    printf("RAW DATA:\n\t");
    output(data, n);

    printf("\nNORMALIZED DATA:\n\t");
    normalization(data, n);
    output(data, n);

    printf("\nSORTED NORMALIZED DATA:\n\t");
    sort(data, n);
    output(data, n);

    printf("\nFINAL DECISION:\n\t");
    if (make_decision(data, n)) {
      printf("YES\n");
    } else {
      printf("NO\n");
    }
    output(data, n);

    free(data);

  } else {
    printf("n/a");
  } 
}