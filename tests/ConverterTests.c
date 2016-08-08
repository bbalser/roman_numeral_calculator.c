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
  ck_assert_str_eq("XX", arabicToRoman(20));
  ck_assert_str_eq("XL", arabicToRoman(40));
  ck_assert_str_eq("L", arabicToRoman(50));
  ck_assert_str_eq("XC", arabicToRoman(90));
  ck_assert_str_eq("C", arabicToRoman(100));
  ck_assert_str_eq("CD", arabicToRoman(400));
  ck_assert_str_eq("D", arabicToRoman(500));
  ck_assert_str_eq("CM", arabicToRoman(900));
  ck_assert_str_eq("M", arabicToRoman(1000));
  ck_assert_str_eq("MMMCMXCIX", arabicToRoman(3999));
  ck_assert_str_eq("MMMDCCCXXXVIII", arabicToRoman(3838));
}
END_TEST

START_TEST(toArabic)
{
  ck_assert_int_eq(1, romanToArabic("I"));
}
END_TEST

Suite * converter_suite(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create("Converter");

  tc_core = tcase_create("Core");
  tcase_add_test(tc_core, toRoman);
  tcase_add_test(tc_core, toArabic);
  suite_add_tcase(s, tc_core);

  return s;
}
