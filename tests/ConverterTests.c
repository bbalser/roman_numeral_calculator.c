#include <check.h>
#include "../src/Converter.h"

START_TEST (toRoman)
{
  ck_assert_str_eq("I", arabicToRoman(1));
  ck_assert_str_eq("II", arabicToRoman(2));
  ck_assert_str_eq("III", arabicToRoman(3));
  ck_assert_str_eq("IV", arabicToRoman(4));
  ck_assert_str_eq("V", arabicToRoman(5));
  ck_assert_str_eq("VI", arabicToRoman(6));
  ck_assert_str_eq("IX", arabicToRoman(9));
  ck_assert_str_eq("X", arabicToRoman(10));
  ck_assert_str_eq("XI", arabicToRoman(11));
}
END_TEST

Suite * converter_suite(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create("Converter");

  tc_core = tcase_create("Core");
  tcase_add_test(tc_core, toRoman);
  suite_add_tcase(s, tc_core);

  return s;
}
