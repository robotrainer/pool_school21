#ifndef SRC_DATA_LIBS_DATA_IO_MACRO_H_
#define SRC_DATA_LIBS_DATA_IO_MACRO_H_

#define input(data, n)            \
  {                               \
    for (int i = 0; i < n; i++) { \
      scanf("%lf", &data[i]);     \
    }                             \
  }

#define output(data, n)            \
  {                                \
    for (int i = 0; i < n; i++) {  \
      printf("%.2lf", data[i]);    \
      if (i != n - 1) printf(" "); \
    }                              \
  }

#endif  // SRC_DATA_LIBS_DATA_IO_MACRO_H_
