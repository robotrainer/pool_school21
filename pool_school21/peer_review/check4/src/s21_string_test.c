#include "s21_string.h"

#include <stdio.h>

#include "s21_string_test.h"

int main() {
#ifdef Q1
  s21_strlen_test();
#endif
#ifdef Q2
  s21_strcmp_test();
#endif
#ifdef Q3
  s21_strcpy_test();
#endif
#ifdef Q4
  s21_strcat_test();
#endif
#ifdef Q5
  s21_strchr_test();
#endif
}

void s21_strlen_test() {
  // Test case 1
  char normal_string[NMAX] = "Hello, my friend";
  int test_case_one = 16;
  int test_one_res = s21_strlen(normal_string);
  printf("%s %d\n", normal_string, test_one_res);
  if (test_one_res == test_case_one)
    printf("SUCCES\n");
  else
    printf("FAIL\n");

  // Test case 2
  char null_string[NMAX] = "     ";
  int test_case_two = 5;
  int test_two_res = s21_strlen(null_string);
  printf("%s %d\n", null_string, test_two_res);
  if (test_case_two == test_two_res)
    printf("SUCCESS\n");
  else
    printf("FAIL\n");

  // Test case 3
  char nothing[100] = "";
  int test_case_three = 0;
  int test_three_res = s21_strlen(nothing);
  printf("%s %d\n", nothing, test_two_res);
  if (test_case_three == test_three_res)
    printf("SUCCES");
  else
    printf("FAIL");
}

void s21_strcmp_test() {
  // Test case 1
  char normal_string_one[NMAX] = "aaa";
  char normal_string_two[NMAX] = "b";
  int test_case_one = -1;
  int test_one_res = s21_strcmp(normal_string_one, normal_string_two);
  printf("%s %s %d\n", normal_string_one, normal_string_two, test_one_res);
  if (test_case_one == test_one_res)
    printf("SUCCESS\n");
  else
    printf("FAIL\n");

  // Test case 2
  char s1[NMAX] = "abvgd";
  char s2[NMAX] = "";
  int test_case_two = 1;
  int test_two_res = s21_strcmp(s1, s2);
  printf("%s %s %d\n", s1, s2, test_two_res);
  if (test_case_two == test_two_res)
    printf("SUCCESS\n");
  else
    printf("FAIL\n");

  // Test case 3
  char s3[NMAX] = "";
  char s4[NMAX] = "";
  int test_case_three = 0;
  int test_three_res = s21_strcmp(s3, s4);
  printf("%s %s %d\n", s3, s4, test_three_res);
  if (test_case_three == test_three_res)
    printf("SUCCESS");
  else
    printf("FAIL");
}

void s21_strcpy_test() {
  // Test case 1
  char source_str[NMAX] = "hello";
  char sec[NMAX] = "";
  s21_strcpy(sec, source_str);
  char *test_one_res = "hello";
  int test_case_one = 0;
  printf("%s %s\n", source_str, sec);
  if (s21_strcmp(sec, test_one_res) == test_case_one)
    printf("SUCCESS\n");
  else
    printf("FAIL\n");

  // Test case 2
  char s1[NMAX] = "abcde\0qwe";
  char s2[NMAX] = "abc";
  s21_strcpy(s2, s1);
  printf("%s %s\n", s1, s2);
  if (s21_strcmp(s2, s1) == 0)
    printf("SUCCESS\n");
  else
    printf("FAIL\n");

  // Test case 3
  char s3[NMAX] = "";
  char s4[NMAX] = "AAAA";
  s21_strcpy(s3, s4);
  printf("%s %s\n", s3, s4);
  if (s21_strcmp(s3, s4) == 0)
    printf("SUCCESS");
  else
    printf("FAIL");
}

void s21_strcat_test() {
  // Test case 1
  char source_str[NMAX] = "first_string";
  char dest_str[NMAX] = "second_string";
  int length_d = s21_strlen(dest_str);
  s21_strcat(dest_str, source_str);
  printf("%s %s\n", source_str, dest_str);
  int length_f = s21_strlen(source_str);
  int length_t = s21_strlen(dest_str);
  if (length_d + length_f == length_t)
    printf("SUCCESS\n");
  else
    printf("FAIL\n");

  // Test case 2
  char s1[NMAX] = "teststring";
  char s2[NMAX] = "";
  int d1 = s21_strlen(s2);
  s21_strcat(s2, s1);
  printf("%s %s\n", s1, s2);
  int d2 = s21_strlen(s1);
  int d3 = s21_strlen(s2);
  if (d1 + d2 == d3)
    printf("SUCCESS\n");
  else
    printf("FAIL\n");

  // Test case 3
  char *s3 = "";
  char s4[NMAX] = "hello_friend";
  int e1 = s21_strlen(s4);
  s21_strcat(s4, s3);
  printf("%s %s\n", s3, s4);
  int e2 = s21_strlen(s3);
  int e3 = s21_strlen(s4);
  if (e1 + e2 == e3)
    printf("SUCCESS");
  else
    printf("FAIL");
}

void s21_strchr_test() {
  // Test case 1

  char str[NMAX] = "YOU SHALL NOT PASS";
  int symb = 'N';
  char *s = s21_strchr(str, symb);
  printf("%s %c %s\n", str, symb, s);
  if (*s == (char)symb)
    printf("SUCCESS\n");
  else
    printf("FAIL\n");

  // Test case 2
  char second[NMAX] = "OMAEWA MO SHINDEIRU";
  int symb_sec = '_';
  char *d = s21_strchr(second, symb_sec);
  printf("%s %c %s\n", second, symb_sec, d);
  if (s21_strcmp(d, "(null)") == 0)
    printf("SUCCESS\n");
  else
    printf("FAIL\n");

  // Test case 3
  char three[NMAX] = "";
  int symb_th = 'A';
  char *g = s21_strchr(three, symb_th);
  printf("%s %c %s\n", three, symb_th, g);
  if (s21_strcmp(g, "(null)") == 0)
    printf("SUCCESS");
  else
    printf("FAIL");
}
