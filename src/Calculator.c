#include "Converter.h"

char * roman_add(char *a, char *b) {
  return arabicToRoman(romanToArabic(a) + romanToArabic(b));
}

char * roman_subtract(char *a, char *b) {
  return arabicToRoman(romanToArabic(a) - romanToArabic(b));
}
