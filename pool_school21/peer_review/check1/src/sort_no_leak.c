#include <stdio.h>
#include <stdlib.h>

#define NMAX 10

int input(int *a, int *n, int *f);
int output(int *a, int n);
int bubble_sort(int *a, int n);

int main() {
  int n;
  int flag = 1;
  int *f;
  f = &flag;
  if (scanf("%d", &n) && (n > 0 && n < 11)) {
    int *p = (int *)malloc(n * sizeof(int));
    if (input(p, &n, f) == 1) {
      if (bubble_sort(p, n) && (*f == 1)) {
        output(p, n);
        free(p);
      } else {
        *f = 0;
      }
    } else {
      *f = 0;
    }
  } else {
    printf("n/a");
  }
  return 0;
}

int input(int *buffer, int *n, int *f) {
  char c;
  for (int *p = buffer; p - buffer < *n; p++) {
    if (*f == 1) {
      if ((scanf("%d", p)) != 1) {
        printf("n/a1");
        *f = 0;
      }
    }
  }
  if (*f == 1) {
    if ((scanf("%c", &c) != 1) || (c != '\n')) {
      printf("n/a2");
      *f = 0;
    }
  }

  return *f;
}

int bubble_sort(int *a, int n) {
  int temp;
  for (int i = 0; i < n - 1; i++) {
    for (int j = (n - 1); j > i; j--) {
      if (a[j - 1] > a[j]) {
        temp = a[j - 1];
        a[j - 1] = a[j];
        a[j] = temp;
      }
    }
  }
  return 1;
}

int output(int *a, int n) {
  for (int i = 0; i < n; i++) {
    printf("%d ", a[i]);
  }
  printf("%c", 8);
  return 1;
}
