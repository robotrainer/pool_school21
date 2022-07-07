#ifndef SRC_S21_STRING_TEST_H_
#define SRC_S21_STRING_TEST_H_

void s21_strlen_test(const char *str, int expected_len);
void s21_strcmp_test(const char *str1, const char *str2, int expected_result);
void s21_strcpy_test(char *destination, const char *source,
                     char *expected_result);
void s21_strcat_test(char *destination, const char *append,
                     char *expected_result);
void s21_strchr_test(char *str, int ch, char *expected_result);

#endif  // SRC_S21_STRING_TEST_H_
