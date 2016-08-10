#include <stdlib.h>
#include <string.h>

void repeat(char * buffer, char * src, int n) {
  for (int i = 0; i < n; i++) {
    strcat(buffer, src);
  }
}

typedef struct {
  char * roman;
  int arabic;
} RomanValue;

static RomanValue roman_values[] = {
  {"M", 1000},
  {"CM", 900},
  {"D", 500},
  {"CD", 400},
  {"C", 100},
  {"XC", 90},
  {"L", 50},
  {"XL", 40},
  {"X", 10},
  {"IX", 9},
  {"V", 5},
  {"IV", 4},
  {"I", 1},
  {"", 0}
};

char * arabicToRoman(int arabic) {
  char *roman = calloc(16, 1);
  int remaining = arabic;

  for (int i = 0; 0 != roman_values[i].arabic; i++) {
    int times = remaining / roman_values[i].arabic;
    remaining = remaining % roman_values[i].arabic;

    repeat(roman, roman_values[i].roman, times);
  }

  return roman;
}

int romanToArabic(char *roman) {
  int total = 0;

  for (int i = 0; 0 != roman_values[i].arabic; i++) {
    int len = strlen(roman_values[i].roman);
    while (strncmp(roman, roman_values[i].roman, len) == 0) {
      total += roman_values[i].arabic;
      roman = roman + len;
    }
  }

  return total;
}
