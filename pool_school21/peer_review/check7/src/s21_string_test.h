#ifndef SRC_S21_STRING_TEST_H_
#define SRC_S21_STRING_TEST_H_

const char str1[13] = {'c', 'h', 'e', 'c', 'k', ' ', 's', 't', 'r', 'i', 'n', 'g', '\0'};
const char str2[13] = {'\0', 'c', 'h', 'e', 'c', 'k', ' ', 's', 't', 'r', 'i', 'n', 'g'};
const char str3[13] = {'c', 'h', 'e', 'c', 'k', '\0', 's', 't', 'r', 'i', 'n', 'g', '\0'};

const int STR1_LENGTH = 12;
const int STR2_LENGTH = 0;
const int STR3_LENGTH = 5;

const int STR_CMP_12 = 99;
const int STR_CMP_13 = 32;
const int STR_CMP_23 = -99;

void s21_strlen_test(void);
void s21_strcmp_test(void);
void s21_strcpy_test(void);

#endif  // SRC_S21_STRING_TEST_H_

