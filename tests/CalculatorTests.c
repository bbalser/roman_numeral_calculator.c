#include <check.h>
#include "../src/Calculator.h"

START_TEST(add)
{
  ck_assert_str_eq("II", roman_add("I", "I"));
  ck_assert_str_eq("V", roman_add("IV", "I"));
  ck_assert_str_eq("MVI", roman_add("MIV", "II"));
}
END_TEST

START_TEST(subtract)
{
  ck_assert_str_eq("I", roman_subtract("III", "II"));
  ck_assert_str_eq("IX", roman_subtract("X", "I"));
  ck_assert_str_eq("CCXXIX", roman_subtract("CCCXC", "CLXI"));
}
END_TEST

Suite * calculator_suite(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create("Calculator");

  tc_core = tcase_create("Core");
  tcase_add_test(tc_core, add);
  tcase_add_test(tc_core, subtract);
  suite_add_tcase(s, tc_core);

  return s;
}
